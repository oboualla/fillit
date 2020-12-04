/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstterm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 05:18:34 by oboualla          #+#    #+#             */
/*   Updated: 2019/06/18 05:06:04 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_index	*add_term(char *terminos, char c)
{
	t_index *new;

	if (!(new = (t_index*)ft_memalloc(sizeof(t_index))))
		return (NULL);
	if (!(new->index = (int*)ft_memalloc(sizeof(int) * 4)))
		return (NULL);
	ft_get_index(new->index, terminos);
	new->alpha = c;
	new->terminos = terminos;
	new->back = NULL;
	new->next = NULL;
	return (new);
}

t_index			*ft_lstterm(t_index **alst, char *terminos)
{
	t_index *ptr;
	t_index *new;
	t_index *back;

	if (!(*alst))
	{
		if (!(new = add_term(terminos, 'A')))
			return (NULL);
		*alst = new;
	}
	else
	{
		ptr = *alst;
		while (ptr->next)
			ptr = ptr->next;
		back = ptr;
		new = add_term(terminos, ptr->alpha + 1);
		ptr->next = new;
		ptr->next->back = back;
	}
	return (new);
}
