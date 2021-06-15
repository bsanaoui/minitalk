/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsanaoui <bsanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:16:47 by bsanaoui          #+#    #+#             */
/*   Updated: 2021/06/15 17:24:17 by bsanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static char	*msg_recieved(char c, pid_t pid)
{
	static char	*message = NULL;
	static int	i = 0;

	if (message == NULL)
		message = (char *)malloc(sizeof(char) * 10000);
	if (i < 10000 )
		message[i++] = c;
	if (c == '\0')
	{
		send_signals(message, pid);
		i = 0;
	}
	return (message);
}

static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int				n_bits = 0;
	static unsigned char	c = 0;
	static unsigned char	tmp_bit = 1;

	context = NULL;
	if (sig == SIGUSR1)
		c = c | tmp_bit;
	tmp_bit = tmp_bit << 1;
	n_bits++;
	if (n_bits == 8)
	{
		msg_recieved(c, info->si_pid);
		ft_putchar(c);
		n_bits = 0;
		tmp_bit = 1;
		c = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sig_act;

	pid = getpid();
	sig_act.sa_flags = SA_SIGINFO;
	sig_act.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &sig_act, NULL);
	sigaction(SIGUSR2, &sig_act, NULL);
	if (pid == -1)
		return (-1);
	put_string("Server Is Running ... | PID = ");
	ft_putnbr(pid);
	put_string("\n");
	while (1)
		pause();
	return (0);
}
