/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:52:24 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/22 19:29:44 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_array_to_list(int *array, int size)
{
	struct t_node	*head;
	struct t_node	*tmp1;
	struct t_node	*tmp2;
	int				i;

	tmp1 = malloc(sizeof(struct t_node));
	tmp1->value = array[0];
	tmp1->next = NULL;
	head = tmp1;
	i = 1;
	while (i < size - 1)
	{
		tmp2 = malloc(sizeof(struct t_node));
		tmp1->next = tmp2;
		tmp2->value = array[i];
		tmp2->next = NULL;
		tmp1 = tmp2;
		i++;
	}
	tmp1 = head;
	while (tmp1 != NULL)
	{
		ft_printf("%d\n", tmp1->value);
		tmp1 = tmp1->next;
	}
}
