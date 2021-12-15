/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwastche </var/mail/cwastche>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:20:08 by cwastche          #+#    #+#             */
/*   Updated: 2021/12/12 16:20:09 by cwastche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	ft_push(t_list **dest, t_list **src)
{
	t_list	*tmp;

	if (!(*src))
		return (1);
	tmp = *src;
	*src = (*src)->next;
	ft_lstadd_front(dest, tmp);
	return (0);
}

int	pa(t_list **a, t_list **b)
{
	if (ft_push(a, b) == 1)
		return (1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_list **a, t_list **b)
{
	if (ft_push(b, a))
		return (1);
	ft_putendl_fd("pb", 1);
	return (0);
}
