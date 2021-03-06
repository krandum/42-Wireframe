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

# include "libft.h"
# include "mlx.h"
# include "math.h"

# define WIN_WIDTH 1600
# define WIN_HEIGHT 1200

typedef unsigned int	t_color;
typedef unsigned char	t_byte;

typedef struct	s_2dp
{
	float		x;
	float		y;
}				t_2dp;

typedef struct	s_3dp
{
	float		x;
	float		y;
	float		z;
}				t_3dp;

typedef struct	s_vertex
{
	t_3dp		*local;
	t_3dp		*world;
	t_3dp		*aligned;
	t_3dp		*projected;
	t_color		color;
}				t_vertex;

typedef struct	s_keys
{
	int			q:1;
	int			w:1;
	int			e:1;
	int			a:1;
	int			s:1;
	int			d:1;
	int			up:1;
	int			left:1;
	int			right:1;
	int			down:1;
}				t_keys;

typedef struct	s_view
{
	void		*id;
	void		*win;
	void		*img;
	char		*pixels;
	t_vertex	***points;
	t_color		*colors;
	int			num_colors;
	int			width;
	int			height;
	int			z_min;
	int			z_max;
	float		theta;
	float		phi;
	float		psi;
	float		scale;
	float		x_shift;
	float		y_shift;
	float		z_shift;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_keys		*pressed;
	int			per;
}				t_view;

t_color			ft_get_color(t_view *view, float c);
void			ft_init_color_table(t_view *view, int colors);
void			ft_mat_bzero(float mat[4][4]);
void			ft_get_id_matrix(float mat[4][4]);
void			ft_mat_mult(float m1[4][4], float m2[4][4], float d[4][4]);
void			ft_vec_mat_mult(t_3dp *src, float mat[4][4], t_3dp *dst);
void			ft_mat_translate(float mat[4][4], float x, float y, float z);
void			ft_mat_rotate(float mat[4][4], float theta, float phi,
	float psi);
void			ft_mat_scale(float mat[4][4], float x, float y, float z);
t_2dp			*ft_get_2d_point(float x, float y);
t_3dp			*ft_get_3d_point(float x, float y, float z);
t_vertex		*ft_get_vertex(float x, float y, float z);
int				ft_draw_point(t_view *view, int x, int y, float z);
void			ft_drawline_3d(t_view *view, t_3dp p0, t_3dp p1);
t_color			ft_color_mult(t_color c, float r);
t_color			ft_color_partial_combine(t_color c1, t_color c2, float r);
t_color			ft_color_combine(t_color c1, t_color c2);
void			ft_put_pixel(t_view *view, int x, int y, t_color color);

#endif
