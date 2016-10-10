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

int		main(void)
{
	/*int		fd;

	if (argc != 2)
	{
		ft_putendl("Usage : ./fdf <filename>");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("No file ");
		ft_putendl(argv[1]);
		return (1);
	}
	close(fd);*/
	void	*id;
	void	*win;

	id = mlx_init();
	win = mlx_new_window(id, 2000, 1200, "Wireframe Projection");
	for (int i = 0; i < 1000; i++)
	{
		mlx_pixel_put(id, win, 500 + i, 600, 0x002222FF);
	}
	mlx_loop(id);
}
