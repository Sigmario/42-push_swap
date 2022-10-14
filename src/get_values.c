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
	if (ft_nbrcmp(array, size) == TRUE)
		return (ft_printf("Error\n"), exit(EXIT_SUCCESS), 0);
	while (i < size - 1)
	{
		stackadd_back(ptr, stacknew(array[i]));
		i++;
	}
	if (!(*ptr)->next)
		return (0);
	if ((*ptr)->value > (*ptr)->next->value && !(*ptr)->next->next)
		return (sa(ptr), ft_printf("sa\n"), 0);
	return (0);
}

static int	invalid_number(char *str, int nbr)
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
	array = (int *)malloc((size - 1) * sizeof(int));
	if (size > 1)
	{
		while (i < size - 1)
		{
			array[i] = ft_atoi(arv[i + 1]);
			if (invalid_number(arv[i + 1], array[i]) == TRUE)
			{
				ft_printf("Error\n");
				exit(EXIT_SUCCESS);
				return (NULL);
			}
			i++;
		}
		array_to_list(array, size, &node);
	}
	return (node);
}

int	sorted(t_stack **ptr)
{
	t_stack	*node;

	node = *ptr;
	while (node)
	{
		if (node->pos != node->index)
			return (FALSE);
		node = node->next;
	}
	return (TRUE);
}
