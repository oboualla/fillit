/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:56:23 by oboualla          #+#    #+#             */
/*   Updated: 2019/06/19 20:07:05 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	lst_index_debut(t_index *ptr, int sq)
{
	t_index *tmp;

	if (ptr->next)
	{
		tmp = ptr->next;
		while (tmp)
		{
			ft_index_debut(tmp->index, sq);
			tmp = tmp->next;
		}
	}
}

static int	help(int *index, int sq)
{
	int max;
	int i;

	max = sq - 1;
	while (max < (sq * sq))
	{
		i = 0;
		while (i < 4)
		{
			if (index[i] == max)
				return (0);
			i++;
		}
		max += sq;
	}
	return (1);
}

int			get_next_index(int *index, int sq, t_index *ptr)
{
	int new_pos;
	int i;

	i = 0;
	new_pos = 0;
	lst_index_debut(ptr, sq);
	if (!(help(index, sq)))
	{
		if (!(new_pos = index_to_nwl(index, 0, sq)))
			return (0);
		else
			while (i < 4)
				index[i++] += new_pos;
	}
	else
		while (i < 4)
			index[i++] += 1;
	return (1);
}
