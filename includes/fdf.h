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

void	draw_wireframe(t_view *view);
void	world_init(t_view *view);
void	view_transform(t_view *view);
void	draw_reload(t_view *view);
void	begin_loop(t_view *view);
void	parse(t_view *view, char *filename);

#endif
