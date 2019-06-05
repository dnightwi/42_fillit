/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 16:31:45 by dnightwi          #+#    #+#             */
/*   Updated: 2019/06/05 18:57:52 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**finds spot on the map with given coordinats
**num[0] - y coor for the map, num[1] - x coor for the map, num[2] - x coor for the figure map, num[3] - counts how many symbols could be pasted
*/

void	ft_intdel(int **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

int		find_spot(char **map, char **tetr, int x, int y)
{
	int	num[4];

	num[0] = -1;
	num[2] = x;
	num[3] = 0;
	while (tetr[++num[0]] && map[y])
	{
		num[1] = 0;
		x = num[2];
		while (tetr[num[0]][num[1]] && map[y][x])
		{
			if (tetr[num[0]][num[1]] == '.')
			{
				num[1]++;
				x++;
				continue;
			}
			num[3] = (tetr[num[0]][num[1]] != '.') ? ++num[3] : num[3];
			if (map[y][x++] >= 'A' && map[y][x] <= 'Z')
				return (1);
			num[1]++;
		}
		y++;
	}
	return (num[3] != 4);
}

/*
**checks if its possible to add on the map next figure
*/

int		check_next(char **tetr, char **map, int side_len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (find_spot(map, tetr, j, i))
	{
		j++;
		if (j == side_len)
		{
			j = 0;
			i++;
		}
		if (i == side_len - 1 && j == side_len - 1)
			return (1);
	}
	return (0);
}

/*
**deletes figure from the map
*/

char	**remove_fig(char **map, char sym)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == sym)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

/*
**finds coordinats on the map to fill figure
*/

int		*find_cors(char ***map, t_lst *fig, int *cor, int side_len)
{
	while (find_spot(*map, fig->str, cor[1], cor[0]))
	{
		cor[1]++;
		if (cor[1] == side_len)
		{
			cor[1] = 0;
			cor[0]++;
		}
		if (cor[0] >= side_len - 1 && cor[1] >= side_len - 1)
		{
			*map = remove_fig(*map, fig->sym);
			cor[0] = -1;
			return (cor);
		}
	}
	return (cor);
}

/*
**writes figure on the map
*/

char	**write_fig(char **map, char **tetr, int *cor)
{
	int tmp;
	int	i;
	int	s;

	tmp = cor[1];
	i = -1;
	while (tetr[++i])
	{
		s = 0;
		cor[1] = tmp;
		while (tetr[i][s])
		{
			if (tetr[i][s] == '.')
			{
				s++;
				cor[1]++;
				continue;
			}
			map[cor[0]][cor[1]] = tetr[i][s];
			s++;
			cor[1]++;
		}
		cor[0]++;
	}
	return (map);
}

/*
**finds space and adds figure to the map and checks if its possible to add next figure
*/

int		add(t_lst *fig, char ***map, int side_len, int *c)
{
	int		*cor;
	int		tmp[2];

	cor = (int*)malloc(sizeof(int) * 2);
	cor[0] = c[0];
	cor[1] = c[1];
	cor = find_cors(map, fig, cor, side_len);
	if (cor[0] == -1)
	{
		ft_intdel(&cor);
		return (1);	
	}
	*map = write_fig(*map, fig->str, cor);
	ft_intdel(&cor);
	if (fig->next)
	{
		if (check_next(fig->next->str, *map, side_len))
		{
			*map = remove_fig(*map, fig->sym);
				return (1);	
		}
		tmp[0] = 0;
		tmp[1] = 0;
		if (fill_map(fig->next, map, side_len, tmp))
			return (1);
	}
	return (0);
}

/*
**increments coordinats depending on add function return
**needs for recursive check of space to fill figure 
*/

int		fill_map(t_lst *fig, char ***map, int side_len, int *cor)
{
	if (fig)
	{
		while (add(fig, map, side_len, cor))
		{
			cor[1]++;
			if (cor[1] == side_len)
			{
				cor[1] = 0;
				cor[0]++;
			}
			if (cor[0] >= side_len - 1 && cor[1] >= side_len - 1)
				return (1);
			*map = remove_fig(*map, fig->sym);
		}
	}
	return (0);
}
