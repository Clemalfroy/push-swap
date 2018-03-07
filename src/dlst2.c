/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 12:37:19 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/03/07 12:37:24 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	clear_dlist(t_list *lst)
{
	t_list *next;
	t_list *current;

	current = lst->next;
	while (current != lst)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void		dlstdtor(t_list **lst)
{
	clear_dlist(*lst);
	free(*lst);
	*lst = NULL;
}
