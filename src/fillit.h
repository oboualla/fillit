/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 22:49:36 by kbahrar           #+#    #+#             */
/*   Updated: 2019/05/11 22:49:39 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_index	t_index;

struct					s_index
{
	char				*terminos;
	char				alpha;
	int					*index;
	t_index				*back;
	t_index				*next;
};

int						ft_copie_tetris(t_index *list, char *tetris, int sq);
int						ft_conver_index(t_index *list, int sq1, int sq2);
int						get_next_index(int *index, int sq, t_index *ptr);
int						ft_convert_case(int *index, int sq1, int sq2,
						int (*ft_conv)(int*, int, int*));
void					fillit(char **tab);
void					ft_putres(char *tetris, int sq);
int						ft_stock_tetriminos(int *index, char *tetris,
						char alpha, int sq);
void					ft_make_tetris(t_index *list, int c);
void					error(void);
void					ft_show_usage(void);
int						ft_conver_index(t_index *list, int sq1, int sq2);
int						index_to_nwl(int *index, int pos, int sq);
int						ft_index_debut(int *index, int sq);
int						ft_get_index(int *index, char *terminos);
void					del_lst(t_index **alst);
t_index					*ft_lstterm(t_index **alst, char *terminos);
int						ft_finalvalid(char *str);
void					ft_delsplit(char **tab);
int						if_allvalid(char *str);
int						ft_valid(char *argv);
char					*ft_readtet(char *argv);
#endif
