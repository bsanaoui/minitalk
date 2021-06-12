#include "minitalk.h"

int	ft_perror(const char *s)
{
	write(1, "Error\n", 7);
	write(1, s, ft_strlen(s));
	exit(EXIT_FAILURE);
	return (0);
}