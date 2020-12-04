/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readtet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 17:58:06 by kbahrar           #+#    #+#             */
/*   Updated: 2019/05/23 17:58:29 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	freedxpoint(char *big, char *line)
{
	free(big);
	free(line);
}

char		*ft_readtet(char *argv)
{
	int		fd;
	char	*line;
	char	*big;
	char	*ptr;

	if (!(big = (char*)ft_memalloc(sizeof(char) * 2)))
		return (NULL);
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ptr = big;
		if (ft_strlen(line) != 4 && ft_strlen(line) != 0)
		{
			freedxpoint(big, line);
			return (NULL);
		}
		if (line[0] == '\0')
		{
			ft_strdel(&line);
			line = ft_strdup("\n");
		}
		big = ft_strjoin(ptr, line);
		freedxpoint(ptr, line);
	}
	return (big);
}
