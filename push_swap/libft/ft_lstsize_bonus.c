/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irrevuel <irrevuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:38:59 by irrevuel          #+#    #+#             */
/*   Updated: 2024/09/21 11:39:12 by irrevuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

/*
int	main(void)
{
	t_list *head = ft_lstnew("Nodo 1");
	t_list *second = ft_lstnew("Nodo 2");
	t_list *third = ft_lstnew("Nodo 3");

	head->next = second;
	second->next = third;

	int size = ft_lstsize(head);
	printf("El tamaño de la lista es: %d\n", size);

	return (0);
}*/
