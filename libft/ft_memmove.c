/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:44:16 by aforcada          #+#    #+#             */
/*   Updated: 2025/11/29 11:22:10 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_l2rcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

static void	ft_r2lcpy(char *dest, const char *src, size_t n)
{
	int	i;

	i = n;
	while (0 < i--)
		dest[i] = src[i];
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest < src)
		ft_l2rcpy((char *)dest, (const char *)src, n);
	if (src < dest)
		ft_r2lcpy((char *)dest, (const char *)src, n);
	return (dest);
}
