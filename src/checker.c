/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:33:29 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/02/26 13:33:32 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int argc, char **argv)
{
	if (argc == 1 || !getlist(argc, argv))
		return (ft_retf(NOP, "Error\n"));

	int i = 0;
	while(++i < argc)
		ft_putl(1, argv[i]);

	return (YEP);
}