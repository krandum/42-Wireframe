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

int				move_loop_hook(t_view *view)
{
	if (view->pressed->w)
		view->theta += 0.05;
	if (view->pressed->s)
		view->theta -= 0.05;
	if (view->pressed->a)
		view->phi -= 0.05;
	if (view->pressed->d)
		view->phi += 0.05;
	if (view->pressed->q)
		view->psi += 0.05;
	if (view->pressed->e)
		view->psi -= 0.05;
	if (view->pressed->up)
		view->y_shift -= 5.0;
	if (view->pressed->down)
		view->y_shift += 5.0;
	if (view->pressed->left)
		view->x_shift -= 5.0;
	if (view->pressed->right)
		view->x_shift += 5.0;
	draw_reload(view);
	return (0);
}

int				key_pressed_hook(int keycode, t_view *view)
{
	if (keycode == KEY_ESC)
		exit_hook(view);
	if (keycode == KEY_ROT_X_U)
		view->pressed->w = 1;
	else if (keycode == KEY_ROT_X_D)
		view->pressed->s = 1;
	else if (keycode == KEY_ROT_Y_U)
		view->pressed->a = 1;
	else if (keycode == KEY_ROT_Y_D)
		view->pressed->d = 1;
	else if (keycode == KEY_ROT_Z_U)
		view->pressed->e = 1;
	else if (keycode == KEY_ROT_Z_D)
		view->pressed->q = 1;
	else if (keycode == KEY_UP)
		view->pressed->up = 1;
	else if (keycode == KEY_DOWN)
		view->pressed->down = 1;
	else if (keycode == KEY_LEFT)
		view->pressed->left = 1;
	else if (keycode == KEY_RIGHT)
		view->pressed->right = 1;
	return (0);
}

int				key_released_hook(int keycode, t_view *view)
{
	if (keycode == KEY_ROT_X_U)
		view->pressed->w = 0;
	else if (keycode == KEY_ROT_X_D)
		view->pressed->s = 0;
	else if (keycode == KEY_ROT_Y_U)
		view->pressed->a = 0;
	else if (keycode == KEY_ROT_Y_D)
		view->pressed->d = 0;
	else if (keycode == KEY_ROT_Z_U)
		view->pressed->e = 0;
	else if (keycode == KEY_ROT_Z_D)
		view->pressed->q = 0;
	else if (keycode == KEY_UP)
		view->pressed->up = 0;
	else if (keycode == KEY_DOWN)
		view->pressed->down = 0;
	else if (keycode == KEY_LEFT)
		view->pressed->left = 0;
	else if (keycode == KEY_RIGHT)
		view->pressed->right = 0;
	return (0);
}

int		expose_hook(t_view *view)
{
	draw_reload(view);
	return (0);
}
