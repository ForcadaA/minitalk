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
char	buf_to_char(const char *buf[8]);


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
			ft_quit(&g_recieved);
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			ft_quit(&g_recieved);
	}
	ft_quit(&g_recieved);
	return (0);
}

void	handle_sigusr12(int signum)
{
	if (signum == SIGUSR1)
		data->val = 0;
	if (signum == SIGUSR2)
		data->val = 1;
	if (signum == SIGUSR1 || signum == SIGUSR2)
		ft_lstaddlast(&g_recieved, data);
}

char	buf_to_char(const char *buf[8])
{
	int		i;
	char	c;

	i = 8;
	c = 0;
	while (i--)
	{
		if ((*buf)[i] < 0)
			return (-1);
		c = c + ((*buf)[i] << i);
	}
}

void	catch_char(t_sigaction *sa)
{
	static char	buf[8];
	int			i;

	i = 8;
	while (i--)
	{
		pause();
		if (sigaction(SIGUSR1, sa, NULL) != -1)
			buf[i] = 0;
		else if (sigaction(SIGUSR2, sa, NULL) != -1)
			buf[i] = 1;
		else
			buf[i] = -1;
	}
}

void	ft_lstaddlast(t_list *lst, void	*content)
{
	t_list	*node;

	if (!lst)
	{
		lst = (t_list *)malloc(sizeof(t_list));
		if (!lst)
			ft_quit(NULL);
		lst->content = content;
		lst->next = NULL;
		return ;
	}
	node = lst;
	while (node->next)
		node = node->next;
	node->next = (t_list *)malloc(sizeof(t_list));
	if (!(node->next))
		ft_quit(lst);
	node->next->content = content;
	node->next->next = NULL;
}
