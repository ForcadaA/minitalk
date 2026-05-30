/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:18:13 by aforcada          #+#    #+#             */
/*   Updated: 2025/11/29 13:24:19 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(const char *s, char d)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != d)
		len++;
	return (len);
}

static int	ft_wordcount(const char *s, char d)
{
	int		i;
	int		w;
	int		len;

	i = 0;
	w = 0;
	while (s[i])
	{
		len = ft_wordlen(&s[i], d);
		if (len > 0)
		{
			w++;
			i += len;
		}
		else
			i++;
	}
	return (w);
}

static void	ft_cpywords(char **arr, const char *s, char d)
{
	int	i;
	int	w;
	int	len;

	i = 0;
	w = 0;
	while (s[i])
	{
		len = ft_wordlen(&s[i], d);
		if (len > 0)
		{
			ft_strlcpy(arr[w], &s[i], len + 1);
			w++;
			i += len;
		}
		else
			i++;
	}
	arr[w] = NULL;
}

static char	**ft_putwords(char **arr, const char *s, char d)
{
	int	i;
	int	w;
	int	len;

	i = 0;
	w = 0;
	while (s[i])
	{
		len = ft_wordlen(&s[i], d);
		if (len > 0)
		{
			arr[w] = (char *) malloc(len + 1);
			if (!arr[w])
				return (NULL);
			w++;
			i += len;
		}
		else
			i++;
	}
	arr[w] = NULL;
	return (arr);
}

char	**ft_split(const char *s, char d)
{
	char	**arr;
	int		w;

	arr = (char **) malloc(sizeof(char *) * (ft_wordcount(s, d) + 1));
	if (!arr)
		return (NULL);
	if (ft_putwords(arr, s, d))
		ft_cpywords(arr, s, d);
	else
	{
		w = 0;
		while (arr[w])
		{
			free(arr[w]);
			arr[w] = NULL;
			w++;
		}
		free(arr);
		arr = NULL;
	}
	return (arr);
}
