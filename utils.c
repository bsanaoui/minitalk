/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsanaoui <bsanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:49:40 by bsanaoui          #+#    #+#             */
/*   Updated: 2021/06/12 17:49:41 by bsanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_perror(const char *s)
{
	write(1, "Error\n", 7);
	write(1, s, ft_strlen(s));
	exit(EXIT_FAILURE);
	return (0);
}
