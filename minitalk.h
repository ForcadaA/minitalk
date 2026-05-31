/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 11:50:38 by aforcada          #+#    #+#             */
/*   Updated: 2026/05/24 12:14:15 by aforcada         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef MINITALK_H
# define MINITALK_H

# define UTIME_WAIT 500
# define _XOPEN_SOURCE 700

# include "./libft/libft.h"
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

typedef	struct s_list		t_list;
typedef struct s_data		t_data;
typedef struct sigaction	t_sigaction;

struct s_list
{
	void	*content;
	t_list	*next;
};

struct s_data
{
	int		id;
	char	val;
};

void	handle_sigusr12(int signum);
void	ft_print_pid(void);
void	ft_quit(t_list *lst);

#endif
