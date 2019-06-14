/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:16:51 by dnightwi          #+#    #+#             */
/*   Updated: 2019/06/13 18:06:43 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct		s_lst
{
	char			**str;
	char			sym;
	struct s_lst	*next;
}					t_lst;

t_lst				*op_wr(char *file, char *line);
t_lst				*create_elem(char *map);
int					fill_map(t_lst *fig, char ***map, int side_len);
int					valid_check(char *map);
int					check_space(char **map, t_lst *tetr);
char				**remove_fig(char **map, char sym);
char				**write_fig(char **map, char **tetr, int *cor);
char				*del_empty_line(char *line);

#endif
