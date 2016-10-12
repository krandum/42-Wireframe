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
	int		y;
	int		x;
	int		z;

	buff = (char*)malloc(sizeof(char) * 4096);
	fd = open(filename, O_RDONLY);
	view->points = (t_vertex***)malloc(sizeof(t_vertex**) * view->height);
	y = 0;
	while (ft_get_next_line(fd, &buff))
	{
		tab = ft_strsplit(buff, ' ');
		view->points[y] = (t_vertex**)malloc(sizeof(t_vertex*) * view->width);
		x = -1;
		while (++x < view->width)
		{
			z = ft_atoi(tab[x]);
			view->points[y][x] = ft_get_vertex(x, y, z);
			view->z_minclip = MIN(z, view->z_minclip);
			view->z_maxclip = MAX(z, view->z_maxclip);
		}
		y++;
	}
}

void		parse(t_view *view, char *filename)
{
	char	*buff;
	char	**tab;
	int		fd;
	int		w;

	buff = (char*)malloc(sizeof(char) * 4096);
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
	}
	close(fd);
	keep_parsing(view, filename);
}
