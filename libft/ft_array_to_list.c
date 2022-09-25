/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:52:24 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/25 19:15:20 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_array_to_list(int *array, int size, t_node *ptr)
{
	int	i;

	i = 0;
	ptr = NULL;
	while (i < size - 1)
	{
		ft_lstadd_back_int(&ptr, ft_lstnew_int(array[i]));
		free(ptr);
		i++;
	}
}
