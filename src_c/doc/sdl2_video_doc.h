/* Auto generated file: with makeref.py .  Docs go in docs/reST/ref/ . */
#define DOC_SDL2VIDEO "Experimental pygame module for porting new SDL video systems"
#define DOC_SDL2_VIDEO_MESSAGEBOX "messagebox(title, message, window=None, info=False, warn=False, buttons=('OK',), return_button=0, escape_button=0)\nCreate a native GUI message box"
#define DOC_SDL2_VIDEO_RENDERERDRIVERINFO "pygame object encapsulating Renderer driver information"
#define DOC_SDL2_VIDEO_GETDRIVERS "get_drivers() -> Iterator[RendererDriverInfo]\nYield info about the rendering drivers available for Renderer objects"
#define DOC_SDL2_VIDEO_GETGRABBEDWINDOW "get_grabbed_window() -> Window or None\nGet the window with input grab enabled"
#define DOC_SDL2_VIDEO_WINDOW "Window(title='pygame window', size=(640, 480), position=None, fullscreen=False, fullscreen_desktop=False, **kwargs) -> Window\npygame object that represents a window"
#define DOC_SDL2_VIDEO_WINDOW_GRABMOUSE "grab_mouse -> bool\nGet or set the window's mouse grab mode"
#define DOC_SDL2_VIDEO_WINDOW_GRABKEYBOARD "grab_keyboard -> bool\nGet or set the window's keyboard grab mode"
#define DOC_SDL2_VIDEO_WINDOW_MOUSEGRABBED "mouse_grabbed -> bool\nGet if the mouse cursor is confined to the window (**read-only**)"
#define DOC_SDL2_VIDEO_WINDOW_KEYBOARDGRABBED "keyboard_grabbed -> bool\nGet if the keyboard shortcuts are captured by the window (**read-only**)"
#define DOC_SDL2_VIDEO_WINDOW_TITLE "title -> str\nGet or set the window title"
#define DOC_SDL2_VIDEO_WINDOW_RESIZABLE "resizable -> bool\nGet or set whether the window is resizable"
#define DOC_SDL2_VIDEO_WINDOW_BORDERLESS "borderless -> bool\nGet or set whether the window is borderless"
#define DOC_SDL2_VIDEO_WINDOW_ALWAYSONTOP "always_on_top -> bool\nGet or set whether the window is always on top"
#define DOC_SDL2_VIDEO_WINDOW_ID "id -> int\nGet the unique window ID (**read-only**)"
#define DOC_SDL2_VIDEO_WINDOW_MOUSERECT "mouse_rect -> Rect|None\nGet or set the mouse confinement rectangle of the window"
#define DOC_SDL2_VIDEO_WINDOW_SIZE "size -> (int, int)\nGet or set the window size in pixels"
#define DOC_SDL2_VIDEO_WINDOW_MINIMUMSIZE "minimum_size -> (int, int)\nGet or set the minimum size of the window's client area"
#define DOC_SDL2_VIDEO_WINDOW_MAXIMUMSIZE "maximum_size -> (int, int)\nGet or set the maximum size of the window's client area"
#define DOC_SDL2_VIDEO_WINDOW_POSITION "position -> (int, int) or WINDOWPOS_CENTERED or WINDOWPOS_UNDEFINED\nGet or set the window position in screen coordinates"
#define DOC_SDL2_VIDEO_WINDOW_OPACITY "opacity -> float\nGet or set the window opacity, between 0.0 (fully transparent) and 1.0 (fully opaque)"
#define DOC_SDL2_VIDEO_WINDOW_DISPLAYINDEX "get_display_index -> int\nGet the index of the display that owns the window (**read-only**)"
#define DOC_SDL2_VIDEO_WINDOW_FROMDISPLAYMODULE "from_display_module() -> Window\nCreate a Window object using window data from display module"
#define DOC_SDL2_VIDEO_WINDOW_GETSURFACE "get_surface() -> Surface\nGet the window surface"
#define DOC_SDL2_VIDEO_WINDOW_UPDATEFROMSURFACE "update_from_surface() -> None\nUpdate the window surface to the window."
#define DOC_SDL2_VIDEO_WINDOW_SETWINDOWED "set_windowed() -> None\nEnable windowed mode (exit fullscreen)"
#define DOC_SDL2_VIDEO_WINDOW_SETFULLSCREEN "set_fullscreen(desktop=False) -> None\nEnter fullscreen"
#define DOC_SDL2_VIDEO_WINDOW_DESTROY "destroy() -> None\nDestroy the window"
#define DOC_SDL2_VIDEO_WINDOW_HIDE "hide() -> None\nHide the window"
#define DOC_SDL2_VIDEO_WINDOW_SHOW "show() -> None\nShow the window"
#define DOC_SDL2_VIDEO_WINDOW_FOCUS "focus(input_only=False) -> None\nSet the window to be focused"
#define DOC_SDL2_VIDEO_WINDOW_RESTORE "restore() -> None\nRestore the size and position of a minimized or maximized window"
#define DOC_SDL2_VIDEO_WINDOW_MAXIMIZE "maximize() -> None\nMaximize the window"
#define DOC_SDL2_VIDEO_WINDOW_MINIMIZE "maximize() -> None\nMinimize the window"
#define DOC_SDL2_VIDEO_WINDOW_SETICON "set_icon(surface) -> None\nSet the window icon"
#define DOC_SDL2_VIDEO_WINDOW_SETMODALFOR "set_modal_for(parent) -> None\nSet the window as a modal for a parent window"
#define DOC_SDL2_VIDEO_TEXTURE "Texture(renderer, size, depth=0, static=False, streaming=False, target=False, scale_quality=None) -> Texture\npygame object that represents a texture"
#define DOC_SDL2_VIDEO_TEXTURE_RENDERER "renderer -> Renderer\nGet the renderer associated with the texture (**read-only**)"
#define DOC_SDL2_VIDEO_TEXTURE_WIDTH "width -> int\nGet the width of the texture (**read-only**)"
#define DOC_SDL2_VIDEO_TEXTURE_HEIGHT "height -> int\nGet the height of the texture (**read-only**)"
#define DOC_SDL2_VIDEO_TEXTURE_ALPHA "alpha -> int\nGet or set the additional alpha value multiplied into draw operations"
#define DOC_SDL2_VIDEO_TEXTURE_BLENDMODE "blend_mode -> int\nGet or set the blend mode for texture drawing operations"
#define DOC_SDL2_VIDEO_TEXTURE_COLOR "color -> Color\nGet or set the additional color value multiplied into texture drawing operations"
#define DOC_SDL2_VIDEO_TEXTURE_FROMSURFACE "from_surface(renderer, surface) -> Texture\nCreate a texture from an existing surface"
#define DOC_SDL2_VIDEO_TEXTURE_GETRECT "get_rect(**kwargs) -> Rect\nGet the rectangular area of the texture"
#define DOC_SDL2_VIDEO_TEXTURE_DRAW "draw(srcrect=None, dstrect=None, angle=0, origin=None, flip_x=False, flip_y=False) -> None\nCopy a portion of the texture to the rendering target"
#define DOC_SDL2_VIDEO_TEXTURE_DRAWTRIANGLE "draw_triangle(p1_xy, p2_xy, p3_xy, p1_uv=(0.0, 0.0), p2_uv=(1.0, 1.0), p3_uv=(0.0, 1.0), p1_mod=(255, 255, 255, 255), p2_mod=(255, 255, 255, 255), p3_mod=(255, 255, 255, 255)) -> None\nCopy a triangle portion of the texture to the rendering target using the given coordinates"
#define DOC_SDL2_VIDEO_TEXTURE_DRAWQUAD "draw_quad(p1_xy, p2_xy, p3_xy, p4_xy, p1_uv=(0.0, 0.0), p2_uv=(1.0, 0.0), p3_uv=(1.0, 1.0), p4_uv=(0.0, 1.0), p1_mod=(255, 255, 255, 255), p2_mod=(255, 255, 255, 255), p3_mod=(255, 255, 255, 255), p4_mod=(255, 255, 255, 255)) -> None\nCopy a quad portion of the texture to the rendering target using the given coordinates"
#define DOC_SDL2_VIDEO_TEXTURE_UPDATE "update(surface, area=None) -> None\nUpdate the texture with Surface (slow operation, use sparingly)"
#define DOC_SDL2_VIDEO_IMAGE "Image(texture_or_image, srcrect=None) -> Image\npygame object that represents a portion of a texture"
#define DOC_SDL2_VIDEO_IMAGE_ANGLE "angle -> float\nGet and set the angle the Image draws itself with"
#define DOC_SDL2_VIDEO_IMAGE_FLIPX "flip_x -> bool\nGet or set whether the Image is flipped on the x axis"
#define DOC_SDL2_VIDEO_IMAGE_FLIPY "flip_y -> bool\nGet or set whether the Image is flipped on the y axis"
#define DOC_SDL2_VIDEO_IMAGE_COLOR "color -> Color\nGet or set the Image color modifier"
#define DOC_SDL2_VIDEO_IMAGE_ALPHA "alpha -> float\nGet or set the Image alpha modifier (0-255)"
#define DOC_SDL2_VIDEO_IMAGE_BLENDMODE "blend_mode -> int\nGet or set the blend mode for the Image"
#define DOC_SDL2_VIDEO_IMAGE_TEXTURE "texture -> Texture\nGet or set the Texture the Image is based on"
#define DOC_SDL2_VIDEO_IMAGE_SRCRECT "srcrect -> Rect\nGet or set the Rect the Image is based on"
#define DOC_SDL2_VIDEO_IMAGE_ORIGIN "origin -> (float, float) or None\nGet or set the Image's origin of rotation"
#define DOC_SDL2_VIDEO_IMAGE_GETRECT "get_rect() -> Rect\nGet the rectangular area of the Image"
#define DOC_SDL2_VIDEO_IMAGE_DRAW "draw(srcrect=None, dstrect=None) -> None\nCopy a portion of the Image to the rendering target"
#define DOC_SDL2_VIDEO_RENDERER "Renderer(window, index=-1, accelerated=-1, vsync=False, target_texture=False) -> Renderer\npygame object wrapping a 2D rendering context for a window"
#define DOC_SDL2_VIDEO_RENDERER_DRAWBLENDMODE "draw_blend_mode -> int\nGet or set the blend mode used for primitive drawing operations"
#define DOC_SDL2_VIDEO_RENDERER_DRAWCOLOR "draw_color -> Color\nGet or set the color used for primitive drawing operations"
#define DOC_SDL2_VIDEO_RENDERER_LOGICALSIZE "logical_size -> (int width, int height)\nGet or set the logical Renderer size (a device independent resolution for rendering)"
#define DOC_SDL2_VIDEO_RENDERER_SCALE "scale -> (float, float)\nGet the drawing scale for the current rendering target"
#define DOC_SDL2_VIDEO_RENDERER_TARGET "target -> Texture or None\nGet or set the current rendering target"
#define DOC_SDL2_VIDEO_RENDERER_FROMWINDOW "from_window(window) -> Renderer\nCreate a Renderer from an existing window"
#define DOC_SDL2_VIDEO_RENDERER_CLEAR "clear() -> None\nClear the current rendering target with the drawing color"
#define DOC_SDL2_VIDEO_RENDERER_PRESENT "present() -> None\nUpdate the screen with any rendering performed since the previous call"
#define DOC_SDL2_VIDEO_RENDERER_GETVIEWPORT "get_viewport() -> Rect\nGet the drawing area on the rendering target"
#define DOC_SDL2_VIDEO_RENDERER_SETVIEWPORT "set_viewport(area) -> None\nSet the drawing area on the rendering target"
#define DOC_SDL2_VIDEO_RENDERER_BLIT "blit(source, dest, area=None, special_flags=0)-> Rect\nDraw textures using a Surface-like API"
#define DOC_SDL2_VIDEO_RENDERER_DRAWLINE "draw_line(p1, p2) -> None\nDraw a line"
#define DOC_SDL2_VIDEO_RENDERER_DRAWPOINT "draw_point(point) -> None\nDraw a point"
#define DOC_SDL2_VIDEO_RENDERER_DRAWRECT "draw_rect(rect)-> None\nDraw a rectangle outline"
#define DOC_SDL2_VIDEO_RENDERER_FILLRECT "fill_rect(rect)-> None\nDraw a filled rectangle"
#define DOC_SDL2_VIDEO_RENDERER_DRAWTRIANGLE "draw_triangle(p1, p2, p3) -> None\nDraw a triangle outline"
#define DOC_SDL2_VIDEO_RENDERER_FILLTRIANGLE "fill_triangle(p1, p2, p3) -> None\nDraw a filled triangle"
#define DOC_SDL2_VIDEO_RENDERER_DRAWQUAD "draw_quad(p1, p2, p3, p4) -> None\nDraw a quad outline"
#define DOC_SDL2_VIDEO_RENDERER_FILLQUAD "fill_quad(p1, p2, p3, p4) -> None\nDraw a filled quad"
#define DOC_SDL2_VIDEO_RENDERER_TOSURFACE "to_surface(surface=None, area=None)-> Surface\nRead pixels from current rendering target and create a Surface (slow operation, use sparingly)"
#define DOC_SDL2_VIDEO_RENDERER_COMPOSECUSTOMBLENDMODE "compose_custom_blend_mode(color_mode, alpha_mode) -> int\nCompose a custom blend mode"
