/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copie_tetris.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:05:10 by oboualla          #+#    #+#             */
/*   Updated: 2019/06/19 20:12:19 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	new_test(t_index *list, t_index **ptr_term, int sq)
{
	t_index *ptr;

	ptr = *ptr_term;
	while (ptr && !(get_next_index(ptr->index, sq, ptr)))
		ptr = ptr->back;
	if (!(ptr))
	{
		*ptr_term = list;
		return (0);
	}
	*ptr_term = list;
	return (1);
}

int			ft_copie_tetris(t_index *list, char *tetris, int sq)
{
	t_index *ptr;

	if (!(list))
		return (-1);
	ptr = list;
	while (ptr)
	{
		if (!(ft_stock_tetriminos(ptr->index, tetris, ptr->alpha, sq)))
		{
			ft_memset((void*)tetris, '.', sq * sq);
			ptr = ptr->back;
			if (!(new_test(list, &ptr, sq)))
				break ;
		}
		else
			ptr = ptr->next;
	}
	if (!(ptr))
		return (1);
	return (0);
}
