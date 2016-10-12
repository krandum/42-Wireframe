/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palatorr <palatorr@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 16:31:22 by palatorr          #+#    #+#             */
/*   Updated: 2016/10/11 16:31:24 by palatorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		key_hook_rot(int keycode, t_view *view)
{
	if (keycode == KEY_ROT_X_U)
		view->theta += 0.05;
	else if (keycode == KEY_ROT_X_D)
		view->theta -= 0.05;
	else if (keycode == KEY_ROT_Y_U)
		view->phi -= 0.05;
	else if (keycode == KEY_ROT_Y_D)
		view->phi += 0.05;
	else if (keycode == KEY_ROT_Z_U)
		view->psi += 0.05;
	else if (keycode == KEY_ROT_Z_D)
		view->psi -= 0.05;
}

static void		key_hook_trans(int keycode, t_view *view)
{
	if (keycode == KEY_UP)
		view->y_shift += 5.0;
	else if (keycode == KEY_DOWN)
		view->y_shift -= 5.0;
	else if (keycode == KEY_LEFT)
		view->x_shift += 5.0;
	else if (keycode == KEY_RIGHT)
		view->x_shift -= 5.0;
}

static void		key_hook_scale(int keycode, t_view *view)
{
	if (keycode == KEY_ZOOM_IN)
		view->scale += 0.1;
	else if (keycode == KEY_ZOOM_OUT)
		view->scale = fabs(view->scale - 0.1);
}

int				key_hook(int keycode, t_view *view)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(view->id, view->win);
		exit(0);
	}
	key_hook_rot(keycode, view);
	key_hook_trans(keycode, view);
	key_hook_scale(keycode, view);
	draw_reload(view);
	return (0);
}

int				expose_hook(t_view *view)
{
	draw_reload(view);
	return (0);
}
