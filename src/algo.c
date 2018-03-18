/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:00:17 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/03/08 18:00:19 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void			tinysort(t_stacks *a, t_stacks *b)
{
	int 	first;
	int 	second;
	int 	third;

	if (dlstissort(a->lst, b->lst, 1))
		return ;
	first = a->lst->next->nb;
	second = a->lst->next->next->nb;
	third = a->lst->next->next->next->nb;
	if (first > second && second < third && first < third)
		getaction("sa", a, b, swapa);
	else if (first < second && third < first)
		getaction("rra", a, b, rrotatea);
	else if (first > second && second < third)
		getaction("ra", a, b, rotatea);
	else if (first > second && second > third)
		getaction("sa", a, b, swapa);
	else if (first > second && second < third)
		getaction("rra", a, b, rrotatea);
	else if (first < second && second > third && first < third)
		getaction("rra", a, b, rrotatea);
	tinysort(a, b);
}

void			selectionsort(t_stacks *a, t_stacks *b)
{
	t_list	*cpy;
	int		i;

	if (dlstissort(a->lst, b->lst, 0))
		return ;
	if (dlstissort(a->lst, b->lst, 1))
		getaction("pa", a, b, pusha);
	else if (a->nbr == 3)
		tinysort(a, b);
	else
	{
		i = 0;
		cpy = a->lst->next;
		findextremum(a->lst, a);
		while (++i && cpy->next->nb != a->min)
			cpy = cpy->next;
		a->lst->next->next->nb == a->min ? getaction("sa", a, b, swapa) : 0;
		while (a->lst->next->nb != a->min)
			i <= a->nbr / 2 ? getaction("ra", a, b, rotatea) :
			getaction("rra", a, b, rrotatea);
		getaction("pb", a, b, pushb);
	}
	selectionsort(a, b);
}

void			sort(t_stacks *lsta, t_stacks *lstb)
{
	if (!dlstissort(lsta->lst, lstb->lst, 0))
	{
		if (lsta->nbr == 2)
			lsta->lst->next->nb > lsta->lst->next->next->nb ?
			getaction("sa", lsta, lstb, swapa) : 0;
		else if (lsta->nbr == 3)
			tinysort(lsta, lstb);
		else if (lsta->nbr < 4500)
			selectionsort(lsta, lstb);
	}
}