/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:27:40 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/03/07 10:27:43 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list		*dlstctor(void)
{
	t_list *racine;

	racine = malloc(sizeof(t_list) * 1);
	if (racine != NULL)
	{
		ft_memset(racine, 0, sizeof(t_list));
		racine->next = racine;
		racine->prev = racine;
	}
	return (racine);
}

inline void	dlstaddbefore(t_list *element, int nb)
{
	t_list *new_elem;

	if (element)
	{
		new_elem = malloc(sizeof(t_list));
		if (new_elem != NULL)
		{
			ft_memset(new_elem, 0, sizeof(t_list));
			new_elem->nb = nb;
			new_elem->prev = element->prev;
			new_elem->next = element;
			element->prev->next = new_elem;
			element->prev = new_elem;
		}
	}
}

inline void dlstrm(t_list *lst)
{
		lst->prev->next = lst->next;
		lst->next->prev = lst->prev;
		free(lst);
}

inline void	dlstrmfirstelem(t_list *racine)
{
	if (racine->next != racine)
		dlstrm(racine->next);
}

inline void	dlstaddafter(t_list *element, int nb)
{
	t_list *new_elem;

	if (element)
	{
		new_elem = malloc(sizeof(t_list));
		if (new_elem != NULL)
		{
			new_elem->nb = nb;
			new_elem->prev = element;
			new_elem->next = element->next;
			element->next->prev = new_elem;
			element->next = new_elem;
		}
	}
}