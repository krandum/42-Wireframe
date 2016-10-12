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

void		ft_draw_point(t_view *view, int x, int y, float z)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned int	color;
	float			per;

	if (x > 0 && y > 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		per = fabs(z) / 10.0;
		r = ((COLOR2 >> 16) - (COLOR1 >> 16) * per);
		r += COLOR1 >> 16;
		g = ((COLOR2 >> 8 & 0xFF) - (COLOR1 >> 8 & 0xFF)) * per;
		g += COLOR1 >> 8 & 0xFF;
		b = ((COLOR2 & 0xFF) - (COLOR1 & 0xFF)) * per;
		b += COLOR1 & 0xFF;
		color = ((int)r) << 16 | ((int)g) << 8 | b;
		mlx_pixel_put(view->id, view->win, x, y, color);
	}
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

static void	get_deltas(float *delta, t_3dp p0, t_3dp p1)
{
	delta[0] = p1.x - p0.x;
	delta[1] = p1.y - p0.y;
	delta[2] = p1.z - p0.z;
}

void		ft_drawline_3d(t_view *view, t_3dp p0, t_3dp p1)
{
	float	delta[3];
	float	error;
	float	slope;
	int		dir;

	dir = swap_vars(&p0, &p1);
	get_deltas(delta, p0, p1);
	slope = fabs(delta[1] / delta[0]);
	error = -1.0;
	while ((int)p0.x != (int)p1.x)
	{
		ft_draw_point(view, dir ? p0.y : p0.x, dir ? p0.x : p0.y, p0.z);
		error += slope;
		if (error >= 0.0)
		{
			p0.y += (p0.y > p1.y) ? -1.0 : 1.0;
			error -= 1.0;
		}
		p0.z -= (p0.z > p1.z) ? -(delta[2] / delta[0]) : delta[2] / delta[0];
		p0.x += (p0.x > p1.x) ? -1.0 : 1.0;
	}
}
