/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsanaoui <bsanaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 13:29:55 by bsanaoui          #+#    #+#             */
/*   Updated: 2021/06/15 16:27:52 by bsanaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include<stdlib.h>
# include<unistd.h>
# include<signal.h>

void	ft_putchar(char c);
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
void	put_string(char *s);
void	ft_putnbr(int n);
int		ft_perror(const char *s);
void	is_valid_pid(char *s);

#endif