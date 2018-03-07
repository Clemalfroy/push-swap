/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:33:29 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/02/26 13:33:32 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	dlstissort(t_list *a, t_list *b)
{
	t_list *cpa;

	if (b->next != b)
		return (FALSE);
	cpa = a->next;
	while (cpa->next != a)
	{
		if (cpa->nb > cpa->next->nb)
			return (FALSE);
		cpa = cpa->next;
	}
	return (TRUE);
}

static void	freeall(t_list *a, t_list *b)
{
	dlstdtor(&a);
	dlstdtor(&b);
}

int			main(int argc, char **argv)
{
	t_list *a;
	t_list *b;

	a = dlstctor();
	b = dlstctor();
	if (argc == 1 || !getlist(argc, argv, a) || !getactions(a, b))
	{
		freeall(a, b);
		return (ft_retf(NOP, "Error\n"));
	}
	if (dlstissort(a, b))
		ft_putl(1, "OK");
	else
		ft_putl(1, "KO");
	freeall(a, b);
	return (YEP);
}
