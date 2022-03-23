/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:05:51 by abziouzi          #+#    #+#             */
/*   Updated: 2022/03/23 22:56:18 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr(char *str);
void	ft_send_message(int server_pid, char letter);
int		ft_atoi(const char *str);

int	main(int argc, char *argv[])
{
	int	server_pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (server_pid <= 0)
		{
			ft_putstr("Invalid PID.");
			exit(1);
		}
		while (argv[2][i])
		{
			ft_send_message(server_pid, argv[2][i]);
			i++;
		}
	}
	else
		ft_putstr("Client : Invalid arguments.\n");
	return (EXIT_FAILURE);
}

void	ft_send_message(int server_pid, char letter)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (letter >> i) & 1;
		kill(server_pid, SIGUSR1 + bit);
		usleep(500);
		i--;
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return (r);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
