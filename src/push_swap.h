/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:49:26 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/29 16:43:23 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/*			INITIALIZATION:												  */
t_stack		*get_values(int size, char **arv);
void		get_index(t_stack *node, int size);
void		display_list(t_stack *node);

/*			INFORMATIONS:												  */
int			min_value_pos(t_stack **ptr);

/*			OPERATIONS:													  */
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);

/*			LIBFT RELATED:												  */
void		stackadd_back(t_stack **ptr, t_stack *new);
void		stackadd_front(t_stack **ptr, t_stack *new);
void		stackclear(t_stack **ptr, void (*d)(int));
void		stackdelone(t_stack *node, void (*d)(int));
void		stackiter(t_stack *node, void (*f)(int));
t_stack		*stacklast(t_stack *node);
t_stack		*stackmap(t_stack *node, int (*f)(int), void (*d)(int));
t_stack		*stacknew(int value);
void		stackdisplay(t_stack *node);
int			stacksize(t_stack *node);

#endif