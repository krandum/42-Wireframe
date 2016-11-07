/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palatorr <palatorr@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 23:35:15 by palatorr          #+#    #+#             */
/*   Updated: 2016/11/05 23:35:16 by palatorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			mouse_hook(int button, int x, int y, t_view *v)
{
	(void)x;
	(void)y;
	if (button == SCROLL_IN)
		v->scale *= 1.1;
	else if (button == SCROLL_OUT)
		v->scale /= 1.2;
	draw_reload(v);
	return (0);
}
