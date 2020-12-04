/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 05:25:35 by oboualla          #+#    #+#             */
/*   Updated: 2019/06/18 01:20:06 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_get_index(int *index, char *terminos)
{
	int i;

	i = 0;
	while (i < 4)
		index[i++] = -1;
	i = 0;
	while (terminos[i] != '\0')
	{
		if (terminos[i] == '#' && index[0] == -1)
			index[0] = i++;
		if (terminos[i] == '#' && index[1] == -1 && index[0] != -1)
			index[1] = i++;
		if (terminos[i] == '#' && index[2] == -1 && index[1] != -1)
			index[2] = i++;
		if (terminos[i] == '#' && index[3] == -1 && index[2] != -1)
			index[3] = i;
		i++;
	}
	ft_index_debut(index, 4);
	return (1);
}
