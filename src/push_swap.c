/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwastche </var/mail/cwastche>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:22:13 by cwastche          #+#    #+#             */
/*   Updated: 2021/12/12 16:22:16 by cwastche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	if (argc < 2)
		return (1);
	if (ft_args_check(argc, argv))
		return (write(1, "Error\n", 6));
	a = malloc(sizeof(t_list));
	b = malloc(sizeof(t_list));
	if (a == NULL || b == NULL)
		return (ft_free_all(a, b));
	*a = NULL;
	*b = NULL;
	if (ft_init_stack(argv, a))
		return (ft_free_all(a, b));
	if (!(is_sorted(*a, *b)))
		sort_tree(a, b);
	ft_free_all(a, b);
	return (0);
}
