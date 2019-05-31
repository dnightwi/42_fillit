/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnightwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:52:19 by dnightwi          #+#    #+#             */
/*   Updated: 2019/05/06 16:52:22 by dnightwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**finds symbol that figure consist of and writes it in the chained list
**this needs for programm work
*/

void	find_sym(t_lst *figs)
{
	int i;

	i = 0;
	while (1)
	{
		if (figs->str[0][i] != '.')
		{
			figs->sym = figs->str[0][i];
			break ;
		}
		i++;
	}
}

/*
**if line only has dots (.) deletes this line
*/

char		*del_empty_line(char *line)
{
	int	i;
	int	check;

	i = 0;
	check = 1;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != '.')
			check = 0;
		i++;
	}
	if (check)
	{
		while (*line == '.')
			line++;
		line++;
		line = del_empty_line(line);
	}
	return (line);
}

/*
**same as previos, but for columns
*/

char		**del_empty_column(char **line)
{
	int	i;
	int	check;

	i = 0;
	check = 1;
	while (line[i])
	{
		if (line[i][0] != '.')
		{
			check = 0;
			break ;
		}
		i++;
	}
	i = 0;
	if (check)
	{
		while (line[i])
		{
			line[i]++;
			i++;
		}
		line = del_empty_column(line);
	}
	return (line);
}

/*
**creates list, str consist figure, sym - symbol that previously was changed from hashs (#) to sym A-Z
*/

t_lst		*create_elem(char *map)
{
	t_lst	*new;
	int		i;

	new = (t_lst *)malloc(sizeof(t_lst));
	new->str = ft_strsplit(map, '\n');
	if (new->str[0])
	{
		new->str = del_empty_column(new->str);
		find_sym(new);
	}
	new->next = NULL;
	return (new);
}

/*
**checks if figure is valid, counts side connections
*/

int			valid_check(char *map)
{
	int			count;
	int			i;
	static int	cm = 1;

	if (cm > 26)
		return (0);
	count = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == '#')
		{
			if (map[i + 1] == '#' && i + 1 < 20)
				count++;
			if (map[i + 5] == '#' && i + 5 < 20)
				count++;
			if (map[i - 1] == '#' && i - 1 >= 0)
				count++;
			if (map[i - 5] == '#' && i - 5 >= 0)
				count++;
		}
		i++;
	}
	cm++;
	return (count == 6 || count == 8);
}
