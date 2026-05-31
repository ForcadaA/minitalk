/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_usr1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 11:49:45 by aforcada          #+#    #+#             */
/*   Updated: 2026/05/24 12:00:42 by aforcada         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minitalk.h"

void	handle_sigusr1(int signum, siginfo_t *info, void *ucontext)
{
	const char	*msg;

	msg = info->si_ptr;
	if (signum != 0)
		ft_putstr_fd((char *)msg, STDOUT_FILENO);
	if (ucontext)
		ft_putstr_fd("wut u doin here..?\n", STDOUT_FILENO);
}
