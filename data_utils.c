/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:48:18 by aforcada          #+#    #+#             */
/*   Updated: 2026/06/01 16:34:52 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_init_data(t_data *data, pid_t client_pid);
int	ft_copy_data(t_data *dst, t_data *src);

int	ft_init_data(t_data *data, pid_t client_pid)
{
	if (!data)
		return (0);
	data->bit_count = 0;
	data->char_received = 0;
	data->client_pid = client_pid;
	return (1);
}

int	ft_copy_data(t_data *dst, t_data *src)
{
	if (!src)
		return (0);
	dst = (t_data *)malloc(sizeof(t_data));
	if (!dst)
		return (0);
	*dst = *src;
	return (1);
}
