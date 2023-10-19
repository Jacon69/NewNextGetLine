
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

#include <unistd.h>

void imprimirCadena(const char *cadena) {
    // Verifica si el puntero es NULL.
    if (cadena == NULL) {
        const char *mensaje = "(null)\n";
        write(STDOUT_FILENO, mensaje, strlen(mensaje));
    } else {
        // Itera sobre la cadena hasta encontrar el carácter nulo.
        for (int i = 0; cadena[i] != '\0'; i++) {
            // Escribe cada carácter en la salida estándar (pantalla).
            write(STDOUT_FILENO, &cadena[i], 1);
        }
    }
}

void leaks()
{
	system("leaks gnl");
}

int	main(void)
{
	char	*str;
	int		fd;

	fd = open("prueba", O_RDONLY);
  	str = get_next_line(fd);
    if (str)
        imprimirCadena (str);
//bucle
    while (str)
    {
        str = get_next_line(fd);
       
        if (str)
        {
             imprimirCadena (str);
            free(str);
        }
    }
	close (fd);
	//leaks();
}