/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 11:59:53 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/03/07 11:59:55 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

inline void	swapa(t_list *a, t_list *b)
{
	int tmp;

	(void)b;
	if (a->next->next != a)
	{
		tmp = a->next->nb;
		a->next->nb = a->next->next->nb;
		a->next->next->nb = tmp;
	}
}

inline void	swapb(t_list *a, t_list *b)
{
	int tmp;

	(void)a;
	if (b->next->next != b)
	{
		tmp = b->next->nb;
		b->next->nb = b->next->next->nb;
		b->next->next->nb = tmp;
	}
}

inline void	swapab(t_list *a, t_list *b)
{
	swapa(a, b);
	swapb(a, b);
}
