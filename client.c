/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 11:49:45 by aforcada          #+#    #+#             */
/*   Updated: 2026/06/02 12:50:04 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(pid_t server_pid, char c);
void	send_msg(pid_t server_pid, char *msg);

int	main(int ac, char *av[])
{
	pid_t		server_pid;
	char		*msg;

	if (ac != 3)
		error_handle("Error: ./client <pid> <string>\n");
	server_pid = ft_atoi(av[1]);
	if (server_pid < 0 && 4194304 < server_pid)
		error_handle("Error: pid out of range\n");
	msg = av[2];
	send_msg(server_pid, msg);
	return (0);
}

void	send_char(pid_t server_pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if ((c >> i) & 1)
		{
			if (kill(server_pid, SIGUSR2) == -1)
				error_handle("Error: char not sent\n");
		}
		else
		{
			if (kill(server_pid, SIGUSR1) == -1)
				error_handle("Error: char not sent\n");
		}
		usleep(UTIME_WAIT);
	}
	usleep(UTIME_WAIT);
}

void	send_msg(pid_t server_pid, char *msg)
{
	if (!msg)
	{
		error_handle("Error: no message\n");
	}
	while (*msg)
		send_char(server_pid, *msg++);
	send_char(server_pid, '\0');
}
