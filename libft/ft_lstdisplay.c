/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdisplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:57:37 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/08 23:38:59 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdisplay(t_list *lst)
{
	while (lst)
	{
		ft_putendl(lst->content);
		lst = lst->next;
	}
	if (!lst)
		return ;
}

void	stackdisplay(t_stack *a, t_stack *b)
{
	while (a || b)
	{
		if (!a)
			ft_puttabs("", 2);
		else if (a)
		{
			if ((ft_nbrlen(a->value) > 7) || (a->value == INT_MIN))
				ft_puttabs(ft_itoa(a->value), 1);
			else
				ft_puttabs(ft_itoa(a->value), 2);
			a = a->next;
		}
		if (b)
		{
			ft_printf("%d", (b->value));
			b = b->next;
		}
		ft_putendl("");
	}
}
