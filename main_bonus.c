
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

// void leaks()
// {
// 	imprimirCadena ("\n+++++++++++++++++++++++\n");
// 	system("leaks -q gnl");
// 	imprimirCadena ("\n+++++++++++++++++++++++\n");
// }

int	main(void)
{
	char	*str1;
	char	*str2;
	int		fd1;
	int		fd2;

	atexit(leaks);
	fd1 = open("text1", O_RDONLY);
	fd2 = open("text2", O_RDONLY);
	str1 = get_next_line(fd1);
	imprimirCadena (str1);
	str2 = get_next_line(fd2);
	imprimirCadena (str2);
//bucle
	while (str1 || str2)
	{
		if (str1)
		{
			free(str1);
			str1 = get_next_line(fd1);
			imprimirCadena (str1);
		}
		if (str2)
		{
			free(str2);
			str2 = get_next_line(fd2);
			imprimirCadena (str2);
		}
	}
	close (fd1);
	close (fd2);
}