/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 12:22:47 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/03/07 12:22:49 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

inline void	rotatea(t_list *a, t_list *b)
{
	(void)b;
	if (a->next != a)
	{
		dlstaddbefore(a, a->next->nb);
		dlstrm(a->next);
	}
}

inline void	rotateb(t_list *a, t_list *b)
{
	(void)a;
	if (b->next != b)
	{
		dlstaddbefore(b, b->next->nb);
		dlstrm(b->next);
	}
}

inline void	rotateab(t_list *a, t_list *b)
{
	rotatea(a, b);
	rotateb(a, b);
}
