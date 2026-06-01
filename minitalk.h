/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 11:50:38 by aforcada          #+#    #+#             */
/*   Updated: 2026/06/01 16:39:14 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define UTIME_WAIT 500
# define _XOPEN_SOURCE 500

# include "./libft/libft.h"
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

typedef struct s_list		t_list;
typedef struct s_data		t_data;
typedef struct sigaction	t_sigaction;

struct s_list
{
	t_data	*data;
	t_list	*next;
};

struct s_data
{
	int		bit_count;
	char	char_received;
	pid_t	pending_client_pid;
};

void	signal_handler(int signum, siginfo_t *info, void *ucontext);
void	ft_print_pid(void);
void	ft_quit(t_list *lst);
int		ft_init_data(t_data *data, pid_t client_pid);
int		ft_copy_data(t_data *dst, t_data *src);

#endif
