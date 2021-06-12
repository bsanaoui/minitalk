/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsanaoui <bsanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:18:39 by bsanaoui          #+#    #+#             */
/*   Updated: 2021/06/12 17:51:21 by bsanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	pid_server = ft_atoi(argv[1]);
	send_signals(argv[2], pid_server);
	return (0);
}
