/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index__to_nwl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 06:55:21 by oboualla          #+#    #+#             */
/*   Updated: 2019/06/19 20:11:39 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_check_index(int *index, int pos, int sq)
{
	int	i;
	int	max;
	int	min;

	i = 0;
	max = (sq * sq) - 1;
	min = max - (sq - 1);
	while (i < 4)
	{
		if ((index[i] + pos) >= min && (index[i] + pos) <= max)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_is_egual(int *index, int sq, int pos)
{
	int max;
	int min;
	int i;

	i = 0;
	max = sq - 1;
	min = 0;
	while (max < (sq * sq))
	{
		i = 0;
		while (i < 4)
		{
			if ((index[i] + pos) == min)
				return (1);
			i++;
		}
		min += sq;
		max += sq;
	}
	return (0);
}

int			index_to_nwl(int *index, int pos, int sq)
{
	int new_pos;

	new_pos = sq;
	if (!(ft_check_index(index, pos, sq)))
		return (0);
	while (!(ft_is_egual(index, sq, pos + new_pos)))
		new_pos--;
	return (new_pos);
}
