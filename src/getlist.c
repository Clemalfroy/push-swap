/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:18:13 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/03/01 11:18:17 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

inline int			getlist(int ac, char **av)
{
	int			i;
	int64_t		nb;
	static int 	tab[INT_MAX];
	int 		neg;

	i = 0;
	while (++i < ac)
	{
		neg = 0;
		if ((*av[i] == '+' || *av[i] == '-') && (neg = 1))
			av[i]++;
		if (!av[i] || !ft_stris(av[i], ft_isdigit) || (nb =  ft_atoi(av[i])) > INT_MAX)
			return (FALSE);
		if (tab[nb] != 1 << 3)
			if ((neg == 1 && tab[nb] == 1 << 2) || (neg == 0 && tab[nb] == 1 << 1))
				tab[nb] = 1 << 3;
			else if (neg == 0 && tab[nb] != 1 << 2)
				tab[nb] = 1 << 2;
			else if (neg == 1 && tab[nb] != 1 << 1)
				tab[nb] = 1 << 1;
			else
				return (FALSE);
		else
			return (FALSE);
	}
	return (TRUE);
}