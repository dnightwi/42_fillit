/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnightwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:16:51 by dnightwi          #+#    #+#             */
/*   Updated: 2019/05/06 18:16:54 by dnightwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct		s_lst
{
	char			**str;
	char			sym;
	struct s_lst	*next;
}					t_lst;

t_lst				*op_wr(char *file);
int					get_next_line(int fd, char **line,
					t_lst **map, t_lst **tmp);
int					check_figure(char *str);
t_lst				*create_elem(char *map);
static char			*change_sym(char *str);
int					valid_check(char *map);
int					check_map(char *lne);
char				**create_map(int n);
int					fill_map(t_lst *fig, char ***map, int side_len, int *cor);
char				*del_empty_line(char *line);
char				**del_empty_column(char **line);

#endif
