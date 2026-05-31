/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 11:49:45 by aforcada          #+#    #+#             */
/*   Updated: 2026/05/24 12:00:42 by aforcada         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minitalk.h"

void	ft_print_pid(void)
{
	int	curr_pid;

	curr_pid = getpid();
	ft_putnbr_fd(curr_pid, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}
