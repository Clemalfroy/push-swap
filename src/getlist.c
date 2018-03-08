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

#include "getinfo.h"

void				freeall(t_list *a, t_list *b)
{
	dlstdtor(&a);
	dlstdtor(&b);
}

inline static void	bitset(uint32_t *words, int n)
{
	words[n / (INT_MAX)] |= (1 << n % (INT_MAX));
}

inline static int	bitget(uint32_t const *words, int n)
{
	uint32_t bit;

	bit = words[n / (INT_MAX)] & (1 << n % (INT_MAX));
	return (bit != 0);
}

inline int			getlist(int ac, char **av, t_list *a)
{
	int				i;
	int64_t			nb;
	static uint32_t tab[UINT32_MAX / (32 * 32)] = { 0 };

	i = 0;
	while (++i < ac)
	{
		if (!av[i] || !ft_stris(av[i] + (*av[i] == '+' || *av[i] == '-' ? 1 :
			0), ft_isdigit) || (nb = ft_atoi(av[i])) > INT_MAX || nb < INT_MIN)
			return (FALSE);
		if (!bitget(tab, (unsigned int)nb))
			bitset(tab, (unsigned int)nb);
		else
			return (FALSE);
		dlstaddbefore(a, (int)nb);
	}
	return (TRUE);
}
