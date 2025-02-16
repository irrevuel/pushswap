/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irrevuel <irrevuel@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:17:20 by irrevuel          #+#    #+#             */
/*   Updated: 2024/09/21 13:17:36 by irrevuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_reverse_copy(void *dest, const void *src, size_t n)
{
	int	i;

	i = n - 1;
	while (n--)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i--;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	if (dest <= src)
	{
		ft_memcpy(dest, src, n);
	}
	else if (dest > src)
	{
		ft_reverse_copy(dest, src, n);
	}
	return (dest);
}
