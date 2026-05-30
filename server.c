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

int		ft_strlen(const char *s);
void	handle_usr1(int sig, t_siginfo *info);

int	main(void)
{
	t_sigact	*sa;
	
	sa = (t_sigact *)malloc(sizeof(t_sigact *));
	sigemptyset(&(sa->sa_mask));
	free(sa);
	sa = NULL;
	return (0);
}

void	handle_usr1(int sig, t_siginfo *info)
{
	const char	*msg;

	msg = info->si_ptr;
	if (sig != 0)
		write(STDOUT_FILENO, msg, ft_strlen(msg));
}

int	ft_strlen(const char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}
