/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_tetris.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:55:51 by oboualla          #+#    #+#             */
/*   Updated: 2019/06/18 05:01:40 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*new_case(int sq)
{
	char *tetris;

	if (!(tetris = ft_strnew(sq * sq)))
		return (NULL);
	ft_memset((void*)tetris, '.', sq * sq);
	return (tetris);
}

void		ft_make_tetris(t_index *list, int sq)
{
	t_index *ptr;
	char	*tetris;

	ptr = list;
	if (!(tetris = new_case(sq)))
		error();
	if (ft_copie_tetris(list, tetris, sq))
	{
		ft_putres(tetris, sq);
		ft_strdel(&tetris);
		del_lst(&list);
		exit(1);
	}
	sq++;
	ft_conver_index(list, sq - 1, sq);
	ft_strdel(&tetris);
	ft_make_tetris(list, sq);
}
