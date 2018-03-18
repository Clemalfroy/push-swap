/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 12:28:59 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/03/08 12:29:00 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int 		main(int argc, char **argv)
{
	t_list		*a;
	t_list		*b;
	t_stacks	lsta;
	t_stacks	lstb;

	if (argc == 1)
		return (0);
	a = dlstctor();
	b = dlstctor();
	if (!(getlist(argc, argv, a)))
	{
		freeall(a, b);
		return (ft_retf(NOP, "Error\n"));
	}
	ft_memset(&lsta, 0, sizeof(t_stacks));
	ft_memset(&lstb, 0, sizeof(t_stacks));
	lsta.lst = a;
	lstb.lst = b;
	lsta.nbr =  argc - 1;
	sort(&lsta, &lstb );
	freeall(a, b);
	return (0);
}
