/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:21:26 by aforcada          #+#    #+#             */
/*   Updated: 2025/11/29 01:09:17 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*us;
	unsigned char	uc;

	i = 0;
	us = (unsigned char *)s;
	uc = (unsigned char)c;
	while (i < n)
	{
		if (us[i] == uc)
			return ((void *)(us + i));
		i++;
	}
	return (NULL);
}
