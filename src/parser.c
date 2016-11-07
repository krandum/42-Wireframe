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

static void	keep_parsing(t_view *view, char *filename)
{
	char	*buff;
	char	**tab;
	int		fd;
	int		c[3];

	fd = open(filename, O_RDONLY);
	view->points = (t_vertex***)malloc(sizeof(t_vertex**) * view->height);
	c[1] = 0;
	view->z_min = 2147483647;
	view->z_max = -2147483648;
	while (ft_get_next_line(fd, &buff))
	{
		tab = ft_strsplit(buff, ' ');
		view->points[c[1]] = malloc(sizeof(t_vertex*) * view->width);
		c[0] = -1;
		while (++c[0] < view->width)
		{
			c[2] = ft_atoi(tab[c[0]]);
			view->points[c[1]][c[0]] = ft_get_vertex(c[0], c[1], c[2]);
			view->z_min = MIN(c[2], view->z_min);
			view->z_max = MAX(c[2], view->z_max);
		}
		c[1]++;
		free(buff);
	}
}

void		parse(t_view *view, char *filename)
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
