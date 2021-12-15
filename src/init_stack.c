/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwastche </var/mail/cwastche>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:21:14 by cwastche          #+#    #+#             */
/*   Updated: 2021/12/12 16:21:16 by cwastche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	ft_init_stack(char **args, t_list **a)
{
	t_list	*tmp;
	int		i;

	i = 1;
	while (args[i])
	{
		tmp = ft_lstnew_ps(ft_atoi(args[i]));
		if (!tmp)
			return (1);
		ft_lstadd_back(a, tmp);
		i++;
	}
	ft_init_index(a);
	return (0);
}

t_list	*ft_lstnew_ps(int nb)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->value = nb;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	ft_init_index(t_list **a)
{	
	t_list	*min;
	int		ind;

	ind = 0;
	min = find_minval(*a);
	while (min)
	{
		min->index = ind++;
		min = find_minval(*a);
	}
	return ;
}

t_list	*find_minval(t_list *head)
{
	t_list	*min;
	int		stop;

	stop = 1;
	min = head;
	while (head)
	{
		if (head->value < min->value && head->index == -1)
		{
			min = head;
			stop = 0;
		}
		head = head->next;
		if (min->index != -1)
		{
			min = head;
			stop = 0;
		}
	}
	if (stop && min->index != -1)
		return (NULL);
	return (min);
}
