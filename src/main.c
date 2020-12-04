/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 22:06:57 by kbahrar           #+#    #+#             */
/*   Updated: 2019/06/20 17:15:23 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char	*big;
	char	**tab;
	int		i;

	i = 0;
	if (argc != 2)
		ft_putstr("usage: ./fillit [path_file]\n");
	else
	{
		big = ft_readtet(argv[1]);
		if (ft_finalvalid(big) == 0)
		{
			ft_putstr("error\n");
			free(big);
			return (0);
		}
		else
		{
			tab = ft_strsplit(big, '\n');
			free(big);
			fillit(tab);
			return (0);
		}
	}
}
