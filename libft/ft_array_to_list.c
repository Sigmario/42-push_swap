/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:52:24 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/25 16:46:21 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_array_to_list(int *array, int size)
{
	int	i;
	t_node *ptr;

	i = 0;
	ptr = NULL;
	ptr->value = array[i];
	while (i < size - 1)
	{
		ft_lstadd_back_int(&ptr, ft_lstnew_int(ptr->value));
		i++;
	}
	ft_printf("%d\n", ptr->value);
}
