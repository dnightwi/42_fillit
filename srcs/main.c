/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:13:15 by dnightwi          #+#    #+#             */
/*   Updated: 2019/06/13 18:06:31 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**create_map(int n, char **map)
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

static void	free_it(char **str)
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

static void	print_res(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i++]);
		write(1, "\n", 1);
	}
	free_it(map);
}

static void	free_lst(t_lst *trash)
{
	t_lst	*tmp;
	char	**arr;
	int		i;

	while (trash)
	{
		tmp = trash;
		trash = trash->next;
		arr = tmp->str;
		while (ft_strlen(arr[0]) != 4)
		{
			i = 0;
			while (arr[i])
				arr[i++]--;
		}
		free_it(arr);
		if (tmp)
			free(tmp);
	}
}

int			main(int argc, char **argv)
{
	int		side_len;
	char	**map;
	char	*line;
	t_lst	*tetr;

	map = NULL;
	line = NULL;
	side_len = 2;
	if (argc == 2)
	{
		if (!(tetr = op_wr(argv[1], line)))
			return (write(1, "error\n", 6));
		map = create_map(side_len, map);
		while (fill_map(tetr, &map, side_len))
		{
			free_it(map);
			side_len++;
			map = create_map(side_len, map);
		}
		print_res(map);
		free_lst(tetr);
	}
	else
		write(1, "usage: fillit file\n", 19);
	return (0);
}
