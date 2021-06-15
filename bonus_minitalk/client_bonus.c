/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsanaoui <bsanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:18:39 by bsanaoui          #+#    #+#             */
/*   Updated: 2021/06/15 17:20:41 by bsanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static char	msg_sended(char *msg)
{
	static char	*message = NULL;
	static int	i = 0;

	if (msg != NULL)
		message = msg;
	else
		return (message[i++]);
	return (message[i]);
}

static void	check_message(char send, char recieve)
{
	if (send != recieve)
		ft_perror("Message Not Sended Correctrly !!\n");
	if (send == recieve && send == '\0')
	{
		put_string("Message Sended Correctly\n");
		exit(EXIT_SUCCESS);
	}
}

static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int				n_bits = 0;
	static unsigned char	c = 0;
	static unsigned char	tmp_bit = 1;

	context = NULL;
	info->si_pid = 0;
	if (sig == SIGUSR1)
		c = c | tmp_bit;
	tmp_bit = tmp_bit << 1;
	n_bits++;
	if (n_bits == 8)
	{
		check_message(msg_sended(NULL), c);
		n_bits = 0;
		tmp_bit = 1;
		c = 0;
	}
}

int	main(int argc, char *argv[])
{
	pid_t				pid;
	struct sigaction	sig_act;

	pid = getpid();
	sig_act.sa_flags = SA_SIGINFO;
	sig_act.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &sig_act, NULL);
	sigaction(SIGUSR2, &sig_act, NULL);
	if (argc != 3)
		ft_perror("Not Valid Arguments\n");
	is_valid_pid(argv[1]);
	msg_sended(argv[2]);
	send_signals(argv[2], ft_atoi(argv[1]));
	while (1)
		pause();
	return (0);
}
