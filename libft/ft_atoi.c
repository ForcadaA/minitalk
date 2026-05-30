/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 23:48:18 by aforcada          #+#    #+#             */
/*   Updated: 2026/05/22 11:03:22 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	num;
	int				sign;

	num = 0;
	sign = 0;
	while (*str && ft_isspace(*str))
		str++;
	if (*str && ft_issign(*str))
		sign = *str++;
	while (*str && ft_isdigit(*str))
		num = num * 10 + ((*str++) - '0');
	if (sign == '-')
		return (-(int)num);
	return (num);
}
