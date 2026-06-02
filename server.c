/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 11:49:55 by aforcada          #+#    #+#             */
/*   Updated: 2026/06/02 12:47:02 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_data	g_server = (t_data){0};
static void		print_received_char(void);
void			signal_handler(int signum, siginfo_t *info, void *ucontext);

int	main(void)
{
	t_sigaction	sa;

	ft_print_pid();
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		usleep(UTIME_WAIT);
		pause();
	}
	return (0);
}

static void	print_received_char(void)
{
	if (g_server.char_received != '\0')
	{
		write(STDOUT_FILENO, &(g_server.char_received), 1);
	}
	else
	{
		write(STDOUT_FILENO, "\n", 1);
		g_server.client_pid = 0;
	}
	g_server.bit_count = 0;
	g_server.char_received = 0;
}

void	signal_handler(int signum, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (!(g_server.client_pid))
		g_server.client_pid = info->si_pid;
	if (g_server.client_pid == info->si_pid)
	{
		g_server.char_received <<= 1;
		if (signum == SIGUSR2)
			g_server.char_received |= 1;
		g_server.bit_count = g_server.bit_count + 1;
		if (g_server.bit_count == 8)
			print_received_char();
	}
}

