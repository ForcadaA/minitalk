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

static void	handler(int signum)
{
	if (signum != 0)
		write(1, "yo\n", 3);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	if (argc != 1)
		return (0);
	sa.sa_handler = handler;
	sigempty(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	return (0);
}
