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

static t_list	g_recieved;

void	handle_sigusr12(int signum);
void	ft_lstaddlast(t_list *lst, void *content);
void	catch_char(t_sigaction *sa);

int	main(void)
{
	t_sigaction	sa;

	ft_print_pid();
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = &handle_sigusr12;
	while (1)
	{
		pause();
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			ft_quit(&g_encoded_msg);
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			ft_quit(&g_encoded_msg);
	}
	ft_quit(&g_encoded_msg);
	return (0);
}

void	handle_sigusr12(int signum)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	ft_bzero(data, sizeof(t_data));
	if (signum == SIGUSR1)
		data->val = 0;
	if (signum == SIGUSR2)
		data->val = 1;
	if (signum == SIGUSR1 || signum == SIGUSR2)
		ft_lstaddlast(&g_encoded_msg, data);
}

void	catch_char(t_sigaction *sa)
{
	int	i;
	char	c;

	i = 8;
	c = 0;
	while (i--)
	{
		pause();
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(UTIME_WAIT);
	}
}

void	ft_lstaddlast(t_list *lst, void	*content)
{
	t_list	*node;

	if (!lst)
	{
		lst = (t_list *)malloc(sizeof(t_list));
		if (!lst)
			return ;
		lst->content = content;
		lst->next = NULL;
		return ;
	}
	node = lst;
	while (node->next)
		node = node->next;
	node->next = (t_list *)malloc(sizeof(t_list));
	if (!(node->next))
		return ;
	node->next->content = content;
	node->next->next = NULL;
}
