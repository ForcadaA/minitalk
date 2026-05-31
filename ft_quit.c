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

static void	ft_free_node(t_list *node)
{
	if (!node)
		return ;
	free(node->content);
	node->content = NULL;
	free(node);
	node = NULL;
}

static void	ft_exit(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_quit(t_list *lst)
{
	t_list	*node;

	if (!lst)
		ft_exit();
	node = lst;
	lst = lst->next;
	ft_free_node(node);
	while (lst)
	{
		node = lst;
		lst = lst->next;
		ft_free_node(node);
	}
	ft_exit();
}
