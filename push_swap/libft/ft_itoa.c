/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irrevuel <irrevuel@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:21:26 by irrevuel          #+#    #+#             */
/*   Updated: 2024/09/17 08:40:29 by irrevuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char	*exception(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else
		return (ft_strdup("0"));
}

char	*ft_itoa(int n)
{
	int		sign;
	int		index;
	char	*num;

	sign = 0;
	if (n == -2147483648 || n == 0)
		return (exception(n));
	index = numlen(n) - 1;
	num = (char *)malloc(sizeof(char) * (index + 2));
	if (!num)
		return (NULL);
	if (n < 0)
	{
		num[0] = '-';
		n = -n;
		sign = 1;
	}
	num[index + 1] = '\0';
	while (index >= sign)
	{
		num[index--] = n % 10 + '0';
		n = n / 10;
	}
	return (num);
}
