#include "geometry_common.h"

int
_pg_circle_set_radius(PyObject *value, pgCircleBase *circle)
{
    double radius = 0.0;
    if (!pg_DoubleFromObj(value, &radius) || radius < 0.0) {
        return 0;
    }
    circle->r = radius;
    return 1;
}

int
pgCircle_FromObject(PyObject *obj, pgCircleBase *out)
{
    Py_ssize_t length;

    if (pgCircle_Check(obj)) {
        *out = pgCircle_AsCircle(obj);
        return 1;
    }

    /* Paths for sequences */
    if (pgSequenceFast_Check(obj)) {
        PyObject **f_arr = PySequence_Fast_ITEMS(obj);
        length = PySequence_Fast_GET_SIZE(obj);

        switch (length) {
            case 1:
                return pgCircle_FromObject(f_arr[0], out);
            case 2:
                return pg_TwoDoublesFromObj(f_arr[0], &out->x, &out->y) &&
                       _pg_circle_set_radius(f_arr[1], out);
            case 3:
                return pg_DoubleFromObj(f_arr[0], &out->x) &&
                       pg_DoubleFromObj(f_arr[1], &out->y) &&
                       _pg_circle_set_radius(f_arr[2], out);
            default:
                return 0;
        }
    }
    else if (PySequence_Check(obj)) {
        PyObject *tmp = NULL;
        length = PySequence_Length(obj);

        if (length == 3) {
            tmp = PySequence_ITEM(obj, 0);
            if (!pg_DoubleFromObj(tmp, &out->x)) {
                Py_DECREF(tmp);
                return 0;
            }
            Py_DECREF(tmp);

            tmp = PySequence_ITEM(obj, 1);
            if (!pg_DoubleFromObj(tmp, &out->y)) {
                Py_DECREF(tmp);
                return 0;
            }
            Py_DECREF(tmp);

            tmp = PySequence_ITEM(obj, 2);
            if (!_pg_circle_set_radius(tmp, out)) {
                Py_DECREF(tmp);
                return 0;
            }
            Py_DECREF(tmp);

            return 1;
        }
        else if (length == 2) {
            tmp = PySequence_ITEM(obj, 0);
            if (!pg_TwoDoublesFromObj(tmp, &out->x, &out->y)) {
                Py_DECREF(tmp);
                return 0;
            }
            Py_DECREF(tmp);

            tmp = PySequence_ITEM(obj, 1);
            if (!_pg_circle_set_radius(tmp, out)) {
                Py_DECREF(tmp);
                return 0;
            }
            Py_DECREF(tmp);

            return 1;
        }
        else if (length == 1) {
            tmp = PySequence_ITEM(obj, 0);
            if (PyUnicode_Check(obj) || !pgCircle_FromObject(tmp, out)) {
                Py_DECREF(tmp);
                return 0;
            }
            Py_DECREF(tmp);
            return 1;
        }
        else {
            return 0;
        }
    }

    /* Path for objects that have a circle attribute */
    PyObject *circleattr;
    if (!(circleattr = PyObject_GetAttrString(obj, "circle"))) {
        PyErr_Clear();
        return 0;
    }

    if (PyCallable_Check(circleattr)) /*call if it's a method*/
    {
        PyObject *circleresult = PyObject_CallNoArgs(circleattr);
        Py_DECREF(circleattr);
        if (!circleresult) {
            PyErr_Clear();
            return 0;
        }
        circleattr = circleresult;
    }

    if (!pgCircle_FromObject(circleattr, out)) {
        PyErr_Clear();
        Py_DECREF(circleattr);
        return 0;
    }

    Py_DECREF(circleattr);

    return 1;
}

int
pgCircle_FromObjectFastcall(PyObject *const *args, Py_ssize_t nargs,
                            pgCircleBase *out)
{
    switch (nargs) {
        case 1:
            return pgCircle_FromObject(args[0], out);
        case 2:
            return pg_TwoDoublesFromObj(args[0], &out->x, &out->y) &&
                   _pg_circle_set_radius(args[1], out);
        case 3:
            return pg_DoubleFromObj(args[0], &out->x) &&
                   pg_DoubleFromObj(args[1], &out->y) &&
                   _pg_circle_set_radius(args[2], out);
        default:
            return 0;
    }
}

static inline int
double_compare(double a, double b)
{
    /* Uses both a fixed epsilon and an adaptive epsilon */
    const double e = 1e-6;
    return fabs(a - b) < e || fabs(a - b) <= e * MAX(fabs(a), fabs(b));
}
