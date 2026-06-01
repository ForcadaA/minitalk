/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 11:49:45 by aforcada          #+#    #+#             */
/*   Updated: 2026/06/01 16:39:15 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(pid_t server_pid, t_sigaction *sa, char c);
void	send_msg(pid_t server_pid, t_sigaction *sa, char *msg);

int	main(int ac, char *av[])
{
	t_sigaction	sa;
	pid_t		server_pid;
	char		*msg;

	if (ac != 3)
		ft_quit(NULL);
	server_pid = ft_atoi(av[1]);
	msg = av[2];
	sigemptyset(&sa.sa_mask);
	send_msg(server_pid, &sa, msg);
	return (0);
}

void	send_char(pid_t server_pid, t_sigaction *sa, char c)
{
	int	i;
	int	j;

	i = 8;
	j = 0;
	while (j != i)
	{
		if ((c >> (i - j)) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		pause();
		if (!sigaction(SIGUSR2, sa, NULL))
			j++;
		usleep(UTIME_WAIT);
	}
	usleep(UTIME_WAIT >> 1);
}

void	send_msg(pid_t server_pid, t_sigaction *sa, char *msg)
{
	if (!msg)
		ft_quit(NULL);
	while (*msg)
		send_char(server_pid, sa, *msg++);
}
