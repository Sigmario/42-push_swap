/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:03:21 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/24 12:15:04 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpy(t_list *node)
{
	t_list *current;
	t_list *new;
	t_list *last;

	current = node;
	new = NULL;
	last = NULL;
	while (current)
	{
		if (!new)
		{
			new = (t_list *)malloc(sizeof(t_list));
			new->content = current->content;
			new->next = NULL;
			last = new;
		}
		else
		{
			last->next = (t_list *)malloc(sizeof(t_list));
			last = last->next;
			last->content = current->content;
			last->next = NULL;
		}
		current = current->next;
	}
	return (new);
}

t_stack	*stackcopy(t_stack *node)
{
	t_stack *current;
	t_stack *new;
	t_stack *last;

	current = node;
	new = NULL;
	last = NULL;
	while (current)
	{
		if (!new)
		{
			new = (t_stack *)malloc(sizeof(t_stack));
			new->value = current->value;
			new->next = NULL;
			last = new;
		}
		else
		{
			last->next = (t_stack *)malloc(sizeof(t_stack));
			last = last->next;
			last->value = current->value;
			last->next = NULL;
		}
		current = current->next;
	}
	return (new);
}
