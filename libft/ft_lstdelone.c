/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 22:20:20 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/27 10:50:40 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*d)(void *))
{
	d(lst->content);
	free(lst);
}

void	stackdelone(t_stack *node, void (*d)(int))
{
	d(node->value);
	free(node);
}

void	ft_lstdelnode(t_list *lst)
{
	t_list	*temp;

	if (lst)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
}

void	stackdelnode(t_stack **node)
{
	t_stack	*top;

	if (node)
	{
		top = *node;
		top = top->next;
		free(*node);
	}
}
