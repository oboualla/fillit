/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putres.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 00:19:16 by oboualla          #+#    #+#             */
/*   Updated: 2019/06/18 22:39:57 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*minimize_box(char *tetris, int sq)
{
	int max;
	int min;

	max = sq - 1;
	min = (sq * sq) - sq;
	while ((max < (sq * sq) && min < (sq * sq))
			&& (tetris[max] == '.' && tetris[min] == '.'))
	{
		min++;
		max += sq;
	}
	if (max > (sq * sq) && min == (sq * sq))
	{
		max = sq - 1;
		min = (sq * sq) - sq;
		while (max < (sq * sq) && min < (sq * sq))
		{
			tetris[max] = '0';
			max += sq;
		}
		ft_memset((void*)&tetris[min], 0, sq);
	}
	return (tetris);
}

void		ft_putres(char *tetris, int sq)
{
	int i;
	int count;

	if (tetris)
	{
		count = 0;
		i = 0;
		minimize_box(tetris, sq);
		while (tetris[i] != '\0')
		{
			if (tetris[i] != '0')
				ft_putchar(tetris[i]);
			i++;
			count++;
			if (count == sq)
			{
				ft_putchar('\n');
				count = 0;
			}
		}
	}
}
