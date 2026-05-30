/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:38:02 by aforcada          #+#    #+#             */
/*   Updated: 2025/11/29 11:24:56 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	cc;
	char	*cs;

	i = 0;
	cc = (char)c;
	cs = (char *)s;
	while (i < n)
	{
		cs[i] = cc;
		i++;
	}
	return (s);
}
