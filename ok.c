/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:47:34 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/21 13:04:57 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_print(char *p_arg)
{
	int	i;
	int	nbr;

	i = 0;
	if (p_arg[0] == '-' || p_arg[0] == '+')
		i++;
	while (p_arg[i])
	{
		if (ft_isdigit(p_arg[i]) == FALSE)
			return (ft_printf("Error\n"), 0);
		i++;
	}
	nbr = ft_atoi(p_arg);
	if ((unsigned)nbr > 2147483647 && p_arg[0] != '-')
		return (ft_printf("Error\n"), 0);
	if ((unsigned)nbr < 2147483648 && p_arg[0] == '-')
		return (ft_printf("Error\n"), 0);
	else
		ft_printf("%d\n", nbr);
	return (0);
}
