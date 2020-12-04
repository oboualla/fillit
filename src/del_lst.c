/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 04:18:15 by oboualla          #+#    #+#             */
/*   Updated: 2019/06/18 05:03:20 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	del_lst(t_index **alst)
{
	t_index *ptr;
	t_index *next;

	if (*alst)
	{
		ptr = *alst;
		while (ptr)
		{
			next = ptr->next;
			ft_strdel(&ptr->terminos);
			free(ptr->index);
			free(ptr);
			ptr = next;
		}
	}
}
