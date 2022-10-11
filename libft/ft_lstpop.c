/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:32:02 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/11 15:23:41 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstpop(t_list **lst)
{
	t_list	*next_node;
	void	*retvalue;

	next_node = NULL;
	retvalue = NULL;
	if (*lst == NULL)
		return (NULL);
	next_node = (*lst)->next;
	retvalue = (*lst)->content;
	free(*lst);
	*lst = next_node;
	return (retvalue);
}

int	stackpop(t_stack **ptr)
{
	t_stack	*next_node;
	int		retvalue;

	next_node = NULL;
	retvalue = 0;
	if (*ptr == NULL)
		return (0);
	next_node = (*ptr)->next;
	retvalue = (*ptr)->value;
	free(*ptr);
	*ptr = next_node;
	return (retvalue);
}

void	stackpop_last(t_stack **ptr)
{
	t_stack	*node;

	node = *ptr;
	while (node->next->next != NULL)
		node = node->next;
	node->next = NULL;
	free(node->next);
}
