/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:39:32 by julmuntz          #+#    #+#             */
/*   Updated: 2022/06/03 18:33:56 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../src/push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new != *lst)
	new->next = *lst;
	*lst = new;
}

void	ps_lstadd_front(t_stack **lst, t_stack *new)
{
	if (new != *lst)
	new->next = *lst;
	*lst = new;
}
