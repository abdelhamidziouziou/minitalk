/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:45:16 by abziouzi          #+#    #+#             */
/*   Updated: 2022/03/23 22:55:17 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

// Server functions
void	ft_handler(int sig, siginfo_t *info, void *ucontext);

// Client functions
int		ft_atoi(const char *str);
void	ft_putstr(char *str);
void	ft_received(int sig);
void	ft_send_message(int server_pid, char letter);

#endif
