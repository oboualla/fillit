/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 21:33:31 by kbahrar           #+#    #+#             */
/*   Updated: 2019/05/21 21:34:12 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_valid(char *tab)
{
	int		j;
	int		conx;
	int		diaz;

	j = -1;
	conx = 0;
	diaz = 0;
	while (tab[++j])
	{
		if (tab[j] == '#')
		{
			if (tab[j + 1] == '#' && j != 3 && j != 7 && j != 11 && j != 15)
				conx++;
			if (tab[j - 1] == '#' && j != 4 && j != 8 && j != 12 && j != 0)
				conx++;
			if (tab[j + 4] == '#')
				conx++;
			if (tab[j - 4] == '#')
				conx++;
			diaz++;
		}
	}
	if (diaz != 4 || conx < 6)
		return (0);
	return (1);
}
