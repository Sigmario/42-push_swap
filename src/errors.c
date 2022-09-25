/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:47:34 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/23 21:30:42 by julmuntz         ###   ########.fr       */
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

int	get_values(int arc, char **arv)
{
	int	i;
	int	*tab;

	i = 0;
	tab = (int *)malloc((arc - 1) * sizeof(int));
	if (arc > 1)
	{
		i = 0;
		while (i < arc - 1)
		{
			tab[i] = ft_atoi(arv[i + 1]);
			if (invalid_data(arv[i + 1], tab[i]) == TRUE)
				return (ft_printf("Error\n"), 0);
			i++;
		}
		ft_array_to_list(tab, arc);
	}
	return (0);
}
