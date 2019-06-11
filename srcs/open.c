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

static int	check_map(char *lne)
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

static int	get_next_line(int fd, char **line, t_lst **map, t_lst **tmp)
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

static int	check_figure(char *str)
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

t_lst		*op_wr(char *file, char *line)
{
	t_lst	*map;
	t_lst	*tmp;
	char	string[20];
	int		i;
	int		j;

	if (get_next_line(open(file, O_RDONLY), &line, &map, &tmp))
		return (NULL);
	j = 0;
	while (line[j])
	{
		i = 0;
		while (i < 20)
			string[i++] = line[j++];
		string[i] = '\0';
		if (check_figure(string) || !(valid_check(string)))
			return (NULL);
		map->next = create_elem(change_sym(string));
		map = map->next;
		if (line[j++] == '\0')
			break ;
	}
	free(line);
	tmp = tmp->next;
	return (tmp);
}