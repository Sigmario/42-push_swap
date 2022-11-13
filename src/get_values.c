/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:47:34 by julmuntz          #+#    #+#             */
/*   Updated: 2022/10/03 20:42:56 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	array_to_list(int *array, int size, t_stack **ptr)
{
	int	i;

	i = 0;
	if (ft_nbrcmp(array, size + 1) == TRUE)
		return (ft_printf("Error\n"), free(array),
			stackclear(ptr), exit(EXIT_FAILURE), 0);
	while (i < size)
	{
		stackadd_back(ptr, stacknew(array[i]));
		i++;
	}
	if (!(*ptr)->next)
		return (free(array), stackclear(ptr), exit(EXIT_FAILURE), 0);
	return (0);
}

static int	invalid_values(char *str, int nbr)
{
	int	i;

	i = 0;
	if ((ft_strlen(str) > 10 && str[0] != '-') || (ft_strlen(str) > 11
			&& str[0] == '-') || (str[0] == 0) || (str[0] == '+'
			&& str[1] == 0))
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

t_stack	*get_values(int size, char **arv)
{
	int		i;
	t_stack	*node;
	int		*array;

	i = 0;
	node = NULL;
	array = (int *)malloc((size) * sizeof(int));
	if (!array)
		return (ft_printf("Error\n"), free(array), NULL);
	if (size > 0)
	{
		while (i < size)
		{
			array[i] = ft_atoi(arv[i + 1]);
			if (invalid_values(arv[i + 1], array[i]) == TRUE)
				return (ft_printf("Error\n"),
					free(array), exit(EXIT_FAILURE), NULL);
			i++;
		}
		array_to_list(array, size, &node);
	}
	free(array);
	return (node);
}

int	sorted(t_stack **ptr)
{
	t_stack	*node;
	t_stack	*tmp;

	node = *ptr;
	while (node->next)
	{
		tmp = node->next;
		if (node->value > tmp->value)
			return (FALSE);
		node = tmp;
	}
	stackclear(ptr);
	return (TRUE);
}
