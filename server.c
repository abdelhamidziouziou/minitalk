/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:05:49 by abziouzi          #+#    #+#             */
/*   Updated: 2022/03/23 22:55:58 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_handler(int sig, siginfo_t *info, void *ucontext);

int	main(void)
{
	struct sigaction	ft_sigact;

	ft_sigact.sa_sigaction = &ft_handler;
	ft_sigact.sa_flags = 0;
	ft_sigact.sa_mask = 0;
	sigaction(SIGUSR1, &ft_sigact, NULL);
	sigaction(SIGUSR2, &ft_sigact, NULL);
	write(1, "Server PID is : ", 17);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		pause();
	}
}

void	ft_handler(int sig, siginfo_t *info, void *ucontext)
{
	int			bit;
	static int	i;
	static int	last_pid;
	static char	c;

	(void)ucontext;
	if (last_pid != 0 && last_pid != info->si_pid)
	{
		i = 0;
		c = 0;
		write(1, "\n", 1);
	}
	i++;
	bit = sig - 30;
	c = (c << 1) | bit;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	last_pid = info->si_pid;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}
