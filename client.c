#include "minitalk.h"

static void	char_to_binary(int c, int pid_server)
{
	int		i;
	int		bit;

	i = 7;
	while (i >= 0)
	{
		bit = c & 1;
		if (bit == 1)
			kill(pid_server, SIGUSR1);
		else
			kill(pid_server, SIGUSR2);
		usleep(90);
		c = c >> 1;
		i--;
	}
}

static void	send_signals(char *s, int pid_server)
{
	int	i;
	int	lenght;

	lenght = ft_strlen(s);
	i = -1;
	while (++i < lenght)
		char_to_binary(s[i], pid_server);
}

int	main(int argc, char *argv[])
{
	int	pid_server;

	if (argc != 3)
		ft_perror("Not Valid Arguments\n");
	printf("Hello From Client\n");
	pid_server = ft_atoi(argv[1]);
	send_signals(argv[2], pid_server);
	// printf("Character \"%c\" To Binary Is : %s\n",argv[2][0], char_to_binary(argv[2][0], pid_server));

	return (0);
}

// 001100111

// 000000001

// 000000001
