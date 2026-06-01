/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 11:49:45 by aforcada          #+#    #+#             */
/*   Updated: 2026/05/24 12:00:42 by aforcada         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minitalk.h"

void	send_char(pid_t server_pid, char c);
void	send_msg(pid_t server_pid, char *msg);

int	main(int ac, char *av[])
{
	pid_t	server_pid;
	char	*msg;
	
	if (ac != 3)
		ft_quit(NULL);
	server_pid = ft_atoi(av[1]);
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
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(UTIME_WAIT);
	}
	usleep(UTIME_WAIT >> 1);
}

void	send_msg(pid_t server_pid, char *msg)
{
	if (!msg)
		ft_quit(NULL);
	while (*msg)
		send_char(server_pid, *msg++);
}
