/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 12:05:48 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/03/07 12:05:49 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

inline void	pusha(t_list *a, t_list *b)
{
	if (b->next != b)
	{
		dlstaddafter(a, b->next->nb, b->next->rnk);
		dlstrmfirstelem(b);
	}
}

inline void	pushb(t_list *a, t_list *b)
{
	if (a->next != a)
	{
		dlstaddafter(b, a->next->nb, a->next->rnk);
		dlstrmfirstelem(a);
	}
}
