/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsanaoui <bsanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:16:47 by bsanaoui          #+#    #+#             */
/*   Updated: 2021/06/12 17:17:09 by bsanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_signal(int sig)
{
	static int				n_bits = 0;
	static unsigned char	c = 0;
	static unsigned char	tmp_bit = 1;

	if (sig == SIGUSR1)
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

int	main(void)
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
