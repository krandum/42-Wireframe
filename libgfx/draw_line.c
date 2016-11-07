/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palatorr <palatorr@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 21:18:48 by palatorr          #+#    #+#             */
/*   Updated: 2016/10/10 21:18:49 by palatorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgfx.h"

void		ft_init_color_table(t_view *view, int colors)
{
	int				i;
	float			f;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	view->colors = (t_color*)malloc(sizeof(t_color) * colors);
	f = 0;
	i = -1;
	if (!view->z_max && !view->z_min)
		view->z_max = 1;
	while (++i < colors)
	{
		r = (cos(f) + 1) * 127;
		g = (sin(f) + 1) * 127;
		b = (-cos(f) + 1) * 127;
		view->colors[i] = ((int)r) << 16 | ((int)g) << 8 | b;
		f += M_PI / colors;
	}
	view->num_colors = colors;
}

int			ft_draw_point(t_view *view, int x, int y, float z)
{
	int				i;
	float			which;
	unsigned int	color;

	if (x > 0 && y > 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		i = (x * 4) + (y * view->size_line);
		which = ((z - view->z_min) / (view->z_max - view->z_min)) *
			(view->num_colors);
		color = view->colors[abs((int)which - 1)];
		view->pixels[i] = color;
		view->pixels[++i] = color >> 8;
		view->pixels[++i] = color >> 16;
		return (1);
	}
	return (0);
}

/*
**	Returns one if it had to flip x and y. We do this to only have one drawline
**	function.
*/

static int	swap_vars(t_3dp *p0, t_3dp *p1)
{
	float	temp;

	if (fabs(p1->x - p0->x) > fabs(p1->y - p0->y))
		return (0);
	temp = p0->y;
	p0->y = p0->x;
	p0->x = temp;
	temp = p1->y;
	p1->y = p1->x;
	p1->x = temp;
	return (1);
}

static int	check_deltas(t_3dp *p0, t_3dp *p1, float delta[3], int dir)
{
	t_3dp	temp;

	if (p0->x == 4.2E7 || p1->x == 4.2E7)
		return (0);
	if ((p0->x > p1->x && p0->x > (dir ? WIN_HEIGHT : WIN_WIDTH) / 2) ||
		(p0->x < p1->x && p0->x < (dir ? WIN_HEIGHT : WIN_WIDTH) / 2))
	{
		temp = *p0;
		*p0 = *p1;
		*p1 = temp;
	}
	delta[0] = p1->x - p0->x;
	if (p0->y == 4.2E7 || p1->y == 4.2E7)
		return (0);
	delta[1] = p1->y - p0->y;
	delta[2] = p1->z - p0->z;
	return (1);
}

void		ft_drawline_3d(t_view *view, t_3dp p0, t_3dp p1)
{
	float	delta[3];
	float	error;
	float	slope;
	int		dir;

	dir = swap_vars(&p0, &p1);
	if (!check_deltas(&p0, &p1, delta, dir))
		return ;
	slope = fabs(delta[1] / delta[0]);
	error = -1.0;
	while ((int)p0.x != (int)p1.x)
	{
		if (!ft_draw_point(view, dir ? p0.y : p0.x, dir ? p0.x : p0.y, p0.z))
			return ;
		error += slope;
		if (error >= 0.0)
		{
			p0.y += (p0.y > p1.y) ? -1.0 : 1.0;
			error -= 1.0;
		}
		p0.z += delta[2] / fabs(delta[0]);
		p0.x += (p0.x > p1.x) ? -1.0 : 1.0;
	}
}
