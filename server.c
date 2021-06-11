#include "minitalk.h"

int	main()
{
	pid_t	pid;

	pid = getpid();
	if (pid == -1)
		return (-1);
	
	if (pid != 0)
	{
		while (1)
		{
			printf("Hello From Server | PID = %d\n", pid);
			usleep(500000);
		}
		
	}
	return (0);
}