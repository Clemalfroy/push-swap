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

#include "dlist.h"
#include "actions.h"

# define TRUE 1
# define FALSE 0

typedef struct	s_sort t_sort;

typedef void	(funcsort)(t_list *a, t_list *b);

struct s_sort
{
	char		*sort;
	funcsort	*func;
};

void			freeall(t_list *a, t_list *b);
extern int 		getlist(int ac, char **av, t_list *a);

#endif
