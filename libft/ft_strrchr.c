/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:34:46 by aforcada          #+#    #+#             */
/*   Updated: 2025/11/29 11:49:40 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*pos;

	i = ft_strlen(s);
	pos = (char *)(&s[i]);
	while (0 < i-- && *pos != (char)c)
		pos--;
	if (*pos == (char)c)
		return (pos);
	return (NULL);
}
