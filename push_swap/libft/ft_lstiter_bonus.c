/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irrevuel <irrevuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:32:21 by irrevuel          #+#    #+#             */
/*   Updated: 2024/09/21 12:19:26 by irrevuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = ft_lstnew("Nodo 1");
	node2 = ft_lstnew("Nodo 2");
	node3 = ft_lstnew("Nodo 3");
	node1->next = node2;
	node2->next = node3;
	ft_lstiter(node1, print_content);
	free(node1);
	free(node2);
	free(node3);
	return (0);
}
*/