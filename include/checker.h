/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:44:59 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/03/01 11:09:19 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define  CHECKER_H

# include <stdint.h>
# include <sys/types.h>
# include <limits.h>
# include <unistd.h>
# include <libft.h>

# define TRUE 1
# define FALSE 0

typedef struct	s_list t_list;
typedef struct	s_sort t_sort;

typedef void	(funcsort)(t_list *a, t_list *b);

struct s_list
{
	int 		nb;
	t_list		*next;
	t_list		*prev;
};

struct s_sort
{
	char		*sort;
	funcsort	*func;
};

t_list			*dlstctor(void);
inline void 	dlstrm(t_list *lst);
inline void		dlstrmfirstelem(t_list *racine);
extern void		dlstaddbefore(t_list *element, int nb);
extern void		dlstaddafter(t_list *element, int nb);

extern int 		getlist(int ac, char **av, t_list *a);
extern int 		getactions(t_list *a, t_list *b);

#endif
