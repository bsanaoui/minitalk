#include "minitalk.h"

int	main()
{
	kill(25053, SIGKILL);
	printf("Hello From Client\n");
	return (0);
}