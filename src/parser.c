/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palatorr <palatorr@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 16:31:30 by palatorr          #+#    #+#             */
/*   Updated: 2016/10/11 16:31:31 by palatorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define RET(x, y) if (c == x) return (y);

static int		get_hex(char c)
{
	RET('0', 0x0)
	RET('1', 0x1)
	RET('2', 0x2)
	RET('3', 0x3)
	RET('4', 0x4)
	RET('5', 0x5)
	RET('6', 0x6)
	RET('7', 0x7)
	RET('8', 0x8)
	RET('9', 0x9)
	RET('A', 0xA)
	RET('B', 0xB)
	RET('C', 0xC)
	RET('D', 0xD)
	RET('E', 0xE)
	RET('F', 0xF)
	return (0);
}

static t_color	get_color(char *str)
{
	t_color	out;
	int		shift;

	while (*str != 'x')
		if (!*(++str))
			return (-1);
	str++;
	out = 0;
	shift = 20;
	while (*str && shift >= 0)
	{
		out |= get_hex(*str) << shift;
		shift -= 4;
		str++;
	}
	return (out);
}

static void		keep_parsing(t_view *view, char *filename)
{
	char	*buff;
	char	**tab;
	int		fd;
	int		c[3];

	fd = open(filename, O_RDONLY);
	view->points = (t_vertex***)malloc(sizeof(t_vertex**) * view->height);
	c[1] = -1;
	while (ft_get_next_line(fd, &buff) && ++c[1] < 2147483647)
	{
		tab = ft_strsplit(buff, ' ');
		view->points[c[1]] = malloc(sizeof(t_vertex*) * view->width);
		c[0] = -1;
		while (++c[0] < view->width)
		{
			c[2] = ft_atoi(tab[c[0]]);
			view->points[c[1]][c[0]] = ft_get_vertex(c[0], c[1], c[2]);
			view->points[c[1]][c[0]]->color = get_color(tab[c[0]]);
			view->z_min = MIN(c[2], view->z_min);
			view->z_max = MAX(c[2], view->z_max);
		}
		free(buff);
		free(tab);
	}
}

void			parse(t_view *view, char *filename)
{
	char	*buff;
	char	**tab;
	int		fd;
	int		w;

	fd = open(filename, O_RDONLY);
	view->height = 0;
	view->width = 0;
	while (ft_get_next_line(fd, &buff))
	{
		tab = ft_strsplit(buff, ' ');
		w = 0;
		while (tab[w])
			w++;
		if (view->width != 0 && view->width != w)
			exit(0);
		view->width = w;
		view->height++;
		free(buff);
	}
	close(fd);
	keep_parsing(view, filename);
	view->per = 1;
	if (view->width > 50 || view->height > 50)
		view->per = 0;
}
