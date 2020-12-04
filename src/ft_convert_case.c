/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 04:50:51 by oboualla          #+#    #+#             */
/*   Updated: 2019/06/18 05:03:40 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	protect_convert(int *index, int sq1, int sq2)
{
	int	i;
	int	max;

	max = sq1 - 1;
	while (max < (sq1 * sq1))
	{
		i = 0;
		while (i < 4)
		{
			if (index[i] > (sq2 * sq2))
				return (0);
			if (index[i] == max)
				return (0);
			i++;
		}
		max += sq1;
	}
	return (1);
}

int			ft_convert_case(int *index, int sq1, int sq2,
		int (*ft_conv)(int*, int, int*))
{
	int *is_conv;

	if (!(is_conv = (int*)ft_memalloc(sizeof(int) * 4)))
		return (-1);
	if (sq1 > sq2)
		if (!(protect_convert(index, sq1, sq2)))
		{
			free(is_conv);
			return (0);
		}
	while (sq1 != sq2)
	{
		ft_conv(index, sq1, is_conv);
		ft_memset((void*)is_conv, 0, 4 * 4);
		if (sq1 < sq2)
			sq1++;
		else if (sq1 > sq2)
			sq1--;
	}
	free(is_conv);
	return (1);
}
