/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:29:06 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/21 16:00:54 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int arc, char **arv)
{
	int i;
	int nbr;

	if (arc > 1)
	{
		i = 1;
		while (arv[i])
		{
			nbr = ft_atoi(arv[i]);
			if (ps_invalid_input(arv[i], nbr) == TRUE)
				return (ft_printf("Error\n"), 0);
			i++;
		}
		i = 1;
		while (arv[i])
		{
			nbr = ft_atoi(arv[i]);
			ft_printf("%d\n", nbr);
			i++;
		}
	}
	return (0);
}
