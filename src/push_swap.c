/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:29:06 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/29 15:05:36 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int arc, char **arv)
{
	t_data	data;
	t_stack	*ptr;

	ptr = NULL;
	if (arc > 1)
	{
		get_values(&data, arv, arc);
		array_to_list(data.array, arc, &ptr);
		puts("");
		printf("\tUNSORTED:");
		puts("");
		print_list(ptr);
		puts("\n");
		ptr = NULL;
		array_to_list(ft_sort_int_tab(data.array, arc), arc, &ptr);
		printf("\tSORTED:");
		puts("");
		print_list(ptr);
		puts("\n");
	}
	return (0);
}
