/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgfx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palatorr <palatorr@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 17:01:40 by palatorr          #+#    #+#             */
/*   Updated: 2016/10/10 17:01:41 by palatorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGFX_H
# define LIBGFX_H

# define COLOR1 0x0066ffff
# define COLOR2 0x006600ff

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# include "libft.h"
# include "mlx.h"
# include "math.h"

typedef struct	s_2dp
{
	float	x;
	float	y;
}				t_2dp;

typedef struct	s_3dp
{
	float	x;
	float	y;
	float	z;
}				t_3dp;

typedef struct	s_vertex
{
	t_3dp	*local;
	t_3dp	*world;
	t_3dp	*aligned;
	t_3dp	*projected;
}				t_vertex;

typedef struct	s_view
{
	void		*id;
	void		*win;
	t_vertex	***points;
	int			width;
	int			height;
	int			z_minclip;
	int			z_maxclip;
	float		theta;
	float		phi;
	float		psi;
	float		scale;
	float		x_shift;
	float		y_shift;
	float		z_shift;
}				t_view;

void		ft_mat_bzero(float mat[4][4]);
void		ft_get_id_matrix(float mat[4][4]);
void		ft_mat_mult(float m1[4][4], float m2[4][4], float d[4][4]);
void		ft_vec_mat_mult(t_3dp *src, float mat[4][4], t_3dp *dst);
void		ft_mat_translate(float mat[4][4], float x, float y, float z);
void		ft_mat_rotate(float mat[4][4], float theta, float phi, float psi);
void		ft_mat_scale(float mat[4][4], float x, float y, float z);
t_2dp		*ft_get_2d_point(float x, float y);
t_3dp		*ft_get_3d_point(float x, float y, float z);
t_vertex	*ft_get_vertex(float x, float y, float z);
void		ft_draw_point(t_view *view, int x, int y, float z);
void		ft_drawline_3d(t_view *view, t_3dp p0, t_3dp p1);

#endif
