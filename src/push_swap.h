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

# define TOP 111
# define BOTTOM 112

typedef struct s_stack
{
	struct s_stack	*a;
	struct s_stack	*b;
	int				value;
	int				index;
	int				pos;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data_a
{
	int				chunk;
	int				quarter;
	int				value;
	int				index;
	int				pos;
}	t_data_a;

typedef struct s_data_b
{
	int				size;
	int				value;
	int				index;
	int				pos;
}	t_data_b;

/*			INITIALIZATION													  */
t_stack		*get_values(int size, char **arv);
int			sorted(t_stack **ptr);
void		get_pos(t_stack **ptr);
void		get_index(t_stack **ptr, int size);
int			min_value_pos(t_stack **ptr);
int			max_value_pos(t_stack **ptr);

/*			SORT															  */
void		checks(t_stack **a, t_stack **b);
int			sort_three(t_stack **a);
int			sort_four(t_stack **a, t_stack **b, int index);
int			sort_five(t_stack **a, t_stack **b);
void		get_chunks(t_stack **a, t_stack **b);
void		sort_hundred(t_stack **a, t_stack **b);

/*			OPERATIONS														  */
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

/*			LIBFT RELATED													  */
void		stackadd_back(t_stack **ptr, t_stack *new);
void		stackadd_front(t_stack **ptr, t_stack *new);
void		stackclear(t_stack **ptr, void (*d)(int));
void		stackdelnode(t_stack **node);
void		stackdelone(t_stack *node, void (*d)(int));
void		stackdisplay(t_stack *a, t_stack *b);
void		stackiter(t_stack *node, void (*f)(int));
t_stack		*stacklast(t_stack *node);
t_stack		*stackmap(t_stack *node, int (*f)(int), void (*d)(int));
t_stack		*stacknew(int value);
int			stackpop(t_stack **ptr);
void		stackpop_last(t_stack **ptr);
void		stackrev(t_stack **ptr);
int			stacksize(t_stack *node);

#endif