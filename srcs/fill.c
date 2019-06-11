/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnightwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:26:12 by dnightwi          #+#    #+#             */
/*   Updated: 2019/06/11 15:26:15 by dnightwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
