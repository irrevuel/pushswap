/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irrevuel <irrevuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:45:25 by irrevuel          #+#    #+#             */
/*   Updated: 2024/09/24 18:00:29 by irrevuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*sol;

	sol = 0;
	if (s1 != 0 && set != 0)
	{
		start = 0;
		end = ft_strlen(s1);
		while (s1[start] && ft_strchr(set, s1[start]))
			start++;
		while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > start)
			end--;
		sol = (char *)malloc(sizeof(char) * (end - start + 1));
		if (!sol)
			return (NULL);
		ft_strlcpy(sol, &s1[start], end - start + 1);
	}
	return (sol);
}
/*
int	main(void)
{
	printf("%s", ft_strtrim("cccccholacc", "abcde"));
	return (0);
}*/