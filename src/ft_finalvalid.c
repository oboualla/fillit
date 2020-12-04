/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finalValid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:08:21 by kbahrar           #+#    #+#             */
/*   Updated: 2019/06/06 16:09:11 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	checkretourligne(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			if (j != 16 || (str[i] != '.' && str[i] != '#'))
			{
				return (0);
			}
			j = 0;
		}
		i++;
		j++;
	}
	return (1);
}

int			ft_finalvalid(char *str)
{
	char	**tab;
	int		i;

	i = 0;
	if (str == NULL || checkretourligne(str) != 1)
		return (0);
	if (!(tab = ft_strsplit(str, '\n')))
		return (0);
	if (tab[i] == NULL)
	{
		ft_delsplit(tab);
		return (0);
	}
	while (tab[i])
	{
		if (ft_valid(tab[i]) == 0 || if_allvalid(tab[i]) == 0)
		{
			ft_delsplit(tab);
			return (0);
		}
		i++;
	}
	ft_delsplit(tab);
	return (1);
}
