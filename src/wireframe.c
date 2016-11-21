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
				ft_drawline_3d(view, *(view->points[y][x]->projected),
					*(view->points[y][x + 1]->projected));
			if (y < view->height - 1)
				ft_drawline_3d(view, *(view->points[y][x]->projected),
					*(view->points[y + 1][x]->projected));
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
	ft_mat_scale(global, 1, 1, 0.15);
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
		(WIN_HEIGHT * view->scale) / view->height, view->scale);
	ft_mat_translate(global, view->x_shift, view->y_shift, view->z_shift);
	y = -1;
	while (++y < view->height)
	{
		x = -1;
		while (++x < view->width)
		{
			ft_vec_mat_mult(view->points[y][x]->world, global,
				view->points[y][x]->aligned);
		}
	}
}

#define VA(k) (view->points[y][x]->aligned->k)
#define VP(k) (view->points[y][x]->projected->k)
#define LIMIT(k) (fabs(k) < 0.1 ? ((k) / fabs(k)) * 0.0001: (k))

void	project_transform(t_view *view)
{
	int		y;
	int		x;

	y = -1;
	while (++y < view->height)
	{
		x = -1;
		while (++x < view->width)
		{
			if (VA(z) == 0.0)
				VA(z) = 0.0001;
			VP(x) = 6.0 * VA(x) / (view->per ? LIMIT(view->z_max - VA(z)) :
				6.0) + WIN_WIDTH / 2;
			if (view->z_max - VA(z) < 0 && view->per)
				VP(x) = 4.2E7;
			VP(y) = 6.0 * VA(y) / (view->per ? LIMIT(view->z_max - VA(z)) :
				6.0) + WIN_HEIGHT / 2;
			if (view->z_max - VA(z) < 0 && view->per)
				VP(y) = 4.2E7;
			VP(z) = view->points[y][x]->local->z;
		}
	}
}

void	draw_reload(t_view *view)
{
	align_transform(view);
	project_transform(view);
	view->img = mlx_new_image(view->id, WIN_WIDTH + 100, WIN_HEIGHT + 100);
	view->pixels = mlx_get_data_addr(view->img, &(view->bits_per_pixel),
		&(view->size_line), &(view->endian));
	draw_wireframe(view);
	mlx_put_image_to_window(view->id, view->win, view->img, 0, 0);
	mlx_destroy_image(view->id, view->img);
}
