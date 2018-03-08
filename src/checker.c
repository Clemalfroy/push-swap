/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:33:29 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/02/26 13:33:32 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#define BUF_SIZE 4

static void	initsort(t_sort *sort)
{
	sort[0] = (t_sort){ "sa", swapa };
	sort[1] = (t_sort){ "sb", swapb };
	sort[2] = (t_sort){ "ss", swapab };
	sort[3] = (t_sort){ "pa", pusha };
	sort[4] = (t_sort){ "pb", pushb };
	sort[5] = (t_sort){ "ra", rotatea };
	sort[6] = (t_sort){ "rb", rotateb };
	sort[7] = (t_sort){ "rr", rotateab };
	sort[8] = (t_sort){ "rra", rrotatea };
	sort[9] = (t_sort){ "rrb", rrotateb };
	sort[10] = (t_sort){ "rrr", rrotateab };
	sort[11] = (t_sort){ NULL, NULL };
}

static int	getactions(t_list *a, t_list *b)
{
	char	buf[BUF_SIZE];
	ssize_t	rd;
	ssize_t	i;
	t_sort	sort[12];

	initsort(sort);
	while ((rd = read(STDIN_FILENO, buf, BUF_SIZE)) > 0)
	{
		buf[rd - 1] = '\0';
		i = -1;
		while (sort[++i].sort != NULL)
			if (!ft_strcmp(sort[i].sort, buf))
			{
				sort[i].func(a, b);
				break ;
			}
		if (i == 11)
			return (FALSE);
	}
	return (TRUE);
}

static int	dlstissort(t_list *a, t_list *b)
{
	t_list *cpa;

	if (b->next != b)
		return (FALSE);
	cpa = a->next;
	while (cpa->next != a)
	{
		if (cpa->nb > cpa->next->nb)
			return (FALSE);
		cpa = cpa->next;
	}
	return (TRUE);
}

int			main(int argc, char **argv)
{
	t_list *a;
	t_list *b;

	a = dlstctor();
	b = dlstctor();
	if (argc == 1 || !getlist(argc, argv, a) || !getactions(a, b))
	{
		freeall(a, b);
		return (ft_retf(NOP, "Error\n"));
	}
	if (dlstissort(a, b))
		ft_putl(1, "OK");
	else
		ft_putl(1, "KO");
	freeall(a, b);
	return (YEP);
}
