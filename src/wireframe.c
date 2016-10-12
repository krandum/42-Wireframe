/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palatorr <palatorr@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 20:10:05 by palatorr          #+#    #+#             */
/*   Updated: 2016/10/09 20:10:06 by palatorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_wireframe(t_view *view)
{
	int		y;
	int		x;

	y = -1;
	while (++y < view->height)
	{
		x = -1;
		while (++x < view->width)
		{
			if (x < view->width - 1)
				ft_drawline_3d(view, *(view->points[y][x]->aligned),
					*(view->points[y][x + 1]->aligned));
			if (y < view->height - 1)
				ft_drawline_3d(view, *(view->points[y][x]->aligned),
					*(view->points[y + 1][x]->aligned));
		}
	}
}

void	world_init(t_view *view)
{
	float	global[4][4];
	int		y;
	int		x;

	ft_get_id_matrix(global);
	ft_mat_translate(global, -(view->width / 2), -(view->height / 2), 0);
	ft_mat_scale(global, 1, 1, 0.25);
	y = -1;
	while (++y < view->height)
	{
		x = -1;
		while (++x < view->width)
		{
			ft_vec_mat_mult(view->points[y][x]->local, global,
				view->points[y][x]->world);
		}
	}
}

void	align_transform(t_view *view)
{
	float	global[4][4];
	int		y;
	int		x;

	ft_get_id_matrix(global);
	ft_mat_rotate(global, view->theta, view->phi, view->psi);
	ft_mat_scale(global, (WIN_WIDTH * view->scale) / view->width,
		(WIN_HEIGHT * view->scale) / view->height, 0.0);
	ft_mat_translate(global, WIN_WIDTH / 2 + view->x_shift,
		WIN_HEIGHT / 2 + view->y_shift, view->z_shift);
	y = -1;
	while (++y < view->height)
	{
		x = -1;
		while (++x < view->width)
		{
			ft_vec_mat_mult(view->points[y][x]->world, global,
				view->points[y][x]->aligned);
			view->points[y][x]->aligned->z = view->points[y][x]->local->z;
		}
	}
}

void	draw_reload(t_view *view)
{
	align_transform(view);
	mlx_clear_window(view->id, view->win);
	draw_wireframe(view);
}

void	begin_loop(t_view *view)
{
	view->theta = -M_PI / 12;
	view->phi = 0.075;
	view->psi = 0.0;
	view->scale = 1.0;
	view->x_shift = 0.0;
	view->y_shift = 0.0;
	view->z_shift = 0.0;
	view->id = mlx_init();
	view->win = mlx_new_window(view->id, WIN_WIDTH, WIN_HEIGHT, "42-Wireframe");
	world_init(view);
	draw_reload(view);
	mlx_expose_hook(view->win, expose_hook, view);
	mlx_hook(view->win, 2, 3, key_hook, view);
	mlx_loop(view->id);
}
