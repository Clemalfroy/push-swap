/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 12:22:47 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/03/07 12:22:49 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

inline void	rrotatea(t_list *a, t_list *b)
{
	(void)b;
	if (a->prev != a)
	{
		dlstaddafter(a, a->prev->nb);
		dlstrm(a->prev);
	}
}

inline void	rrotateb(t_list *a, t_list *b)
{
	(void)a;
	if (b->prev != b)
	{
		dlstaddafter(b, b->prev->nb);
		dlstrm(b->prev);
	}
}

inline void	rrotateab(t_list *a, t_list *b)
{
	rrotatea(a, b);
	rrotateb(a, b);
}
