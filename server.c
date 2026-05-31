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

int	main(void)
{
	t_sigact	sa;

	ft_print_pid();
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handle_sigusr1;
	pause();
	sigaction(SIGUSR1, &sa, NULL);
	return (0);
}
