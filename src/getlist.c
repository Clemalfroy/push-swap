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

inline static void	bitset(uint32_t *words, uint32_t n)
{
	words[n / (sizeof(uint32_t) * 8)] |= (1 << n % (sizeof(uint32_t) * 8));
}

inline static int	bitget(uint32_t const *words, uint32_t n)
{
	uint32_t bit;

	bit = words[n / (sizeof(uint32_t) * 8)] & (1 << n % (sizeof(uint32_t) * 8));
	return (bit != 0);
}

inline int			getlist(int ac, char **av, t_list *a)
{
	int				i;
	int64_t			nb;
	static uint32_t tab[UINT32_MAX / 32] = { 0 };

	i = 0;
	while (++i < ac)
	{
		if (!av[i] || !ft_stris(av[i] + (*av[i] == '+' || *av[i] == '-' ? 1 :
			0), ft_isdigit) || (nb = ft_atoi(av[i])) > INT_MAX || nb < INT_MIN)
			return (FALSE);
		if (!bitget(tab, (uint32_t)nb))
			bitset(tab, (uint32_t)nb);
		else
			return (FALSE);
		dlstaddbefore(a, (int)nb);
	}
	return (TRUE);
}
