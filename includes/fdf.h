/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palatorr <palatorr@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:35:53 by palatorr          #+#    #+#             */
/*   Updated: 2016/10/09 17:35:58 by palatorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include "libgfx.h"
# include <unistd.h>
# include <fcntl.h>

# define KEY_ESC 53

# define KEY_UP 126 //UP
# define KEY_DOWN 125 //DOWN
# define KEY_LEFT 123 //LEFT
# define KEY_RIGHT 124 //RIGHT

# define KEY_ZOOM_IN 49 //' '
# define KEY_ZOOM_OUT 257 //SHIFT

# define KEY_ROT_X_U 13 //W
# define KEY_ROT_X_D 1 //S
# define KEY_ROT_Y_U 0 //A
# define KEY_ROT_Y_D 2 //D
# define KEY_ROT_Z_U 12 //Q
# define KEY_ROT_Z_D 14 //E

void	draw_wireframe(t_view *view);
void	world_init(t_view *view);
void	align_transform(t_view *view);
void	draw_reload(t_view *view);
void	begin_loop(t_view *view);
void	parse(t_view *view, char *filename);
int		key_pressed_hook(int keycode, t_view *view);
int		key_released_hook(int keycode, t_view *view);
int		move_loop_hook(t_view *view);
int		expose_hook(t_view *view);
int		exit_hook(t_view *view);

#endif
