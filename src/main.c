/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palatorr <palatorr@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 19:34:28 by palatorr          #+#    #+#             */
/*   Updated: 2016/10/09 19:34:28 by palatorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		exit_hook(t_view *view)
{
	mlx_destroy_window(view->id, view->win);
	exit(0);
}

void	begin_loop(t_view *view)
{
	view->theta = 0.0;
	view->phi = 0.0;
	view->psi = 0.0;
	view->scale = 1.0;
	view->x_shift = 0.0;
	view->y_shift = 30.0;
	view->z_shift = 0.0;
	view->id = mlx_init();
	view->win = mlx_new_window(view->id, WIN_WIDTH, WIN_HEIGHT, "42-Wireframe");
	view->pressed = (t_keys*)ft_memalloc(sizeof(t_keys));
	world_init(view);
	ft_init_color_table(view, 100);
	draw_reload(view);
	mlx_expose_hook(view->win, expose_hook, view);
	mlx_do_key_autorepeatoff(view->id);
	mlx_hook(view->win, 2, 0, key_pressed_hook, view);
	mlx_hook(view->win, 3, 0, key_released_hook, view);
	mlx_hook(view->win, 17, 0, exit_hook, view);
	mlx_hook(view->win, 4, 5, mouse_hook, view);
	mlx_loop_hook(view->id, move_loop_hook, view);
	mlx_loop(view->id);
}

int		main(int argc, char **argv)
{
	t_view	*view;

	if (argc != 2)
	{
		ft_putendl("Usage : ./fdf <filename>");
		return (0);
	}
	view = (t_view*)malloc(sizeof(t_view));
	parse(view, argv[1]);
	begin_loop(view);
}
