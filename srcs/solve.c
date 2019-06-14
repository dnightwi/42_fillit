/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 16:31:45 by dnightwi          #+#    #+#             */
/*   Updated: 2019/06/13 18:06:15 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	find_spot(char **map, char **tetr, int x, int y)
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

static int	check_next(char **tetr, char **map, int side_len)
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

static int	*find_cors(char ***map, t_lst *fig, int *cor, int side_len)
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

static int	add(t_lst *fig, char ***map, int side_len, int *c)
{
	int		*cor;

	cor = (int*)malloc(sizeof(int) * 2);
	cor[0] = c[0];
	cor[1] = c[1];
	cor = find_cors(map, fig, cor, side_len);
	if (cor[0] == -1)
	{
		free(cor);
		return (1);
	}
	*map = write_fig(*map, fig->str, cor);
	free(cor);
	if (fig->next)
	{
		if (check_next(fig->next->str, *map, side_len))
		{
			*map = remove_fig(*map, fig->sym);
			return (1);
		}
		if (fill_map(fig->next, map, side_len))
			return (1);
	}
	return (0);
}

int			fill_map(t_lst *fig, char ***map, int side_len)
{
	int	cor[2];

	cor[0] = 0;
	cor[1] = 0;
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
			if ((cor[0] >= side_len - 1 && cor[1] >= side_len - 1)
			|| check_space(*map, fig))
				return (1);
			*map = remove_fig(*map, fig->sym);
		}
	}
	return (0);
}
