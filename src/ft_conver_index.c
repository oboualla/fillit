/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conver_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:54:28 by oboualla          #+#    #+#             */
/*   Updated: 2019/06/18 05:00:50 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	conver_index(int *index, int *is_conv, int nbr, int flag)
{
	if (flag == 1)
	{
		*is_conv = 1;
		*index += nbr;
	}
	else
	{
		*is_conv = 1;
		*index -= nbr;
	}
	return (1);
}

static int	ft_conv_to_small(int *index, int sq, int *is_conv)
{
	int	max;
	int	min;
	int	i;
	int	moin;

	moin = 0;
	max = sq - 1;
	min = 0;
	while (max < (sq * sq))
	{
		i = -1;
		while (++i < 4)
		{
			if ((index[i] >= min && index[i] <= max) && is_conv[i] == 0)
				conver_index(&index[i], &is_conv[i], moin, 0);
		}
		moin++;
		max += sq;
		min += sq;
	}
	return (1);
}

static int	ft_conv_to_larg(int *index, int sq, int *is_conv)
{
	int	max;
	int	min;
	int	i;
	int	plus;

	plus = 0;
	max = sq - 1;
	min = 0;
	while (max < (sq * sq))
	{
		i = -1;
		while (++i < 4)
		{
			if ((index[i] >= min && index[i] <= max) && is_conv[i] == 0)
				conver_index(&index[i], &is_conv[i], plus, 1);
		}
		plus++;
		max += sq;
		min += sq;
	}
	return (1);
}

static int	back_index(t_index *ptr, int sq1, int sq2)
{
	ptr = ptr->back;
	while (ptr)
	{
		ft_convert_case(ptr->index, sq2, sq1, &ft_conv_to_larg);
		ptr = ptr->back;
	}
	return (0);
}

int			ft_conver_index(t_index *ptr, int sq1, int sq2)
{
	if (sq1 < sq2)
		while (ptr)
		{
			ft_get_index(ptr->index, ptr->terminos);
			ft_convert_case(ptr->index, 4, sq2, &ft_conv_to_larg);
			ptr = ptr->next;
		}
	else
		while (ptr)
		{
			if (!(ft_convert_case(ptr->index, sq1, sq2, &ft_conv_to_small)))
				return (back_index(ptr, sq1, sq2));
			ptr = ptr->next;
		}
	return (1);
}
