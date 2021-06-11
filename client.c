#include "minitalk.h"

int	main(int argc, char *argv[])
{
	int	pid_server;

	argc = 5;
	printf("Hello From Client\n");
	pid_server = atoi(argv[1]);
	
	kill(pid_server, SIGUSR1);
	return (0);
}