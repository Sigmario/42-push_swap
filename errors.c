/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:47:34 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/21 14:13:19 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_invalid_input(char *str)
{
	int	i;
	int	nbr;

	i = 0;
	if (str[0] == '+' && str[1] == 0)
		return (TRUE);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == FALSE)
			return (TRUE);
		i++;
	}
	nbr = ft_atoi(str);
	if ((unsigned)nbr > 2147483647 && str[0] != '-')
		return (TRUE);
	if ((unsigned)nbr < 2147483648 && str[0] == '-')
		return (TRUE);
	return (0);
}
