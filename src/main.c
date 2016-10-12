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
