/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:29:06 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/29 16:12:30 by julmuntz         ###   ########.fr       */
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
		array_to_list(&data, &ptr, arc);
		puts("");
		display_stack(ptr);
		puts("");
		ft_printf("%d\n", number_of_elements(ptr));
	}
	return (0);
}
