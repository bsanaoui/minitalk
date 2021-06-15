/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsanaoui <bsanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:49:40 by bsanaoui          #+#    #+#             */
/*   Updated: 2021/06/15 16:27:46 by bsanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
