/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:13:27 by julmuntz          #+#    #+#             */
/*   Updated: 2022/11/09 05:58:38 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpy(t_list *lst)
{
	t_list	*current;

	if (lst == NULL)
		return (NULL);
	else
	{
		current = (t_list *)malloc(sizeof(t_list));
		current->content = lst->content;
		current->next = ft_lstcpy(lst->next);
		return (current);
	}
}

t_stack	*stackcopy(t_stack *node)
{
	t_stack *current;

	if (node == NULL)
		return (NULL);
	else
	{
		current = (t_stack *)malloc(sizeof(t_stack));
		current->value = node->value;
		current->index = node->index;
		current->next = stackcopy(node->next);
		return (current);
	}
}
