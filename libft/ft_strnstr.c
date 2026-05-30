/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:17:33 by aforcada          #+#    #+#             */
/*   Updated: 2025/11/29 11:50:05 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l;

	l = ft_strlen(little);
	if (l == 0)
		return ((char *)big);
	i = 0;
	while (i + l - 1 < len && *big)
	{
		if (!ft_strncmp(big, little, l))
			return ((char *)(big));
		big++;
		i++;
	}
	return (NULL);
}
