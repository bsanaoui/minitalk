/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsanaoui <bsanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 13:29:55 by bsanaoui          #+#    #+#             */
/*   Updated: 2021/06/15 16:34:26 by bsanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include<stdlib.h>
# include<unistd.h>
# include<signal.h>

void	ft_putchar(char c);
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
void	put_string(char *s);
void	ft_putnbr(int n);
int		ft_perror(const char *s);
char	*ft_itoa(int n);
void	is_valid_pid(char *s);
void	send_signals(char *s, int pid);
#endif