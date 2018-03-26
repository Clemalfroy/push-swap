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

int 			computecost(t_stacks *a, t_stacks *b, int *cpta, int *cptb)
{
	t_list		*cpya;
	t_list		*cpyb;
	int 		cost;
	int 		i;
	int			j;
	int 		value;

	i = 0;
	cpya = a->lst->next;
	cost = INT_MAX;
	value = 0;
	while ((i += 1) && cpya != a->lst && !(j = 0))
	{
		cpyb = b->lst->next;
		while ((j += 1) && cpyb->nb > cpya->nb)
			cpyb = cpyb->next;
		if (((i < a->nbr - i ? i : a->nbr - i) + (j < b->nbr - j ? j : b->nbr - j)) < cost)
		{
			cost = (i < a->nbr - i ? i : a->nbr - i) + (j < b->nbr - j ? j : b->nbr - j);
			*cpta = i;
			*cptb = j;
			value = cpya->nb;
		}
		cpya = cpya->next;
	}
	return (value);
}

void			costsort(t_stacks *a, t_stacks *b)
{
	int 		tomove;
	int 		i;
	int 		j;

	if (dlstissort(a->lst, b->lst, 0))
		return ;
	tomove = computecost(a, b, &i, &j);
	findextremum(b->lst, b);
	while (a->lst->next->nb != tomove)
		i <= a->nbr / 2 ? getaction("ra", a, b, rotatea) :
		getaction("rra", a, b, rrotatea);
	while (42)
	{
		if (b->lst->prev->nb > tomove && b->lst->next->nb < tomove)
			break;
		if (tomove > b->max && b->lst->next->nb == b->max)
			break;
		if (tomove < b->min && b->lst->prev->nb == b->min)
			break;
		j <= b->nbr / 2 ? getaction("rb", a, b, rotateb) :
		getaction("rrb", a, b, rrotateb);
	}
	getaction("pb", a, b, pushb);
	if (a->nbr < 1)
	{
		while (b->lst->next->nb != b->max)
			getaction("rb", a, b, rotateb);
		selectionsort(a, b);
	}
	costsort(a, b);
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
		else if (lsta->nbr <= 45)
			selectionsort(lsta, lstb);
		else
			costsort(lsta, lstb);
	}
}