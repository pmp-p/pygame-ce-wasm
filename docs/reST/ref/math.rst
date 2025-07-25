.. include:: common.txt

:mod:`pygame.math`
==================

.. module:: pygame.math
   :synopsis: pygame module for vector classes

| :sl:`pygame module for vector classes`

The pygame math module currently provides Vector classes in two and three
dimensions, ``Vector2`` and ``Vector3`` respectively.

They support the following numerical operations: ``vec + vec``, ``vec - vec``,
``vec * number``, ``number * vec``, ``vec / number``, ``vec // number``, ``vec += vec``,
``vec -= vec``, ``vec *= number``, ``vec /= number``, ``vec //= number``, ``round(vec, ndigits=0)``.

All these operations will be performed elementwise.
In addition ``vec * vec`` will perform a scalar-product (a.k.a. dot-product).
If you want to multiply every element from vector v with every element from
vector w you can use the elementwise method: ``v.elementwise() * w``

The coordinates of a vector can be retrieved or set using attributes or
subscripts

::

   v = pygame.Vector3()

   v.x = 5
   v[1] = 2 * v.x
   print(v[1]) # 10

   v.x == v[0]
   v.y == v[1]
   v.z == v[2]

Multiple coordinates can be set and retrieved using slices or swizzling.

::

   v = pygame.Vector2()
   v.xy = 1, 2
   v[:] = 1, 2
   print(v)  # Vector2(1, 2)
   print(v.x)  # 1.0
   print(v.y)  # 2.0
   print(v.xy)  # Vector2(1, 2)
   print(v.yx)  # Vector2(2, 1)
   print(v.xyyx)  # (1.0, 2.0, 2.0, 1.0)

Note above, that swizzling with 2 components will return a Vector2 instance
again, while more than 2 components will result in a tuple. But since vectors
support the iterator protocol, they can be unpacked, or converted to lists or
tuples.

::

   v = Vector2(1, 2)
   print(*v)  # 1.0 2.0
   print(tuple(v))  # (1.0, 2.0)
   print(tuple(v.yx))  # (2.0, 1.0)


A vector can be converted to other data types using the built-in constructors

::

    v = pygame.Vector2(1, 2)

    list(v) == [1.0, 2.0]
    tuple(v) == (1.0, 2.0)
    set(v) == {1.0, 2.0}

Conversion can be combined with swizzling or slicing to create a new order

::

    v = pygame.Vector3(1, 2, 3)

    list(v.xz) == [1.0, 3.0]
    list(v.zyx) == [3.0, 2.0, 1.0]
    list(v.yyy) == [2.0, 2.0, 2.0]
    tuple(v.xyyzzz) == (1.0, 2.0, 2.0, 3.0, 3.0, 3.0)
    tuple(v.zxyxzzyx) == (3.0, 1.0, 2.0, 1.0, 3.0, 3.0, 2.0, 1.0)
    set(v.yxzxzyzxyx) == {1.0, 2.0, 3.0} # sets remove duplicates

    list(v[:]) == [1.0, 2.0, 3.0]
    tuple(v[::-1]) == (3.0, 2.0, 1.0)
    set(v[1:3]) == {2.0, 3.0}

.. versionaddedold:: 1.9.2pre
.. versionchangedold:: 1.9.4 Removed experimental notice.
.. versionchangedold:: 1.9.4 Allow scalar construction like GLSL Vector2(2) == Vector2(2.0, 2.0)
.. versionchangedold:: 1.9.4 :mod:`pygame.math` import not required. More convenient ``pygame.Vector2`` and ``pygame.Vector3``.
.. versionchanged:: 2.1.4 `round` returns a new vector with components rounded to the specified digits.

.. function:: clamp

   | :sl:`returns value clamped to min and max.`
   | :sg:`clamp(value, min, max, /) -> float`

   Clamps a numeric ``value`` so that it's no lower than ``min``, and no higher
   than ``max``.

   .. versionadded:: 2.1.3

   .. ## math.clamp ##

.. function:: lerp

   | :sl:`returns value linearly interpolated between a and b`
   | :sg:`lerp(a, b, value, do_clamp=True, /) -> float`

   Returns a number which is a linear interpolation between ``a``
   and ``b``. The third parameter determines how far between ``a`` and
   ``b`` the result is going to be.
   If ``do_clamp`` is false, the result can exceed the range 0.0 to 1.0.

   The formula is:

   ``a + (b - a) * value``.

   .. versionadded:: 2.4.0

   .. ## math.lerp ##

.. function:: invlerp

   | :sl:`returns value inverse interpolated between a and b`
   | :sg:`invlerp(a, b, value, /) -> float`

   Returns a number which is an inverse interpolation between ``a``
   and ``b``. The third parameter ``value`` is the result of the linear interpolation
   between a and b with a certain coefficient. In other words, this coefficient
   will be the result of this function.
   If ``b`` and ``a`` are equal, it raises a ``ValueError``.

   The formula is:

   ``(v - a)/(b - a)``.

   This is an example explaining what is above :

   .. code-block:: python

      > a = 10
      > b = 20
      > pygame.math.invlerp(10, 20, 11.5)
      > 0.15
      > pygame.math.lerp(10, 20, 0.15)
      > 11.5


   .. versionadded:: 2.5.0

   .. ## math.invlerp ##

.. function:: smoothstep

   | :sl:`returns value smoothly interpolated between a and b.`
   | :sg:`smoothstep(a, b, value, /) -> float`

   Returns a number which is a "smooth" interpolation between ``a``
   and ``b``. This means that the interpolation follows an s-shaped curve, with
   change happening more slowly near the limits (0.0 and 1.0) and faster in the middle.
   The third parameter determines how far between ``a`` and
   ``b`` the result is going to be.

   The formula is:

   ``a * interp + (1 - interp) * b``

   where:

   ``interp = value * value * (3 - 2 * value)``

   .. versionadded:: 2.4.0

   .. ## math.smoothstep ##

.. function:: remap

   | :sl:`remaps value from given input range to given output range`
   | :sg:`remap(i_min, i_max, o_min, o_max, value, /) -> float`

   Returns a number which is the value remapped from ``[i_min, i_max]`` range to
   ``[o_min, o_max]`` range.
   If ``i_min`` and ``i_max`` are equal, it raises a ``ValueError``.

   Example:

   .. code-block:: python

      > value = 50
      > pygame.math.remap(0, 100, 0, 200, value)
      > 100.0


   .. versionadded:: 2.5.0

   .. ## math.remap ##

.. class:: Vector2

   | :sl:`a 2-Dimensional Vector`
   | :sg:`Vector2() -> Vector2(0, 0)`
   | :sg:`Vector2(int) -> Vector2`
   | :sg:`Vector2(float) -> Vector2`
   | :sg:`Vector2(Vector2) -> Vector2`
   | :sg:`Vector2(x, y) -> Vector2`
   | :sg:`Vector2((x, y)) -> Vector2`

   Some general information about the ``Vector2`` class.

   .. versionchanged:: 2.1.3
      Inherited methods of vector subclasses now correctly return an instance of the
      subclass instead of the superclass

   .. method:: dot

      | :sl:`calculates the dot- or scalar-product with the other vector`
      | :sg:`dot(Vector2, /) -> float`

      .. ## Vector2.dot ##

   .. method:: cross

      | :sl:`calculates the cross- or vector-product`
      | :sg:`cross(Vector2, /) -> float`

      calculates the third component of the cross-product.

      .. ## Vector2.cross ##

   .. method:: magnitude

      | :sl:`returns the Euclidean magnitude of the vector.`
      | :sg:`magnitude() -> float`

      calculates the magnitude of the vector which follows from the
      theorem: ``vec.magnitude() == math.sqrt(vec.x**2 + vec.y**2)``

      .. ## Vector2.magnitude ##

   .. method:: magnitude_squared

      | :sl:`returns the squared magnitude of the vector.`
      | :sg:`magnitude_squared() -> float`

      calculates the magnitude of the vector which follows from the
      theorem: ``vec.magnitude_squared() == vec.x**2 + vec.y**2``. This
      is faster than ``vec.magnitude()`` because it avoids the square root.

      .. ## Vector2.magnitude_squared ##

   .. method:: length

      | :sl:`returns the Euclidean length of the vector.`
      | :sg:`length() -> float`

      calculates the Euclidean length of the vector which follows from the
      Pythagorean theorem: ``vec.length() == math.sqrt(vec.x**2 + vec.y**2)``

      .. ## Vector2.length ##

   .. method:: length_squared

      | :sl:`returns the squared Euclidean length of the vector.`
      | :sg:`length_squared() -> float`

      calculates the Euclidean length of the vector which follows from the
      Pythagorean theorem: ``vec.length_squared() == vec.x**2 + vec.y**2``.
      This is faster than ``vec.length()`` because it avoids the square root.

      .. ## Vector2.length_squared ##

   .. method:: normalize

      | :sl:`returns a vector with the same direction but length 1.`
      | :sg:`normalize() -> Vector2`

      Returns a new vector that has ``length`` equal to ``1`` and the same
      direction as self.

      .. ## Vector2.normalize ##

   .. method:: normalize_ip

      | :sl:`normalizes the vector in place so that its length is 1.`
      | :sg:`normalize_ip() -> None`

      Normalizes the vector so that it has ``length`` equal to ``1``.
      The direction of the vector is not changed.

      .. ## Vector2.normalize_ip ##

   .. method:: is_normalized

      | :sl:`tests if the vector is normalized i.e. has length == 1.`
      | :sg:`is_normalized() -> Bool`

      Returns True if the vector has ``length`` equal to ``1``. Otherwise
      it returns ``False``.

      .. ## Vector2.is_normalized ##

   .. method:: scale_to_length

      | :sl:`scales the vector to a given length.`
      | :sg:`scale_to_length(float, /) -> None`

      Scales the vector so that it has the given length. The direction of the
      vector is not changed. You can also scale to length ``0``. If the vector
      is the zero vector (i.e. has length ``0`` thus no direction) a
      ``ValueError`` is raised.

      .. ## Vector2.scale_to_length ##

   .. method:: reflect

      | :sl:`returns a vector reflected of a given normal.`
      | :sg:`reflect(Vector2, /) -> Vector2`

      Returns a new vector that points in the direction as if self would bounce
      of a surface characterized by the given surface normal. The length of the
      new vector is the same as self's.

      .. ## Vector2.reflect ##

   .. method:: reflect_ip

      | :sl:`reflect the vector of a given normal in place.`
      | :sg:`reflect_ip(Vector2, /) -> None`

      Changes the direction of self as if it would have been reflected of a
      surface with the given surface normal.

      .. ## Vector2.reflect_ip ##

   .. method:: distance_to

      | :sl:`calculates the Euclidean distance to a given vector.`
      | :sg:`distance_to(Vector2, /) -> float`

      .. ## Vector2.distance_to ##

   .. method:: distance_squared_to

      | :sl:`calculates the squared Euclidean distance to a given vector.`
      | :sg:`distance_squared_to(Vector2, /) -> float`

      .. ## Vector2.distance_squared_to ##

   .. method:: move_towards

      | :sl:`returns a vector moved toward the target by a given distance.`
      | :sg:`move_towards(Vector2, float, /) -> Vector2`

      Returns a Vector which is moved towards the given Vector by a given
      distance and does not overshoot past its target Vector.
      The first parameter determines the target Vector, while the second
      parameter determines the delta distance. If the distance is in the
      negatives, then it will move away from the target Vector.

      .. versionadded:: 2.1.3

      .. ## Vector2.move_towards ##

   .. method:: move_towards_ip

      | :sl:`moves the vector toward its target at a given distance.`
      | :sg:`move_towards_ip(Vector2, float, /) -> None`

      Moves itself toward the given Vector at a given distance and does not
      overshoot past its target Vector.
      The first parameter determines the target Vector, while the second
      parameter determines the delta distance. If the distance is in the
      negatives, then it will move away from the target Vector.

      .. versionadded:: 2.1.3

      .. ## Vector2.move_towards_ip ##

   .. method:: lerp

      | :sl:`returns a linear interpolation to the given vector.`
      | :sg:`lerp(Vector2, float, /) -> Vector2`

      Returns a Vector which is a linear interpolation between self and the
      given Vector. The second parameter determines how far between self and
      other the result is going to be. It must be a value between ``0`` and ``1``
      where ``0`` means self and ``1`` means other will be returned.

      .. ## Vector2.lerp ##

   .. method:: slerp

      | :sl:`returns a spherical interpolation to the given vector.`
      | :sg:`slerp(Vector2, float, /) -> Vector2`

      Calculates the spherical interpolation from self to the given Vector. The
      second argument - often called t - must be in the range ``[-1, 1]``. It
      parametrizes where - in between the two vectors - the result should be.
      If a negative value is given the interpolation will not take the
      complement of the shortest path.

      .. ## Vector2.slerp ##

   .. method:: smoothstep

      | :sl:`returns a smooth interpolation to the given vector.`
      | :sg:`smoothstep(Vector2, float, /) -> Vector2`

      Returns a Vector which is a smooth interpolation between self and the
      given Vector. This means that the interpolation follows an s-shaped curve, with
      change happening more slowly near the limits (0.0 and 1.0) and faster in the middle.
      The third parameter determines how far between the two vectors the result is going to be.

      The formula is:

      ``a * interp + (1 - interp) * b``

      where:

      ``interp = value * value * (3 - 2 * value)``

      .. versionadded:: 2.4.0

      .. ## Vector2.smoothstep ##

   .. method:: elementwise

      | :sl:`The next operation will be performed elementwise.`
      | :sg:`elementwise() -> VectorElementwiseProxy`

      Applies the following operation to each element of the vector.

      .. ## Vector2.elementwise ##

   .. method:: rotate

      | :sl:`rotates a vector by a given angle in degrees.`
      | :sg:`rotate(angle, /) -> Vector2`

      Returns a vector which has the same length as self but is rotated
      counterclockwise by the given angle in degrees.
      (Note that due to pygame's inverted y coordinate system, the rotation
      will look clockwise if displayed).

      .. ## Vector2.rotate ##

   .. method:: rotate_rad

      | :sl:`rotates a vector by a given angle in radians.`
      | :sg:`rotate_rad(angle, /) -> Vector2`

      Returns a vector which has the same length as self but is rotated
      counterclockwise by the given angle in radians.
      (Note that due to pygame's inverted y coordinate system, the rotation
      will look clockwise if displayed).

      .. versionaddedold:: 2.0.0

      .. ## Vector2.rotate_rad ##

   .. method:: rotate_ip

      | :sl:`rotates the vector by a given angle in degrees in place.`
      | :sg:`rotate_ip(angle, /) -> None`

      Rotates the vector counterclockwise by the given angle in degrees. The
      length of the vector is not changed.
      (Note that due to pygame's inverted y coordinate system, the rotation
      will look clockwise if displayed).

      .. ## Vector2.rotate_ip ##

   .. method:: rotate_ip_rad

      | :sl:`rotates the vector by a given angle in radians in place.`
      | :sg:`rotate_ip_rad(angle, /) -> None`

      DEPRECATED: Use rotate_rad_ip() instead.

      .. versionaddedold:: 2.0.0
      .. deprecatedold:: 2.1.1

      .. ## Vector2.rotate_rad_ip ##

   .. method:: rotate_rad_ip

      | :sl:`rotates the vector by a given angle in radians in place.`
      | :sg:`rotate_rad_ip(angle, /) -> None`

      Rotates the vector counterclockwise by the given angle in radians. The
      length of the vector is not changed.
      (Note that due to pygame's inverted y coordinate system, the rotation
      will look clockwise if displayed).

      .. versionaddedold:: 2.1.1

      .. ## Vector2.rotate_rad_ip ##

   .. method:: angle_to

      | :sl:`calculates the angle to a given vector in degrees.`
      | :sg:`angle_to(Vector2, /) -> float`

      Returns the angle from self to the passed ``Vector2`` that would rotate self
      to be aligned with the passed ``Vector2`` without crossing over the negative
      x-axis.

      .. figure:: code_examples/angle_to.png
         :alt: angle_to image

         Example demonstrating the angle returned

      .. ## Vector2.angle_to ##

   .. method:: as_polar

      | :sl:`returns a tuple with radial distance and azimuthal angle.`
      | :sg:`as_polar() -> (r, phi)`

      Returns a tuple ``(r, phi)`` where r is the radial distance, and phi
      is the azimuthal angle.

      .. ## Vector2.as_polar ##

   .. method:: from_polar

      | :sl:`Sets x and y from a polar coordinates tuple.`
      | :sg:`from_polar((r, phi), /) -> None`

      Sets x and y from a tuple (r, phi) where r is the radial distance, and
      phi is the azimuthal angle.

      .. ## Vector2.from_polar ##

   .. method:: project

      | :sl:`projects a vector onto another.`
      | :sg:`project(Vector2, /) -> Vector2`

      Returns the projected vector. This is useful for collision detection in finding the components in a certain direction (e.g. in direction of the wall).
      For a more detailed explanation see `Wikipedia <https://en.wikipedia.org/wiki/Vector_projection>`_.

      .. versionaddedold:: 2.0.2

      .. ## Vector2.project ##


   .. method:: copy

      | :sl:`Returns a copy of itself.`
      | :sg:`copy() -> Vector2`

      Returns a new Vector2 having the same dimensions.

      .. versionaddedold:: 2.1.1

      .. ## Vector2.copy ##


   .. method:: clamp_magnitude

      | :sl:`Returns a copy of a vector with the magnitude clamped between max_length and min_length.`
      | :sg:`clamp_magnitude(max_length, /) -> Vector2`
      | :sg:`clamp_magnitude(min_length, max_length, /) -> Vector2`

      **Experimental:** feature still in development available for testing and feedback. It may change.
      `Please leave clamp_magnitude feedback with authors <https://github.com/pygame-community/pygame-ce>`_

      Returns a new copy of a vector with the magnitude clamped between
      ``max_length`` and ``min_length``. If only one argument is passed, it is
      taken to be the ``max_length``

      This function raises ``ValueError`` if ``min_length`` is greater than
      ``max_length``, or if either of these values are negative.

      .. versionadded:: 2.1.3

      .. versionchanged:: 2.4.0 It is now possible to use ``clamp_magnitude`` on a zero-vector as long as ``min_length``
         is unspecified or 0.

      .. note::
         Before pygame-ce 2.4.0, attempting to clamp a zero vector would always raise a ``ValueError``

      .. ## Vector2.clamp_magnitude ##


   .. method:: clamp_magnitude_ip

      | :sl:`Clamps the vector's magnitude between max_length and min_length`
      | :sg:`clamp_magnitude_ip(max_length, /) -> None`
      | :sg:`clamp_magnitude_ip(min_length, max_length, /) -> None`

      Clamps the vector's magnitude between ``max_length`` and ``min_length``.
      If only one argument is passed, it is taken to be the ``max_length``

      This function raises ``ValueError`` if ``min_length`` is greater than
      ``max_length``, or if either of these values are negative.

      .. versionadded:: 2.1.3

      .. versionchanged:: 2.4.0 It is now possible to use ``clamp_magnitude`` on a zero-vector as long as ``min_length``
         is unspecified or 0.

      .. note::
         Before pygame-ce 2.4.0, attempting to clamp a zero vector would always raise a ``ValueError``

      .. ## Vector2.clamp_magnitude_ip ##


   .. method:: update

      | :sl:`Sets the coordinates of the vector.`
      | :sg:`update() -> None`
      | :sg:`update(int) -> None`
      | :sg:`update(float) -> None`
      | :sg:`update(Vector2) -> None`
      | :sg:`update(x, y) -> None`
      | :sg:`update((x, y)) -> None`

      Sets coordinates x and y in place.

      .. versionaddedold:: 1.9.5

      .. ## Vector2.update ##


   .. attribute:: epsilon

      | :sl:`Determines the tolerance of vector calculations.`

      Both Vector classes have a value named ``epsilon`` that defaults to ``1e-6``.
      This value acts as a numerical margin in various methods to account for floating point
      arithmetic errors. Specifically, ``epsilon`` is used in the following places:

         * comparing Vectors (``==`` and ``!=``)
         * the ``is_normalized`` method (if the square of the length is within ``epsilon`` of 1, it's normalized)
         * slerping (a Vector with a length of ``<epsilon`` is considered a zero vector, and can't slerp with that)
         * reflection (can't reflect over the zero vector)
         * projection (can't project onto the zero vector)
         * rotation (only used when rotating by a multiple of 90 degrees)

      While it's possible to change ``epsilon`` for a specific instance of a Vector, all the other Vectors
      will retain the default value. Changing ``epsilon`` on a specific instance however could lead to some
      asymmetric behavior where symmetry would be expected, such as

      ::

         u = pygame.Vector2(0, 1)
         v = pygame.Vector2(0, 1.2)
         u.epsilon = 0.5 # don't set it nearly this large

         print(u == v) # >> True
         print(v == u) # >> False

      You'll probably never have to change ``epsilon`` from the default value, but in rare situations you might
      find that either the margin is too large or too small, in which case changing ``epsilon`` slightly
      might help you out.

   .. attribute:: angle

      | :sl:`Gives the angle of the vector in degrees, relative to the X-axis, normalized to the interval [-180, 180].`

      Read-only attribute representing the angle of the vector in degrees relative to the X-axis. This angle is normalized to
      the interval [-180, 180].

      Usage: Accessing `angle` provides the current angle of the vector in degrees within the predefined range of [-180, 180].

      .. versionadded:: 2.5.5

   .. attribute:: angle_rad

      | :sl:`Gives the angle of the vector in radians, relative to the X-axis, normalized to the interval [-π, π].`

      Read-only attribute representing the angle of the vector in radians relative to the X-axis. This value is equivalent
      to the `angle` attribute converted to radians and is normalized to the interval [-π, π].

      Usage: Accessing `angle_rad` provides the current angle of the vector in radians within the predefined range of [-π, π].

      .. versionadded:: 2.5.5

   .. ## pygame.math.Vector2 ##

.. class:: Vector3

   | :sl:`a 3-Dimensional Vector`
   | :sg:`Vector3() -> Vector3(0, 0, 0)`
   | :sg:`Vector3(int) -> Vector3`
   | :sg:`Vector3(float) -> Vector3`
   | :sg:`Vector3(Vector3) -> Vector3`
   | :sg:`Vector3(x, y, z) -> Vector3`
   | :sg:`Vector3((x, y, z)) -> Vector3`

   Some general information about the Vector3 class.

   .. versionchanged:: 2.1.3
      Inherited methods of vector subclasses now correctly return an instance of the
      subclass instead of the superclass

   .. method:: dot

      | :sl:`calculates the dot- or scalar-product with the other vector`
      | :sg:`dot(Vector3, /) -> float`

      .. ## Vector3.dot ##

   .. method:: cross

      | :sl:`calculates the cross- or vector-product`
      | :sg:`cross(Vector3, /) -> Vector3`

      calculates the cross-product.

      .. ## Vector3.cross ##

   .. method:: magnitude

      | :sl:`returns the Euclidean magnitude of the vector.`
      | :sg:`magnitude() -> float`

      calculates the magnitude of the vector which follows from the
      theorem: ``vec.magnitude() == math.sqrt(vec.x**2 + vec.y**2 + vec.z**2)``

      .. ## Vector3.magnitude ##

   .. method:: magnitude_squared

      | :sl:`returns the squared Euclidean magnitude of the vector.`
      | :sg:`magnitude_squared() -> float`

      calculates the magnitude of the vector which follows from the
      theorem:
      ``vec.magnitude_squared() == vec.x**2 + vec.y**2 + vec.z**2``.
      This is faster than ``vec.magnitude()`` because it avoids the
      square root.

      .. ## Vector3.magnitude_squared ##

   .. method:: length

      | :sl:`returns the Euclidean length of the vector.`
      | :sg:`length() -> float`

      calculates the Euclidean length of the vector which follows from the
      Pythagorean theorem:
      ``vec.length() == math.sqrt(vec.x**2 + vec.y**2 + vec.z**2)``

      .. ## Vector3.length ##

   .. method:: length_squared

      | :sl:`returns the squared Euclidean length of the vector.`
      | :sg:`length_squared() -> float`

      calculates the Euclidean length of the vector which follows from the
      Pythagorean theorem:
      ``vec.length_squared() == vec.x**2 + vec.y**2 + vec.z**2``.
      This is faster than ``vec.length()`` because it avoids the square root.

      .. ## Vector3.length_squared ##

   .. method:: normalize

      | :sl:`returns a vector with the same direction but length 1.`
      | :sg:`normalize() -> Vector3`

      Returns a new vector that has ``length`` equal to ``1`` and the same
      direction as self.

      .. ## Vector3.normalize ##

   .. method:: normalize_ip

      | :sl:`normalizes the vector in place so that its length is 1.`
      | :sg:`normalize_ip() -> None`

      Normalizes the vector so that it has ``length`` equal to ``1``. The
      direction of the vector is not changed.

      .. ## Vector3.normalize_ip ##

   .. method:: is_normalized

      | :sl:`tests if the vector is normalized i.e. has length == 1.`
      | :sg:`is_normalized() -> Bool`

      Returns True if the vector has ``length`` equal to ``1``. Otherwise it
      returns ``False``.

      .. ## Vector3.is_normalized ##

   .. method:: scale_to_length

      | :sl:`scales the vector to a given length.`
      | :sg:`scale_to_length(float, /) -> None`

      Scales the vector so that it has the given length. The direction of the
      vector is not changed. You can also scale to length ``0``. If the vector
      is the zero vector (i.e. has length ``0`` thus no direction) a
      ``ValueError`` is raised.

      .. ## Vector3.scale_to_length ##

   .. method:: reflect

      | :sl:`returns a vector reflected of a given normal.`
      | :sg:`reflect(Vector3, /) -> Vector3`

      Returns a new vector that points in the direction as if self would bounce
      of a surface characterized by the given surface normal. The length of the
      new vector is the same as self's.

      .. ## Vector3.reflect ##

   .. method:: reflect_ip

      | :sl:`reflect the vector of a given normal in place.`
      | :sg:`reflect_ip(Vector3, /) -> None`

      Changes the direction of self as if it would have been reflected of a
      surface with the given surface normal.

      .. ## Vector3.reflect_ip ##

   .. method:: distance_to

      | :sl:`calculates the Euclidean distance to a given vector.`
      | :sg:`distance_to(Vector3, /) -> float`

      .. ## Vector3.distance_to ##

   .. method:: distance_squared_to

      | :sl:`calculates the squared Euclidean distance to a given vector.`
      | :sg:`distance_squared_to(Vector3, /) -> float`

      .. ## Vector3.distance_squared_to ##

   .. method:: move_towards

      | :sl:`returns a vector moved toward the target by a given distance.`
      | :sg:`move_towards(Vector3, float, /) -> Vector3`

      Returns a Vector which is moved towards the given Vector by a given
      distance and does not overshoot past its target Vector.
      The first parameter determines the target Vector, while the second
      parameter determines the delta distance. If the distance is in the
      negatives, then it will move away from the target Vector.

      .. versionadded:: 2.1.3

      .. ## Vector3.move_towards ##

   .. method:: move_towards_ip

      | :sl:`moves the vector toward its target at a given distance.`
      | :sg:`move_towards_ip(Vector3, float, /) -> None`

      Moves itself toward the given Vector at a given distance and does not
      overshoot past its target Vector.
      The first parameter determines the target Vector, while the second
      parameter determines the delta distance. If the distance is in the
      negatives, then it will move away from the target Vector.

      .. versionadded:: 2.1.3

      .. ## Vector3.move_towards_ip ##

   .. method:: lerp

      | :sl:`returns a linear interpolation to the given vector.`
      | :sg:`lerp(Vector3, float, /) -> Vector3`

      Returns a Vector which is a linear interpolation between self and the
      given Vector. The second parameter determines how far between self an
      other the result is going to be. It must be a value between ``0`` and
      ``1``, where ``0`` means self and ``1`` means other will be returned.

      .. ## Vector3.lerp ##

   .. method:: slerp

      | :sl:`returns a spherical interpolation to the given vector.`
      | :sg:`slerp(Vector3, float, /) -> Vector3`

      Calculates the spherical interpolation from self to the given Vector. The
      second argument - often called t - must be in the range ``[-1, 1]``. It
      parametrizes where - in between the two vectors - the result should be.
      If a negative value is given the interpolation will not take the
      complement of the shortest path.

      .. ## Vector3.slerp ##

   .. method:: smoothstep

      | :sl:`returns a smooth interpolation to the given vector.`
      | :sg:`smoothstep(Vector3, float, /) -> Vector3`

      Returns a Vector which is a smooth interpolation between self and the
      given Vector. This means that the interpolation follows an s-shaped curve, with
      change happening more slowly near the limits (0.0 and 1.0) and faster in the middle.
      The third parameter determines how far between the two vectors the result is going to be.

      The formula is:

      ``a * interp + (1 - interp) * b``

      where:

      ``interp = value * value * (3 - 2 * value)``

      .. versionadded:: 2.4.0

      .. ## Vector3.smoothstep ##

   .. method:: elementwise

      | :sl:`The next operation will be performed elementwise.`
      | :sg:`elementwise() -> VectorElementwiseProxy`

      Applies the following operation to each element of the vector.

      .. ## Vector3.elementwise ##

   .. method:: rotate

      | :sl:`rotates a vector by a given angle in degrees.`
      | :sg:`rotate(angle, Vector3, /) -> Vector3`

      Returns a vector which has the same length as self but is rotated
      counterclockwise by the given angle in degrees around the given axis.
      (Note that due to pygame's inverted y coordinate system, the rotation
      will look clockwise if displayed).

      .. ## Vector3.rotate ##

   .. method:: rotate_rad

      | :sl:`rotates a vector by a given angle in radians.`
      | :sg:`rotate_rad(angle, Vector3, /) -> Vector3`

      Returns a vector which has the same length as self but is rotated
      counterclockwise by the given angle in radians around the given axis.
      (Note that due to pygame's inverted y coordinate system, the rotation
      will look clockwise if displayed).

      .. versionaddedold:: 2.0.0

      .. ## Vector3.rotate_rad ##

   .. method:: rotate_ip

      | :sl:`rotates the vector by a given angle in degrees in place.`
      | :sg:`rotate_ip(angle, Vector3, /) -> None`

      Rotates the vector counterclockwise around the given axis by the given
      angle in degrees. The length of the vector is not changed.
      (Note that due to pygame's inverted y coordinate system, the rotation
      will look clockwise if displayed).

      .. ## Vector3.rotate_ip ##

   .. method:: rotate_ip_rad

      | :sl:`rotates the vector by a given angle in radians in place.`
      | :sg:`rotate_ip_rad(angle, Vector3, /) -> None`

      DEPRECATED: Use rotate_rad_ip() instead.

      .. versionaddedold:: 2.0.0
      .. deprecatedold:: 2.1.1

      .. ## Vector3.rotate_ip_rad ##

   .. method:: rotate_rad_ip

      | :sl:`rotates the vector by a given angle in radians in place.`
      | :sg:`rotate_rad_ip(angle, Vector3, /) -> None`

      Rotates the vector counterclockwise around the given axis by the given
      angle in radians. The length of the vector is not changed.
      (Note that due to pygame's inverted y coordinate system, the rotation
      will look clockwise if displayed).

      .. versionaddedold:: 2.1.1

      .. ## Vector3.rotate_rad_ip ##

   .. method:: rotate_x

      | :sl:`rotates a vector around the x-axis by the angle in degrees.`
      | :sg:`rotate_x(angle, /) -> Vector3`

      Returns a vector which has the same length as self but is rotated
      counterclockwise around the x-axis by the given angle in degrees.
      (Note that due to pygame's inverted y coordinate system, the rotation
      will look clockwise if displayed).

      .. ## Vector3.rotate_x ##

   .. method:: rotate_x_rad

      | :sl:`rotates a vector around the x-axis by the angle in radians.`
      | :sg:`rotate_x_rad(angle, /) -> Vector3`

      Returns a vector which has the same length as self but is rotated
      counterclockwise around the x-axis by the given angle in radians.
      (Note that due to pygame's inverted y coordinate system, the rotation
      will look clockwise if displayed).

      .. versionaddedold:: 2.0.0

      .. ## Vector3.rotate_x_rad ##

   .. method:: rotate_x_ip

      | :sl:`rotates the vector around the x-axis by the angle in degrees in place.`
      | :sg:`rotate_x_ip(angle, /) -> None`

      Rotates the vector counterclockwise around the x-axis by the given angle
      in degrees. The length of the vector is not changed.
      (Note that due to pygame's inverted y coordinate system, the rotation
      will look clockwise if displayed).

      .. ## Vector3.rotate_x_ip ##

   .. method:: rotate_x_ip_rad

      | :sl:`rotates the vector around the x-axis by the angle in radians in place.`
      | :sg:`rotate_x_ip_rad(angle, /) -> None`

      DEPRECATED: Use rotate_x_rad_ip() instead.

      .. versionaddedold:: 2.0.0
      .. deprecatedold:: 2.1.1

      .. ## Vector3.rotate_x_ip_rad ##

   .. method:: rotate_x_rad_ip

      | :sl:`rotates the vector around the x-axis by the angle in radians in place.`
      | :sg:`rotate_x_rad_ip(angle, /) -> None`

      Rotates the vector counterclockwise around the x-axis by the given angle
      in radians. The length of the vector is not changed.
      (Note that due to pygame's inverted y coordinate system, the rotation
      will look clockwise if displayed).

      .. versionaddedold:: 2.1.1

      .. ## Vector3.rotate_x_rad_ip ##

   .. method:: rotate_y

      | :sl:`rotates a vector around the y-axis by the angle in degrees.`
      | :sg:`rotate_y(angle, /) -> Vector3`

      Returns a vector which has the same length as self but is rotated
      counterclockwise around the y-axis by the given angle in degrees.
      (Note that due to pygame's inverted y coordinate system, the rotation
      will look clockwise if displayed).

      .. ## Vector3.rotate_y ##

   .. method:: rotate_y_rad

      | :sl:`rotates a vector around the y-axis by the angle in radians.`
      | :sg:`rotate_y_rad(angle, /) -> Vector3`

      Returns a vector which has the same length as self but is rotated
      counterclockwise around the y-axis by the given angle in radians.
      (Note that due to pygame's inverted y coordinate system, the rotation
      will look clockwise if displayed).

      .. versionaddedold:: 2.0.0

      .. ## Vector3.rotate_y_rad ##

   .. method:: rotate_y_ip

      | :sl:`rotates the vector around the y-axis by the angle in degrees in place.`
      | :sg:`rotate_y_ip(angle, /) -> None`

      Rotates the vector counterclockwise around the y-axis by the given angle
      in degrees. The length of the vector is not changed.
      (Note that due to pygame's inverted y coordinate system, the rotation
      will look clockwise if displayed).

      .. ## Vector3.rotate_y_ip ##

   .. method:: rotate_y_ip_rad

      | :sl:`rotates the vector around the y-axis by the angle in radians in place.`
      | :sg:`rotate_y_ip_rad(angle, /) -> None`

      DEPRECATED: Use rotate_y_rad_ip() instead.

      .. versionaddedold:: 2.0.0
      .. deprecatedold:: 2.1.1

      .. ## Vector3.rotate_y_ip_rad ##

   .. method:: rotate_y_rad_ip

      | :sl:`rotates the vector around the y-axis by the angle in radians in place.`
      | :sg:`rotate_y_rad_ip(angle, /) -> None`

      Rotates the vector counterclockwise around the y-axis by the given angle
      in radians. The length of the vector is not changed.
      (Note that due to pygame's inverted y coordinate system, the rotation
      will look clockwise if displayed).

      .. versionaddedold:: 2.1.1

      .. ## Vector3.rotate_y_rad_ip ##

   .. method:: rotate_z

      | :sl:`rotates a vector around the z-axis by the angle in degrees.`
      | :sg:`rotate_z(angle, /) -> Vector3`

      Returns a vector which has the same length as self but is rotated
      counterclockwise around the z-axis by the given angle in degrees.
      (Note that due to pygame's inverted y coordinate system, the rotation
      will look clockwise if displayed).

      .. ## Vector3.rotate_z ##

   .. method:: rotate_z_rad

      | :sl:`rotates a vector around the z-axis by the angle in radians.`
      | :sg:`rotate_z_rad(angle, /) -> Vector3`

      Returns a vector which has the same length as self but is rotated
      counterclockwise around the z-axis by the given angle in radians.
      (Note that due to pygame's inverted y coordinate system, the rotation
      will look clockwise if displayed).

      .. versionaddedold:: 2.0.0

      .. ## Vector3.rotate_z_rad ##

   .. method:: rotate_z_ip

      | :sl:`rotates the vector around the z-axis by the angle in degrees in place.`
      | :sg:`rotate_z_ip(angle, /) -> None`

      Rotates the vector counterclockwise around the z-axis by the given angle
      in degrees. The length of the vector is not changed.
      (Note that due to pygame's inverted y coordinate system, the rotation
      will look clockwise if displayed).

      .. ## Vector3.rotate_z_ip ##

   .. method:: rotate_z_ip_rad

      | :sl:`rotates the vector around the z-axis by the angle in radians in place.`
      | :sg:`rotate_z_ip_rad(angle, /) -> None`

      DEPRECATED: Use rotate_z_rad_ip() instead.

      .. deprecatedold:: 2.1.1

      .. ## Vector3.rotate_z_ip_rad ##

   .. method:: rotate_z_rad_ip

      | :sl:`rotates the vector around the z-axis by the angle in radians in place.`
      | :sg:`rotate_z_rad_ip(angle, /) -> None`

      Rotates the vector counterclockwise around the z-axis by the given angle
      in radians. The length of the vector is not changed.
      (Note that due to pygame's inverted y coordinate system, the rotation
      will look clockwise if displayed).

      .. versionaddedold:: 2.1.1

      .. ## Vector3.rotate_z_rad_ip ##

   .. method:: angle_to

      | :sl:`calculates the angle to a given vector in degrees.`
      | :sg:`angle_to(Vector3, /) -> float`

      Returns the angle between self and the given vector.

      .. ## Vector3.angle_to ##

   .. method:: as_spherical

      | :sl:`returns a tuple with radial distance, inclination and azimuthal angle.`
      | :sg:`as_spherical() -> (r, theta, phi)`

      Returns a tuple ``(r, theta, phi)`` where r is the radial distance, theta is
      the inclination angle and phi is the azimuthal angle.

      .. ## Vector3.as_spherical ##

   .. method:: from_spherical

      | :sl:`Sets x, y and z from a spherical coordinates 3-tuple.`
      | :sg:`from_spherical((r, theta, phi), /) -> None`

      Sets x, y and z from a tuple ``(r, theta, phi)`` where r is the radial
      distance, theta is the inclination angle and phi is the azimuthal angle.

      .. ## Vector3.from_spherical ##

   .. method:: project

      | :sl:`projects a vector onto another.`
      | :sg:`project(Vector3, /) -> Vector3`

      Returns the projected vector. This is useful for collision detection in finding the components in a certain direction (e.g. in direction of the wall).
      For a more detailed explanation see `Wikipedia <https://en.wikipedia.org/wiki/Vector_projection>`_.

      .. versionaddedold:: 2.0.2

      .. ## Vector3.project ##

   .. method:: copy

      | :sl:`Returns a copy of itself.`
      | :sg:`copy() -> Vector3`

      Returns a new Vector3 having the same dimensions.

      .. versionaddedold:: 2.1.1

      .. ## Vector3.copy ##


   .. method:: clamp_magnitude

      | :sl:`Returns a copy of a vector with the magnitude clamped between max_length and min_length.`
      | :sg:`clamp_magnitude(max_length, /) -> Vector3`
      | :sg:`clamp_magnitude(min_length, max_length, /) -> Vector3`

      Returns a new copy of a vector with the magnitude clamped between
      ``max_length`` and ``min_length``. If only one argument is passed, it is
      taken to be the ``max_length``

      This function raises ``ValueError`` if ``min_length`` is greater than
      ``max_length``, or if either of these values are negative.

      .. versionadded:: 2.1.3

      .. versionchanged:: 2.4.0 It is now possible to use ``clamp_magnitude`` on a zero-vector as long as ``min_length``
         is unspecified or 0.

      .. note::
         Before pygame-ce 2.4.0, attempting to clamp a zero vector would always raise a ``ValueError``

      .. ## Vector3.clamp_magnitude ##


   .. method:: clamp_magnitude_ip

      | :sl:`Clamps the vector's magnitude between max_length and min_length`
      | :sg:`clamp_magnitude_ip(max_length, /) -> None`
      | :sg:`clamp_magnitude_ip(min_length, max_length, /) -> None`

      Clamps the vector's magnitude between ``max_length`` and ``min_length``.
      If only one argument is passed, it is taken to be the ``max_length``

      This function raises ``ValueError`` if ``min_length`` is greater than
      ``max_length``, or if either of these values are negative.

      .. versionadded:: 2.1.3

      .. versionchanged:: 2.4.0 It is now possible to use ``clamp_magnitude`` on a zero-vector as long as ``min_length``
         is unspecified or 0.

      .. note::
         Before pygame-ce 2.4.0, attempting to clamp a zero vector would always raise a ``ValueError``

      .. ## Vector3.clamp_magnitude_ip ##

   .. method:: update

      | :sl:`Sets the coordinates of the vector.`
      | :sg:`update() -> None`
      | :sg:`update(int) -> None`
      | :sg:`update(float) -> None`
      | :sg:`update(Vector3) -> None`
      | :sg:`update(x, y, z) -> None`
      | :sg:`update((x, y, z)) -> None`

      Sets coordinates x, y, and z in place.

      .. versionaddedold:: 1.9.5

      .. ## Vector3.update ##

   .. attribute:: epsilon

      | :sl:`Determines the tolerance of vector calculations.`

      With lengths within this number, vectors are considered equal. For more information see :attr:`pygame.math.Vector2.epsilon`

   .. ##  ##

   .. ## pygame.math.Vector3 ##

.. ## pygame.math ##
