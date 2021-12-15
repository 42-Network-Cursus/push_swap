/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwastche </var/mail/cwastche>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:20:16 by cwastche          #+#    #+#             */
/*   Updated: 2021/12/12 16:20:17 by cwastche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	ft_rev_rotate(t_list **stack)
{
	t_list	*tmp;

	if (!(*stack) || !(*stack)->next)
		return (1);
	tmp = ft_lstlast(*stack);
	tmp->next = *stack;
	while ((*stack)->next != tmp)
		*stack = (*stack)->next;
	(*stack)->next = NULL;
	*stack = tmp;
	return (0);
}

int	rra(t_list **a)
{
	if (ft_rev_rotate(a))
		return (1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_list **b)
{
	if (ft_rev_rotate(b))
		return (1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_list **a, t_list **b)
{
	if ((ft_lstsize(*a) < 2) || (ft_lstsize(*b) < 2))
		return (1);
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
