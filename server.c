/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 11:49:55 by aforcada          #+#    #+#             */
/*   Updated: 2026/05/24 12:26:11 by aforcada         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minitalk.h"

static t_list	g_encoded_msg;

void	handle_sigusr12(int signum);

int	main(void)
{
	t_sigaction	sa;

	ft_print_pid();
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = &handle_sigusr12;
	while (1)
	{
		pause();
		if (sigaction(SIGUSR1 | SIGUSR2, &sa, NULL) == -1)
			ft_quit();
	}
	return (0);
}

void	handle_sigusr12(int signum)
{
	if (signum == SIGUSR1)
		i = 0;
	if (signum == SIGUSR2)
		i = 1;
}
