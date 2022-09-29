/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:47:34 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/29 14:26:58 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	invalid_number(char *str, int nbr)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 10 && str[0] != '-')
		return (TRUE);
	if (ft_strlen(str) > 11 && str[0] == '-')
		return (TRUE);
	if (str[0] == 0)
		return (TRUE);
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
	if ((unsigned long)nbr > INT_MAX && str[0] != '-')
		return (TRUE);
	if ((unsigned long)nbr <= INT_MAX && str[0] == '-')
		return (TRUE);
	return (0);
}

int	get_values(t_data *data, char **arg, int size)
{
	int		i;
	int		*array;

	i = 0;
	array = (int *)malloc((size - 1) * sizeof(int));
	if (size > 1)
	{
		while (i < size - 1)
		{
			array[i] = ft_atoi(arg[i + 1]);
			if (invalid_number(arg[i + 1], array[i]) == TRUE)
				return (ft_printf("Error\n"), 0);
			i++;
		}
		data->array = array;
	}
	return (0);
}
