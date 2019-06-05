/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnightwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:13:15 by dnightwi          #+#    #+#             */
/*   Updated: 2019/05/06 17:13:17 by dnightwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**create map of n size
*/

void	free_it(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**create_map(int n, char **map)
{
	int		i;
	int		j;

	i = 0;
	map = (char **)malloc(sizeof(char *) * n + 1);
	while (i < n)
	{
		j = 0;
		map[i] = (char *)malloc(sizeof(char) * n);
		while (j < n)
			map[i][j++] = '.';
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

/*
**print solve map
*/

void	print_res(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i++]);
		write(1, "\n", 1);
	}
}

/*
**main function where all magic happens
*/

int		main(int argc, char **argv)
{
	int		side_len;
	int		cor[2];
	char	**map;
	t_lst	*tetr;

	cor[0] = 0;
	cor[1] = 0;
	side_len = 4;
	if (argc == 2)
	{
		if (!(tetr = op_wr(argv[1])))
		{
			write(1, "error\n", 6);
			return (0);
		}
		map = create_map(side_len, map);
		while (fill_map(tetr, &map, side_len, cor))
		{
			free_it(map);
			cor[0] = 0;
			cor[1] = 0;
			side_len++;
			map = create_map(side_len, map);
		}
		print_res(map);
		free_it(map);
	}
	else
		write(1, "error\n", 6);
	return (0);
}
