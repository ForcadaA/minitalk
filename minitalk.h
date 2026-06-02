/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 11:50:38 by aforcada          #+#    #+#             */
/*   Updated: 2026/06/02 12:27:39 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define UTIME_WAIT 400
# define _XOPEN_SOURCE 500

# include "./libft/libft.h"
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h> // delete this

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
	pid_t	client_pid;
};

void	ft_print_pid(void);
void	error_handle(char *error_msg);

#endif
