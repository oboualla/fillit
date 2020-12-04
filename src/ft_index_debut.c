/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_debut.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 05:02:17 by oboualla          #+#    #+#             */
/*   Updated: 2019/06/18 05:04:08 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	is_debut(int *index, int sq)
{
	int i;

	while (index[0] > (sq - 1))
	{
		i = 0;
		while (i < 4)
			index[i++] -= sq;
	}
	return (1);
}

static int	is_egual(int *index, int sq)
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
			if (index[i] == min)
				return (1);
			i++;
		}
		min += sq;
		max += sq;
	}
	return (0);
}

int			ft_index_debut(int *index, int sq)
{
	int max;
	int min;
	int i;

	max = sq - 1;
	min = 0;
	while (!is_egual(index, sq))
	{
		i = 0;
		while (i < 4)
			index[i++]--;
	}
	is_debut(index, sq);
	return (1);
}
