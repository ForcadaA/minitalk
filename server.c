/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 11:49:55 by aforcada          #+#    #+#             */
/*   Updated: 2026/06/01 16:39:16 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_list	g_pending = {0};

void	signal_handler(int signum, siginfo_t *info, void *ucontext);
int		ft_lstaddlast(t_list *lst, t_data *data);

int	main(void)
{
	t_sigaction	sa;

	ft_print_pid();
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &signal_handler;
	while (1)
	{
		pause();
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	return (0);
}

void	signal_handler(int signum, siginfo_t *info, void *ucontext)
{
	static t_data	data = (t_data){0};

	(void)ucontext;
	(void)signum;
	if (data.pending_client_pid != info->si_pid)
	{
		// do something
	}
}

int	ft_is_pending_client(pid_t client_pid)
{
	int		is_pending;
	t_list	*node;

	is_pending = 0;
	node = &g_pending;
	if (!(node->data) || !(node->data->pending_client_pid))
		return (0);
	if (node->data->pending_client_pid == client_pid)
		return (1);
	if (!(node->next))
		return (0);
}

int	ft_lstaddlast(t_list *lst, t_data *data)
{
	t_list	*node;

	if (!lst)
	{
		lst = (t_list *)malloc(sizeof(t_list));
		if (!lst)
			return (0);
		if (!ft_copy_data(lst->data, data))
			return (0);
		lst->next = NULL;
		return (1);
	}
	node = lst;
	while (node->next)
		node = node->next;
	node->next = (t_list *)malloc(sizeof(t_list));
	if (!(node->next))
		return (0);
	if (!ft_copy_data(node->next->data, data))
		return (0);
	node->next->next = NULL;
	return (1);
}
