/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irrevuel <irrevuel@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:29:41 by irrevuel          #+#    #+#             */
/*   Updated: 2024/09/16 19:32:50 by irrevuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*s_cast;

	s_cast = (char *)s;
	i = 0;
	while (i < n)
	{
		if (s_cast[i] == (char)c)
			return (&s_cast[i]);
		i++;
	}
	return (NULL);
}
//ver si retorno s_cast o s? (en &s_cast[i])
// tienen que ser unsigned char?
// no se si estoy tratatndo bien los tipos void de los array
