# MLX42 PUBLIC FUNCTIONS
---

## mlx_font.c

* __const mlx_texture_t*__ _mlx_get_font(void)_: Devuelve la fuente como textura (variable ```font_atlas```)

* __int32_t__ _mlx_get_texoffset(char c)_: Calcula el desplazamiento del caracter ```c``` 

* __mlx_image_t*__ _mlx_put_string(mlx_t* mlx, const char* str, int32_t x, int32_t y)_: Crea una imagen a partir del string ```str``` que será colocada en las posiciones ```(x, y)``` de la ventana de ```mlx```

## mlx_png.c

* __mlx_texture_t*__ _mlx_load_png(const char* path)_: Carga la imagen _.png_ de la ruta ```path``` como textura

## mlx_texture.c

* __mlx_image_t*__ _mlx_texture_to_image(mlx_t* mlx, mlx_texture_t* texture)_: Convierte la textura ```texture``` a imagen.

* __void__ _mlx_delete_texture(mlx_texture_t* texture)_: Libera la memoria de la textura ```texture```

## mlx_xpm42.c

* __xpm_t*__ _mlx_load_xpm42(const char* path)_: Carga el archivo _.xpm42_ de la ruta ```path``` como textura ````xpm42```

* __void__ _mlx_delete_xpm42(xpm_t* xpm)_: Libera la memoria de la textura ```xpm```

## mlx_compare.c

_Todas las funciones son privadas._

## mlx_error.c

* __const char*__ _mlx_strerror(mlx_errno_t val)_: Imprime el mensaje de error de la posición ```val```

## mlx_list.c

_Todas las funciones son privadas._

## mlx_utils.c

* __double__ _mlx_get_time(void)_: Llama a la función ```glfwGetTime()``` de ```glfw```

* __void__ _mlx_focus(mlx_t* mlx)_: Llama a la función ```glfwFocusWindow()```, siempre que ```mlx``` esté reservada en memoria.

## mlx_cursor.c

* __mlx_win_cursor_t*__ _mlx_create_std_cursor(cursor_t type)_: Crea un cursor estándar de ```glfwCreateStandardCursor()```. ```cursor_t``` establece los tipos de cursores estándar, y se pasará como parámetro a la función de glfw mencionada anteriormente

* __mlx_win_cursor_t*__ _mlx_create_cursor(mlx_texture_t* texture)_: Crea un cursor dada una textura ```texture```

* __void__ _mlx_destroy_cursor(mlx_win_cursor_t* cursor)_: Libera la memoria reservada para ```cursor```

* __void__ _mlx_set_cursor(mlx_t* mlx, mlx_win_cursor_t* cursor)_: Establece el cursor a utilizar en la ventana

* __void__ _mlx_set_cursor_mode(mlx_t* mlx, mouse_mode_t mode)_: Establece el modo del cursor usado en la ventana. (mouse_mode_t??)

## mlx_exit.c

* __void__ _mlx_close_window(mlx_t* mlx)_: Cierra y libera la ventana

* __void__ _mlx_terminate(mlx_t* mlx)_: Libera la estructura de tipo ```mlx_t*```

## mlx_images.c

* __void__ _mlx_set_instance_depth(mlx_instance_t* instance, int32_t zdepth)_: Maneja la transparencia ```zdepth``` de imagenes, guardadas en un array de instancias ```instance``` (imagenes printeadas en la ventana)

* __int32_t__ _mlx_image_to_window(mlx_t* mlx, mlx_image_t* img, int32_t x, int32_t y)_: Coloca en la posicion ```(x,y)``` de la ventana la imagen ```img```

* __mlx_image_t*__ _mlx_new_image(mlx_t* mlx, uint32_t width, uint32_t height)_: Crea una nueva imagen de dimensione ```width``` x ```height```

* __void__ _mlx_delete_image(mlx_t* mlx, mlx_image_t* image)_: Elimina y libera la imagen ```image```

* __bool__ _mlx_resize_image(mlx_image_t* img, uint32_t nwidth, uint32_t nheight)_: Cambia las dimensiones de la imagen ```img```, dadas las nuevas dimensiones [```nwidth```,````nheight```]

## mlx_init.c

* __mlx_t*__ _mlx_init(int32_t width, int32_t height, const char* title, bool resize)_: Crea la estructura ```mlx_t*``` de proporciones ```width``` y ```height``` junto con la ventana, de titulo ```title``` y determinando si la ventana se podrá redimensionar o no (```resize```) 

* __void__ _mlx_set_setting(mlx_settings_t setting, int32_t value)_: Coloca en la posición ```setting``` del array ```mlx_settings``` el valor ```value```

## mlx_keys.c

* __void__ _mlx_key_hook(mlx_t* mlx, mlx_keyfunc func, void* param)_: Crea un disparador de la función ```func```, con un parámetro ```param``` opcional, que se llamará cuando se presione una tecla, Explicación en ```Hooks.md``` del repositorio de MLX42.

* __bool__ _mlx_is_key_down(mlx_t* mlx, keys_t key)_: Comprueba si se ha presionado la tecla ```key```

## mlx_loop.c

* __bool__ _mlx_loop_hook(mlx_t* mlx, void (*f)(void*), void* param)_: Explicación en ```Hooks.md``` del repositorio de MLX42

* __void__ _mlx_loop(mlx_t* mlx)_: Hace que la ventana no cierre y crea el ciclo de renderizado del MLX42

## mlx_monitor.c

* __void__ _mlx_get_monitor_size(int32_t index, int32_t* width, int32_t* height)_: Devuelve en ```width``` y ```height``` las dimensiones de la pantalla del ordenador

## mlx_mouse.c

* __void__ _mlx_scroll_hook(mlx_t* mlx, mlx_scrollfunc func, void* param)_: Explicación en ```Hooks.md``` del repositorio de MLX42

* __void__ _mlx_mouse_hook(mlx_t* mlx, mlx_mousefunc func, void* param)_: Explicación en ```Hooks.md``` del repositorio de MLX42

* __void__ _mlx_cursor_hook(mlx_t* mlx, mlx_cursorfunc func, void* param)_: Explicación en ```Hooks.md``` del repositorio de MLX42

* __bool__ _mlx_is_mouse_down(mlx_t* mlx, mouse_key_t key)_: Devuelve ```true``` si ```key``` ha sido presionado

* __void__ _mlx_set_mouse_pos(mlx_t* mlx, int32_t x, int32_t y)_: Coloca el puntero del mouse en la posicion ```(x,y)``` de la ventana

* __void__ _mlx_get_mouse_pos(mlx_t* mlx, int32_t* x, int32_t* y)_: Devuelve las posiciones ```(x,y)``` del puntero del mouse en la pantalla


## mlx_put_pixel.c

* __void__ _mlx_put_pixel(mlx_image_t* image, uint32_t x, uint32_t y, uint32_t color)_: Printea un pixel de color ```color``` en las posiciones ```(x, y)``` de la imagen ```image```

## mlx_window.c

* __void__ _mlx_close_hook(mlx_t* mlx, mlx_closefunc func, void* param)_: Explicación en ```Hooks.md``` del repositorio de MLX42

* __void__ _mlx_resize_hook(mlx_t* mlx, mlx_resizefunc func, void* param)_: Explicación en ```Hooks.md``` del repositorio de MLX42

* __void__ _mlx_set_icon(mlx_t* mlx, mlx_texture_t* image)_: Convierte a ```image``` en el icono de la ventana

* __void__ _mlx_set_window_pos(mlx_t* mlx, int32_t xpos, int32_t ypos)_: Establece una nueva posicion ```(x,y)``` para la ventana 

* __void__ _mlx_get_window_pos(mlx_t* mlx, int32_t* xpos, int32_t* ypos)_: Devuelve la posición ```(x,y)``` de la ventana

* __void__ _mlx_set_window_size(mlx_t* mlx, int32_t new_width, int32_t new_height)_: Establece unas nuevas dimensiones [```new_width```, ```new_height```] para la ventana

* __void__ _mlx_set_window_limit(mlx_t* mlx, int32_t min_w, int32_t min_h, int32_t max_w, int32_t max_h)_: Establece límites de tamaño (dimensiones) para la ventana

* __void__ _mlx_set_window_title(mlx_t* mlx, const char* title)_: Establece un nuevo título para la ventana