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

# define TOP 11
# define BOTTOM 22

typedef struct s_stack
{
	struct s_stack	*a;
	struct s_stack	*b;
	int				pos;
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	int				pos;
	int				size;
	int				value;
	int				index;
	int				chunk;
	int				quarter;
	int				max_pos;
	int				second_max_pos;
	int				bool;
}	t_data;

////////////////////////////////////////////////////////////////
/////////////  D  A  T  A  /////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
t_stack		*get_values(int size, char **arv);
void		get_pos(t_stack **ptr);
void		get_index(t_stack **ptr, int size);
int			sorted(t_stack **ptr);
int			min_value_pos(t_stack **ptr);
int			max_value_pos(t_stack **ptr);
int			second_max_value_pos(t_stack **ptr);

////////////////////////////////////////////////////////////////
/////////////  S O R T I N G  //////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int			sort_two(t_stack **a);
int			sort_three(t_stack **a);
int			sort_four(t_stack **a, t_stack **b, int index);
int			sort_five(t_stack **a, t_stack **b);
void		sort_beyond(t_stack **a, t_stack **b);

////////////////////////////////////////////////////////////////
/////////////  O P E R A T I O N S  ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////
/////////////  S T A C K   F U N C T I O N S  //////////////////////////
////////////////////////////////////////////////////////////////////////////////
void		stackadd_back(t_stack **ptr, t_stack *new);
void		stackadd_front(t_stack **ptr, t_stack *new);
t_stack		*stackcopy(t_stack *node);
void		stackdisplay(t_stack *a, t_stack *b);
t_stack		*stacklast(t_stack *node);
t_stack		*stacknew(int value);
int			stackpop(t_stack **ptr);
void		stackpop_last(t_stack **ptr);
void		stackrev(t_stack *node);
int			stacksize(t_stack *node);

#endif