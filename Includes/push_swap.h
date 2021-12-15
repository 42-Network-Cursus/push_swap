/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwastche </var/mail/cwastche>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:09:02 by cwastche          #+#    #+#             */
/*   Updated: 2021/12/12 16:09:30 by cwastche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

//	Check for errors
int		ft_args_check(int argc, char **argv);
int		ft_isnum(char *arg);
int		ft_find_dupl(int nb, char **argv, int i);
int		ft_minmaxint(char *arg);

//	Stack initializer
int		ft_init_stack(char **args, t_list **st_a);
t_list	*ft_lstnew_ps(int nb);
void	ft_init_index(t_list **st_a);
t_list	*find_minval(t_list *head);

//	Operations
int		ft_swap(t_list **stack);
int		sa(t_list **st_a);
int		sb(t_list **st_b);
int		ss(t_list **st_a, t_list **st_b);

int		ft_push(t_list **src, t_list **dest);
int		pa(t_list **st_a, t_list **st_b);
int		pb(t_list **st_a, t_list **st_b);

int		ft_rotate(t_list **stack);
int		ra(t_list **st_a);
int		rb(t_list **st_b);
int		rr(t_list **st_a, t_list **st_b);

int		ft_rev_rotate(t_list **stack);
int		rra(t_list **st_a);
int		rrb(t_list **st_b);
int		rrr(t_list **st_a, t_list **st_b);

//	Algorithm
void	sort_radix(t_list **st_a, t_list **st_b);
void	sort_3(t_list **a);
void	sort_4(t_list **a, t_list **b);
void	sort_5(t_list **a, t_list **b);
void	sort_tree(t_list **a, t_list **b);

//	Utils
int		is_sorted(t_list *a, t_list *b);
int		find_min(t_list	*a);
int		ft_free_all(t_list **a, t_list **b);

#endif
