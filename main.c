/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 01:48:37 by agaliste          #+#    #+#             */
/*   Updated: 2021/11/18 15:11:33 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	startmlx(t_data img)
{
	mlx_hook(img.win, 17, 0L, prgclose, &img);
	mlx_hook(img.win, 2, 1L << 0, key_hook, &img);
	mlx_loop(img.mlx);
}

int	main(int argc, char **argv)
{
	t_data	img;
	int		fd;

	img.coin = 0;
	img.cocur = 0;
	img.moves = 0;
	parseinput(argc, argv[1]);
	fd = open(argv[1], O_RDONLY);
	img.map = parsemap(fd);
	close(fd);
	img.y_size = getleny(img.map);
	img.x_size = ft_strnllen(img.map[0]);
	checkmapcontent(img.map, &img);
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 32 * img.x_size, 32 * img.y_size,
			"Er so long mu largo");
	draw(&img, 0);
	startmlx(img);
	return (0);
}
