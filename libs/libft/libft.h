/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:44:33 by jdomingu          #+#    #+#             */
/*   Updated: 2023/07/31 19:20:46 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/**
  * Verifica si un caracter es una letra, ya sea mayúscula o minúscula.
  * @param c el caracter como int.
  * @returns 0 si no es una letra. Cualquier otro número si lo es.
  */
int		ft_isalpha(int c);

/**
  * Verifica si un caracter es un número.
  * @param c el caracter como int.
  * @returns 0 si no es un número. Cualquier otro número si lo es.
  */
int		ft_isdigit(int c);

/**
  * Verifica si un caracter es una letra o un número.
  * @param c el caracter como int.
  * @returns 0 si no es un número o letra. Cualquier otro número si lo es.
  */
int		ft_isalnum(int c);

/**
  * Verifica si c es un unsigned char (7 bits) que pertenece a la tabla
  * ASCII de caracteres.
  * @param c caracter a verificar.
  * @returns 0 si no pertenece a la tabla ASCII. Cualquier otro número
  * si lo cumple.
  */
int		ft_isascii(int c);

/**
  * Los caracteres imprimibles son un subconjunto de la tabla ASCII.
  * Esta función verifica si el entero recibido es un caracter imprimible
  * de la tabla ASCII.
  * @param c Entero para verificar si es imprimible.
  * @returns 0 si no lo cumple. Cualquier otro número si lo cumple.
  */
int		ft_isprint(int c);

/**
  * Calcula el tamaño de un string.
  * @param str el string a procesar.
  * @returns el tamaño del string.
  */
size_t	ft_strlen(const char *str);

/**
  * Rellena los primero n bytes de un area de memoria con el valor
  * especificado.
  * La función modifica el contenido del puntero y también la devuelve.
  * @param b El bloque de memoria a rellenar.
  * @param c El valor que se quiere asignar.
  * @param len El nº de bytes que se quieren rellenar.
  * @returns Un puntero al principio de la misma posición 
  * de memoria que se pasa por parámetros.
  */
void	*ft_memset(void *b, int c, size_t len);

/**
  * Rellena los primeros n bytes de un bloque de memoria a 0.
  * La función modifica el contenido del puntero y también lo devuelve,
  * por si acaso.
  * @param s El bloque de memoria a rellenar.
  * @param n El nº de bytes que se quieren rellenar a 0.
  * @returns Un puntero al principio de la misma posición
  * de memoria que se pasa por parámetros.
  */
void	ft_bzero(void *s, size_t n);

/**
  * Copia n bytes de un bloque de memoria, src, a otro bloque
  * de memoria, dst. Los bloques de memoria no se pueden solapar. 
  * Usa memmove si se solapan. :)
  * @param dst bloque de memoria donde se ponen los bytes.
  * @param src bloque de memoria del cual se copian los bytes.
  * @param n nº de bytes a copiar.
  * @returns un puntero al principio de dst por si acaso.
  */
void	*ft_memcpy(void *dst, const void *src, size_t n);

/**
  * Copia n bytes de un bloque de memoria, src, a otro bloque
  * de memoria, dst. Los bloques de memoria pueden solaparse.
  * @param dst bloque de memoria donde se ponen los bytes.
  * @param src bloque de memoria del cual se copian los bytes.
  * @param len nº de bytes a copiar.
  * @returns un puntero al principio de dst por si acaso.
  */
void	*ft_memmove(void *dst, const void *src, size_t len);

/**
  * Copia en dst el string contenido en src como mucho hasta dstsize - 1
  * para añadir un null en la última posición y asegurarse de que es
  * null-terminating.
  * Si src es más pequeño, no va a rellenar todo hasta el final con
  * null. Sólo el último.
  * @param dst string donde de almacena la copia.
  * @param src string que se va a copiar.
  * @param dstsize tamaño del buffer de dst.
  * @returns el tamaño de src.
  */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/**
  * Concatena a continuación de dst lo que haya en src como mucho
  * hasta dstsize - 1, para asegurar que sea null-terminating.
  * @param dst El buffer donde se va a concatenar.
  * @param src El string a concatenar.
  * @param dstsize El tamaño del buffer destino.
  * @returns el tamaño total del string que se ha intentado crear.
  */
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);

/**
  * Transforma un caracter a mayúsculas si tiene sentido.
  * En otro caso devuelve el mismo caracter.
  * @param c el caracter a transformar.
  * @returns el caracter en mayúsculas si se puede convertir.
  * Si no el mismo caracter.
  */
int		ft_toupper(int c);

/**
  * Transforma un caracter a minúscilas si tiene sentido.
  * En otro caso devuelve el mismo caracter.
  * @param c el caracter a transformar.
  * @returns el caracter en minúsculas si se puede convertir.
  * Si no el mismo caracter.
  */
int		ft_tolower(int c);

/**
  * Busca la primera ocurrencia del caracter c en el string s.
  * @param str El string a analizar.
  * @param c El caracter a buscar.
  * @return un puntero a la primera ocurrencia del caracter en el string,
  * o NULL si el caracter no se encuentra.
  */
char	*ft_strchr(const char *s, int c);

/**
  * Busca la última ocurrencia del caracter c en el string s.
  * @param str El string a analizar.
  * @param c El caracter a buscar.
  * @return un puntero a la última ocurrencia del caracter en el string,
  * o NULL si el caracter no se encuentra.
  */
char	*ft_strrchr(const char *s, int c);

/**
  * Compara dos strings lexicográficamente según su valor en la tabla ascii.
  * Va comparando hasta que uno de ellos termine o lleguemos al tamaño n.
  * @param s1 Primer string.
  * @param s2 Segundo string.
  * @param n Tamaño máximo a comparar.
  * @return si son iguales hasta el tamaño n, devuelve 0.
  * Si es primero es menor, devuelve un número negativo.
  * Si el primero es mayor, devuelve un número positivo.
  */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
  * Busca la primera ocurrencia del caracter c 
  * en los primeros n bytes del string.
  * @param str El puntero al bloque de memoria donde se realiza la búsqueda.
  * @param c El valor a buscar como entero, que se transforma a byte.
  * @param n El numero de bytes a analizar.
  * @return Un puntero al byte encontrado o NULL
  * si el caracter no se encuentra en el bloque.
  */
void	*ft_memchr(const void *s, int c, size_t n);

/**
  * Compara los primeros n bytes del bloque de memoria ptr1
  * con los primeros n bytes de ptr2, y devuelve un valor
  * indicando cuál es mayor.
  * @param ptr1 Puntero a un bloque de memoria.
  * @param ptr2 Puntero a un bloque de memoria.
  * @param num Número de bytes a comparar.
  * @return Entero que indica la relación entre el contenido de
  * los bloques de memoria:
  * 0 si el contenido de los bloqies de memoria son iguales.
  * <0 si el primer byte que no coincide en ambos bloques tiene menor valor
  * en ptr1 que en ptr2.
  * >0 si el primer byte que no coincide en ambos bloques tiene mayor valor
  * en ptr1 que en ptr2.
  */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
  * Busca la primera ocurrencia del string needle en haystack,
  * buscando no más de len caracteres en el haystack.
  * @param haystack El string donde se realiza la búsqueda.
  * @param needle El substring a buscar.
  * @param len El tamaño máximo donde realizar la búsqueda en el haystack.
  * @returns Si encuentra el substring, un puntero desde donde lo encuentra,
  * incluyendo al substring. Si no lo encuentra, NULL.
  */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/**
  * Convierte un string a entero si es posible.
  * @returns El número encontrado en el string. 
  * Si en algún momento se detecta un valor no númerico,
  * se para de procesar ahí y se devuelve el número detectado
  * hasta el momento. 0 si no se ha detectado ningún
  * número desde el principio)
  * Si se ha hecho overflow por arriba, devuelve -1.
  * Si se ha hecho overflow por debajo, devuelve 0.
  */
int		ft_atoi(const char *str);

/**
  * Reserva memoria en condiciones: Comprueba que no se haga overflow.
  * Esta función reserva memoria para n elementos (tipo básico, struct, ...)
  * de tamaño size y lo inicializa a 0 todo.
  * @param count El número de elementos que se quieren reservar.
  * @param size El tamaño de un elemento.
  * @returns un puntero al principio de la región de memoria reservada
  * o NULL si hubo algún problema a la hora de realizar la reserva.
  */
void	*ft_calloc(size_t count, size_t size);

/**
  * Reserva memoria y duplica el string recibido por parámetros.
  * @param s1 el string a duplicar.
  * @returns una copia del string s1 en un nuevo string reservado
  * o NULL si hubo algún problema al reservar la memoria.
  */
char	*ft_strdup(const char *s1);

/**
  * Reserva y devuelve un substring de s empezando desde el índice start
  * y con tamaño máximo len.
  * @param s String desde el que crear el substring.
  * @param start El índice del caracter en s desde el que empezar el substring.
  * @param len La longitud máxima del substring.
  * @return EL substring resultante o NULL si falla la reserva de memoria.
  */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
  * Reserva y devuelve un nuevo string, formado por la concatenación de s1 y s2.
  * @param s1 El primer string.
  * @param s2 El string a añadir a s1.
  * @returns El nuevo string o NULL si falla la reserva de memoria.
  */
char	*ft_strjoin(char const *s1, char const *s2);

/**
  * Elimina todos los caracteres del string set desde el principio
  * y desde el final de ’s1’, hasta encontrar un caracter no perteneciente a set.
  * El string resultante se devuelve en una posición nueva reservada.
  * @param s1 El string que debe ser recortado.
  * @param set: Los caracteres a eliminar del string.
  * @returns El string recortado o NULL si falla la reserva de memoria.
  */
char	*ft_strtrim(char const *s1, char const *set);

/**
  * Reserva un array de strings resultante de separar s en substrings
  * utilizando el caracter ’c’ como delimitador.
  * @param s El string a separar.
  * @param c El carácter delimitador.
  * @returns El array de strings resultante de la separación, terminado
  * en un NULL o NULL si falla la reserva de memoria.
  */
char	**ft_split(char const *s, char c);

/**
  * Genera un string que representa el valor entero
  * recibido como argumento.
  * @param n El entero a convertir.
  * @returns El string que representa al número
  * o NULL si falla la reserva de memoria.
  */
char	*ft_itoa(int n);

/**
  * Aplica la función f a cada carácter del string ’s’,
  * dando como parámetros el índice de cada carácter y el propio valor.
  * Genera un nuevo string con el resultado de cada caracter.
  * @param s El string que se itera.
  * @param f La función que se aplica sobre cada carácter.
  * @returns El string creado tras llamar a ’f’ sobre cada carácter o
  * NULL si falla la reserva de memoria.
  */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
  * Aplica la función f a cada carácter del string s, 
  * dando como parámetros el índice de cada carácter y la dirección
  * del propio carácter, que podrá modificarse si es necesario.
  * @param s El string que iterar.
  * @param f La función que se aplica sobre cada carácter.
  */
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
  * Envía el carácter c al file descriptor especificado.
  * @param c El carácter a enviar.
  * @param fd El file descriptor sobre el que escribir.
  */
void	ft_putchar_fd(char c, int fd);

/**
  * Envía el string s al file descriptor especificado.
  * @param s El string a enviar.
  * @param fd El file descriptor sobre el que escribir.
  */
void	ft_putstr_fd(char *c, int fd);

/**
  * Envía el string s al file descriptor especificado
  * seguido de un salto de línea.
  * @param s El string a enviar.
  * @param fd El file descriptor sobre el que escribir.
  */
void	ft_putendl_fd(char *s, int fd);

/**
  * Envía el número n al file descriptor especificado.
  * @param s El número a enviar.
  * @param fd El file descriptor sobre el que escribir.
  */
void	ft_putnbr_fd(int n, int fd);

/**
  * Crea un nuevo nodo. La variable content se inicializa con el
  * contenido del parámetro ’content’. 
  * La variable ’next’, se inicializa a NULL.
  * @param content el contenido con el que crear el nodo.
  * @returns El nuevo nodo
  */
t_list	*ft_lstnew(void *content);

/**
  * Añade el nodo new al principio de la lista ’lst’.
  * @param lst Dirección de un puntero al primer nodo de una lista.
  * @param new Puntero al nodo que añadir.
  */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
  * Añade el nodo new al final de la lista ’lst’.
  * @param lst Dirección de un puntero al primer nodo de una lista.
  * @param new Puntero al nodo que añadir.
  */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
  * Cuenta el número de nodos de una lista.
  * @param lst El principio de la lista.
  * @returns La longitud de la lista.
  */
int		ft_lstsize(t_list *lst);

/**
  * Devuelve el último nodo de la lista.
  * @param lst El principio de la lista.
  * @returns Último nodo de la lista.
  */
t_list	*ft_lstlast(t_list *lst);

/**
  * Función para liberar un nodo de la lista.
  * Además, libera la memoria del contenido utilizando la función del.
  * No libera la memoria de next.
c lst El nodo a liberar.
  * @param del: Puntero a la función para liberar el contenido del nodo.
  */
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/**
  * Elimina y libera una lista entera.
  * Para liberar el puntero content se utiliza la función del.
  * Al final, el puntero a la lista va a ser NULL.
  * @param lst Dirección de un puntero a una lista.
  * @param del Puntero a función para eliminar el contenido de un nodo.
  */
void	ft_lstclear(t_list **lst, void (*del)(void*));

/**
  * Itera la lista lst y aplica la función f en el contenido de cada nodo.
  * @param lst Puntero al primer nodo.
  * @param f Puntero a la función que utilizará cada nodo.
  */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
  * Itera la lista lst y aplica la función f al contenido de cada nodo.
  * Crea una lista resultante de la aplicación sucesiva de ’f’ sobre cada nodo. 
  * La función ’del’ se utiliza para eliminar el contenido de un nodo,
  * si hiciera falta.
  * @param lst Puntero al principio de la lista.
  * @param f Función usada en la iteración de cada elemento de la lista.
  * @param del Función utilizado para eliminar el contenido de un nodo,
  * si es necesario.
  * @returns La nueva lista, o NULL si falla la reserva de memoria.
  */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
