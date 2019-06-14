/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:26:12 by dnightwi          #+#    #+#             */
/*   Updated: 2019/06/13 18:06:21 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**write_fig(char **map, char **tetr, int *cor)
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

char			**remove_fig(char **map, char sym)
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

static t_lst	*go_lst(char **map, t_lst *tetr)
{
	int	i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == tetr->sym)
			{
				tetr = tetr->next;
				i = 0;
				j = 0;
			}
			j++;
		}
		i++;
	}
	return (tetr);
}

int				check_space(char **map, t_lst *fig)
{
	int		i;
	int		j;
	int		count;
	int		count_lst;
	t_lst	*tetr;

	i = 0;
	count = 0;
	count_lst = 0;
	tetr = fig;
	while (map[i])
	{
		j = 0;
		while (map[i][j++])
			if (map[i][j] == '.')
				count++;
		i++;
	}
	tetr = go_lst(map, tetr);
	while (tetr->next)
	{
		count_lst++;
		tetr = tetr->next;
	}
	return (count_lst * 4 > count);
}
