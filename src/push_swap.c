/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:29:06 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/21 19:35:19 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int arc, char **arv)
{
	int i;
	int *arr;

	i = 0;
	arr = (int *)malloc((arc - 1) * sizeof(int));
	if (arc > 1)
	{
		i = 0;
		while (i < arc - 1)
		{
			arr[i] = ft_atoi(arv[i + 1]);
			if (ps_invalid_input(arv[i + 1], arr[i]) == TRUE)
				return (ft_printf("Error\n"), 0);
			i++;
		}
		i = 0;
		while (i < arc - 1)
		{
			ft_printf("%d\n", arr[i]);
			i++;
		}
	}
	return (0);
}
