/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 21:56:52 by oboualla          #+#    #+#             */
/*   Updated: 2019/06/19 20:12:35 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_detect_sqrt(char c)
{
	int sq;
	int nbr_term;

	sq = 0;
	nbr_term = c - 'A';
	nbr_term *= 4;
	while (!(sq = ft_sqrt(nbr_term)))
		nbr_term++;
	return (sq);
}

void		fillit(char **all_term)
{
	t_index *list;
	t_index *ptr;
	int		i;
	int		sq;

	i = 0;
	list = NULL;
	while (all_term[i])
	{
		ptr = ft_lstterm(&list, all_term[i]);
		i++;
	}
	free(all_term);
	if (ptr->alpha > 'Z')
	{
		del_lst(&list);
		error();
	}
	sq = ft_detect_sqrt(ptr->alpha + 1);
	while (!(ft_conver_index(list, 4, sq)))
		sq++;
	ft_make_tetris(list, sq);
}
