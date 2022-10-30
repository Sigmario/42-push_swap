/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:13:27 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/30 04:04:08 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpy(t_list *lst)
{
	t_list	*current;

	if (lst == NULL)
		return (0);
	current = (t_list *)malloc(sizeof(t_list));
	current->content = lst->content;
	current->next = ft_lstcpy(lst->content);
	return (current);
}

t_stack	*stackcopy(t_stack *node)
{
	t_stack	*current;

	if (node == NULL)
		return (0);
	current = (t_stack *)malloc(sizeof(t_stack));
	current->value = node->value;
	current->next = stackcopy(node->next);
	return (current);
}
