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

int	main(int ac, char *av[])
{
	t_sigact	sa;
	siginfo_t	info;

	if (ac != 3)
		ft_quit();
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handle_sigusr1;
	info.si_signo = SIGUSR1;
	info.si_code = SI_QUEUE;
	info.si_ptr = av[2];
}
