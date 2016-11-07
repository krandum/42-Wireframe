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

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define SCROLL_IN 4
# define SCROLL_OUT 5

# define KEY_ROT_X_U 13
# define KEY_ROT_X_D 1
# define KEY_ROT_Y_U 0
# define KEY_ROT_Y_D 2
# define KEY_ROT_Z_U 12
# define KEY_ROT_Z_D 14

void	draw_wireframe(t_view *view);
void	world_init(t_view *view);
void	align_transform(t_view *view);
void	draw_reload(t_view *view);
void	begin_loop(t_view *view);
void	parse(t_view *view, char *filename);
int		key_pressed_hook(int keycode, t_view *view);
int		key_released_hook(int keycode, t_view *view);
int		mouse_hook(int button, int x, int y, t_view *v);
int		move_loop_hook(t_view *view);
int		expose_hook(t_view *view);
int		exit_hook(t_view *view);

#endif
