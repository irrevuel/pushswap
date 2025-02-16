/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpastor- <lpastor-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:27:24 by irrevuel          #+#    #+#             */
/*   Updated: 2024/09/23 18:14:43 by irrevuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*old_last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		old_last = ft_lstlast(*lst);
		old_last->next = new;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	t_list *head = ft_lstnew("Nodo 1");
	t_list *second = ft_lstnew("Nodo 2");
	t_list *third = ft_lstnew("Nodo 3");
	t_list *four = ft_lstnew("Nodo 4");

	head->next = second;
	second->next = third;
	ft_lstadd_back(&head, four);
	t_list *sol = ft_lstlast(head);
	printf("El último nodo es: %s\n", (*sol).content);

	free(head);
	free(second);
	free(third);

	return (0);
}*/
