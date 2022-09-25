/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:47:34 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/25 19:24:59 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	invalid_data(char *str, int nbr)
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

int	get_values(char **str, int size, t_node **ptr)
{
	int	i;
	int	*arr;

	i = 0;
	arr = (int *)malloc((size - 1) * sizeof(int));
	if (size > 1)
	{
		i = 0;
		while (i < size - 1)
		{
			arr[i] = ft_atoi(str[i + 1]);
			if (invalid_data(str[i + 1], arr[i]) == TRUE)
				return (ft_printf("Error\n"), 0);
			i++;
		}
		ft_array_to_list(arr, size, *ptr);
		free(arr);
	}
	return (0);
}
