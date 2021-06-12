#include "minitalk.h"

static void	byte_to_char(int sig)
{
	static int	n_bits = 0;
	static char	c = 0;
	static char tmp_bit = 1;

	if (sig == 1)
		c = c | tmp_bit;
	tmp_bit = tmp_bit << 1;
	n_bits++;
	if (n_bits == 8)
	{
		ft_putchar(c);
		n_bits = 0;
		tmp_bit = 1;
		c = 0;
	}
}

static void	handle_signal(int sig)
{
	if (sig == SIGUSR1) {
		byte_to_char(1);
	}
	else
		byte_to_char(0);
}

int	main()
{
	pid_t	pid;

	pid = getpid();

	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	if (pid == -1)
		return (-1);
	put_string("Hello From Server | PID = ");
	ft_putnbr(pid);
	put_string("\n");
	while (1)
		pause();

	return (0);
}