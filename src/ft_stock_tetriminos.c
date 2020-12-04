/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_tetriminos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 04:14:54 by oboualla          #+#    #+#             */
/*   Updated: 2019/06/18 05:06:31 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_is_egual(int *index, int pos, int sq)
{
	int max;
	int i;

	max = sq - 1;
	i = 0;
	while (max < ((sq * sq) - 1))
	{
		i = 0;
		while (i < 4)
		{
			if ((index[i] + pos) == max)
				return (1);
			i++;
		}
		max += sq;
	}
	return (0);
}

static int	ft_stock(int *index, char *tetris, char alpha, int pos)
{
	int i;

	i = 0;
	if (tetris[index[0] + pos] == '.' && tetris[index[1] + pos] == '.'
	&& tetris[index[2] + pos] == '.' && tetris[index[3] + pos] == '.')
	{
		while (i < 4)
		{
			tetris[index[i] + pos] = alpha;
			i++;
		}
		return (1);
	}
	return (0);
}

int			ft_stock_tetriminos(int *index, char *tetris, char alpha, int sq)
{
	int pos;
	int n_pos;

	n_pos = 0;
	pos = 0;
	while ((index[3] + pos) < (sq * sq) && !ft_stock(index, tetris, alpha, pos))
	{
		if (check_is_egual(index, pos, sq))
		{
			if (!(n_pos = index_to_nwl(index, pos, sq)))
				return (0);
			pos += n_pos;
		}
		else
			pos++;
	}
	if ((index[3] + pos) > (sq * sq - 1))
		return (0);
	return (1);
}
