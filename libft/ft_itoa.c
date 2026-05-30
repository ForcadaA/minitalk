/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:22:40 by aforcada          #+#    #+#             */
/*   Updated: 2025/11/29 00:46:24 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digits(long int x)
{
	int			digits;
	long int	cpy;

	if (x < 10)
		return (1);
	digits = 1;
	cpy = x;
	while (cpy > 9)
	{
		cpy /= 10;
		digits++;
	}
	return (digits);
}

static void	ft_revitoa(char *n, long int x, int digits)
{
	int		i;

	if (digits == 1)
	{
		n[0] = '0' + x;
		return ;
	}
	i = 0;
	while (i < digits)
	{
		n[i] = '0' + (x % 10);
		x /= 10;
		i++;
	}
}

static void	ft_revstr(char *n, int len)
{
	int		i;
	char	tmp;

	i = 0;
	while (2 * i < len)
	{
		tmp = n[i];
		n[i] = n[len - 1 - i];
		n[len - 1 - i] = tmp;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char		*num;
	int			sign;
	int			digits;
	long int	x;

	x = (long int)n;
	sign = (int)(x < 0);
	if (sign)
		x = -x;
	digits = ft_digits(x);
	num = (char *) malloc(sign + digits + 1);
	if (!num)
		return (NULL);
	if (sign)
		num[0] = '-';
	ft_revitoa(num + sign, x, digits);
	ft_revstr(num + sign, digits);
	num[sign + digits] = '\0';
	return (num);
}
