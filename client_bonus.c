/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:44:13 by abziouzi          #+#    #+#             */
/*   Updated: 2022/03/23 22:46:54 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_putstr(char *str);
int		ft_atoi(const char *str);
void	ft_received(int sig);
void	ft_send_message(int server_pid, char letter);

int	main(int argc, char *argv[])
{
	int		server_pid;
	char	*message;

	signal(SIGUSR1, ft_received);
	if (argc != 3)
	{
		ft_putstr("Client : Invalid arguments.\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_putstr("Invalid PID.");
		exit(1);
	}
	message = argv[2];
	while (*message)
	{
		ft_send_message(server_pid, *message);
		message++;
	}
	ft_send_message(server_pid, 0);
}

void	ft_received(int sig)
{
	(void)sig;
	write(1, "Message sent.\n", 15);
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
