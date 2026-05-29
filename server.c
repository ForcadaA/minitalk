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

void	handle_usr1(int sig, siginfo_t *info, void *ucontext);

void	handle_usr1(int sig, siginfo_t *info, void *ucontext)
{
	const char	*msg;

	msg = info->si_ptr;
	if (sig != 0)
		write(STDOUT_FILENO, msg, ft_strlen(msg));
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_usr1;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);

	return (0);
}
