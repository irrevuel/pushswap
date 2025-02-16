/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irrevuel <irrevuel@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:32:01 by irrevuel          #+#    #+#             */
/*   Updated: 2024/09/20 09:32:21 by irrevuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*s1_cast;
	const char	*s2_cast;

	s1_cast = s1;
	s2_cast = s2;
	i = 0;
	while (i < n)
	{
		if (s1_cast[i] != s2_cast[i])
			return ((unsigned char)s1_cast[i] - (unsigned char)s2_cast[i]);
		i++;
	}
	return (0);
}
