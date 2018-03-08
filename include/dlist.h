/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:56:10 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/03/08 11:56:12 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLIST_H
# define DLIST_H

# include <libft.h>

typedef struct s_list	t_list;

struct			s_list
{
	int			nb;
	t_list		*next;
	t_list		*prev;
};

t_list			*dlstctor(void);
extern void		dlstrm(t_list *lst);
extern void		dlstrmfirstelem(t_list *racine);
extern void		dlstaddbefore(t_list *element, int nb);
extern void		dlstaddafter(t_list *element, int nb);
void			dlstdtor(t_list **lst);

#endif
