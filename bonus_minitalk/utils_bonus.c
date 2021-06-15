/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsanaoui <bsanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:49:40 by bsanaoui          #+#    #+#             */
/*   Updated: 2021/06/15 17:09:24 by bsanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	char_to_binary(int c, int pid)
{
	int		i;
	int		bit;

	i = 7;
	while (i >= 0)
	{
		bit = c & 1;
		if (bit == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(90);
		c = c >> 1;
		i--;
	}
}

void	send_signals(char *s, int pid)
{
	int	i;

	i = -1;
	while (s[++i])
		char_to_binary(s[i], pid);
	char_to_binary(0, pid);
}

void	is_valid_pid(char *s)
{
	int	i;

	i = -1;
	if (s[0] == '-' || s[0] == '+')
	{
		ft_perror("Not A valid PID\n");
		i++;
	}
	while (s[++i])
	{
		if ((s[i] < 48 || s[i] > 57))
			ft_perror("Not A valid PID\n");
	}
}

int	ft_perror(const char *s)
{
	write(1, "Error\n", 7);
	write(1, s, ft_strlen(s));
	exit(EXIT_FAILURE);
	return (0);
}
