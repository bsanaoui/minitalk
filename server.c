#include "minitalk.h"

void	handle_signal(int sig)
{
	if (sig == SIGUSR1) {
		printf("Recieve Signal 1\n");
	}
	else
		printf("Recieve Signal 2\n");
}

int	main()
{
	pid_t	pid;

	pid = getpid();

	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	if (pid == -1)
		return (-1);
	
	printf("Hello From Server | PID = %d\n", pid);
	while (1)
		pause();

	return (0);
}