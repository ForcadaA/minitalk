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

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

typedef	struct s_args	t_args;

struct s_args
{
	void	*data;
	t_args	*next;
};
