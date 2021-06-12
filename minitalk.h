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
char	*ft_itoa(int n);
#endif