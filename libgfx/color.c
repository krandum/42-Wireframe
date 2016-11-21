/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palatorr <palatorr@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 17:16:49 by palatorr          #+#    #+#             */
/*   Updated: 2016/10/30 17:16:50 by palatorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgfx.h"

t_color		ft_color_mult(t_color c, float r)
{
	t_byte	rgb[3];
	t_color	out;

	rgb[0] = (t_byte)((c & 0xFF0000) >> 16);
	rgb[1] = (t_byte)((c & 0xFF00) >> 8);
	rgb[2] = (t_byte)(c & 0xFF);
	rgb[0] = MAX(0, MIN(0xFF, rgb[0] * r));
	rgb[1] = MAX(0, MIN(0xFF, rgb[1] * r));
	rgb[2] = MAX(0, MIN(0xFF, rgb[2] * r));
	out = ((t_color)rgb[0]) << 16 | ((t_color)rgb[1]) << 8 | (t_color)rgb[2];
	return (out);
}

t_color		ft_color_partial_combine(t_color c1, t_color c2, float r)
{
	t_byte	rgb1[3];
	t_byte	rgb2[3];
	t_byte	rgbo[3];
	t_color	out;

	rgb1[0] = (t_byte)((c1 & 0xFF0000) >> 16);
	rgb1[1] = (t_byte)((c1 & 0xFF00) >> 8);
	rgb1[2] = (t_byte)(c1 & 0xFF);
	rgb2[0] = (t_byte)((c2 & 0xFF0000) >> 16);
	rgb2[1] = (t_byte)((c2 & 0xFF00) >> 8);
	rgb2[2] = (t_byte)(c2 & 0xFF);
	rgbo[0] = (t_byte)(((float)rgb1[0] * r) + ((float)rgb2[0] * (1.0 - r)));
	rgbo[1] = (t_byte)(((float)rgb1[1] * r) + ((float)rgb2[1] * (1.0 - r)));
	rgbo[2] = (t_byte)(((float)rgb1[2] * r) + ((float)rgb2[2] * (1.0 - r)));
	out = ((t_color)rgbo[0]) << 16 | ((t_color)rgbo[1]) << 8 | (t_color)rgbo[2];
	return (out);
}

t_color		ft_color_combine(t_color c1, t_color c2)
{
	unsigned char	rgb[3];
	t_color			out;

	if (!c1)
		return (c2);
	if (!c2)
		return (c1);
	rgb[0] = (unsigned char)((((c1 & 0xFF0000) + (c2 & 0xFF0000)) / 2) >> 16);
	rgb[1] = (unsigned char)((((c1 & 0xFF00) + (c2 & 0xFF00)) / 2) >> 8);
	rgb[2] = (unsigned char)(((c1 & 0xFF) + (c2 & 0xFF)) / 2);
	out = ((t_color)rgb[0]) << 16 | ((t_color)rgb[1]) << 8 | (t_color)rgb[2];
	return (out);
}

void		ft_put_pixel(t_view *view, int x, int y, t_color color)
{
	int				i;

	i = (x * 4) + (y * view->size_line);
	view->pixels[i] = color;
	view->pixels[++i] = color >> 8;
	view->pixels[++i] = color >> 16;
}
