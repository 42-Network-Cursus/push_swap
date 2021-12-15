/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwastche </var/mail/cwastche>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:20:26 by cwastche          #+#    #+#             */
/*   Updated: 2021/12/12 16:20:27 by cwastche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	ft_rotate(t_list **stack)
{
	t_list	*tmp;

	if (!(*stack) || !(*stack)->next)
		return (1);
	tmp = ft_lstlast(*stack);
	tmp->next = *stack;
	tmp = (*stack)->next;
	(*stack)->next = NULL;
	*stack = tmp;
	return (0);
}

int	ra(t_list **a)
{
	if (ft_rotate(a))
		return (1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_list **b)
{
	if (ft_rotate(b))
		return (1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rr(t_list **a, t_list **b)
{
	if ((ft_lstsize(*a) < 2) || (ft_lstsize(*b) < 2))
		return (1);
	ft_rotate(a);
	ft_rotate(b);
	ft_putendl_fd("rr", 1);
	return (0);
}
