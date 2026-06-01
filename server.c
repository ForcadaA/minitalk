/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 11:49:55 by aforcada          #+#    #+#             */
/*   Updated: 2026/06/01 18:00:15 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_data	data = (t_data){0};
static void		signal_handler(int signum, siginfo_t *info, void *ucontext);

int	main(void)
{
	t_sigaction	sa;

	ft_print_pid();
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

static void	signal_handler(int signum, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (!(data.client_pid))
		data.client_pid = info->si_pid;
	if (data.client_pid != info->si_pid)
		kill(info->si_pid, SIGUSR1);
	else
	{
		data.char_received <<= 1;
		if (signum == SIGUSR2)
			data.char_received |= 1;
		data.bit_count = data.bit_count + 1;
		if (data.bit_count == 8)
		{
			if (data.char_received != '\0')
				write(STDOUT_FILENO, &(data.char_received), 1);
			else
				data.client_pid = 0;
			data.bit_count = 0;
			data.char_received = 0;
		}
	}
}
