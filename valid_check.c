/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnightwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:52:28 by dnightwi          #+#    #+#             */
/*   Updated: 2019/05/06 16:52:30 by dnightwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**checks if map with figure has correct end and spaces betwen figures
*/

int			check_map(char *lne)
{
	int i;

	i = 0;
	while (lne[i])
	{
		if (lne[i] == '\n' && lne[i + 1] == '\n' &&
		(lne[i + 2] == '\n' || lne[i + 2] == '\0'))
			return (1);
		i++;
	}
	return (0);
}

/*
**reads file from standart input and creates line, that consist all text from input file
*/

int			get_next_line(int fd, char **line, t_lst **map, t_lst **tmp)
{
	char	*buf;
	char	*tmpp;
	int		ret;

	ret = 0;
	*line = (char *)malloc(sizeof(char));
	buf = (char *)malloc(sizeof(char) * 2);
	while ((ret = read(fd, buf, 1)) > 0)
	{
		buf[1] = '\0';
		tmpp = *line;
		*line = ft_strjoin(*line, buf);
		if (tmpp)
			free(tmpp);
	}
	if (buf)
		free(buf);
	if (ret < 0 || !line || fd < 0 || check_map(*line))
		return (1);
	*map = create_elem("");
	*tmp = *map;
	return (0);
}

/*
**checks if one figure has 4 hashs(#), 5 new lines (\n) and 20 elements at all
*/

int			check_figure(char *str)
{
	int	i;
	int	hash;
	int	nl;

	i = 0;
	hash = 0;
	nl = 0;
	while (str[i])
	{
		if (str[i] == '#')
			hash++;
		if (str[i] == '\n')
			nl++;
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			break ;
		i++;
	}
	if (i != 20 || hash != 4 || nl != 4)
		return (1);
	return (0);
}

/*
**changes hashs to symbol from A to Z
*/

static char	*change_sym(char *str)
{
	int			i;
	static char	sym = 'A';

	i = 0;
	str = del_empty_line(str);
	while (str[i])
	{
		str[i] = (str[i] == '#') ? sym : str[i];
		i++;
	}
	sym++;
	return (str);
}

/*
** function works with line, that consist all text from input file
** one cycle works with one figure from input file: check is valid, and write it in the chained list
*/

t_lst		*op_wr(char *file)
{
	char	*line;
	t_lst	*map;
	t_lst	*tmp;
	char	*string;
	int		i;

	if (get_next_line(open(file, O_RDONLY), &line, &map, &tmp))
		return (NULL);
	while (*line)
	{
		i = 0;
		string = (char *)malloc(sizeof(char) * 20);
		while (i < 20)
			string[i++] = *(line++);
		string[i] = '\0';
		if (check_figure(string) || !(valid_check(string)))
			return (NULL);
		map->next = create_elem(change_sym(string));
		map = map->next;
		free(string);
		if (*(line++) == '\0')
			break ;
	}
	tmp = tmp->next;
	return (tmp);
}
