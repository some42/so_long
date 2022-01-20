/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printelem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 19:09:01 by agaliste          #+#    #+#             */
/*   Updated: 2022/01/20 12:41:36 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

static inline void
	printelem3(t_data *img, int i, size_t y, size_t x)
{
	if (i == 6)
	{
		img->path = "./imgs/characDown.xpm";
		img->img = mlx_xpm_file_to_image(img->mlx, img->path, &img->width,
				&img->height);
		mlx_put_image_to_window(img->mlx, img->win, img->img, y, x);
	}
	if (i == 7)
	{
		img->path = "./imgs/characLeft.xpm";
		img->img = mlx_xpm_file_to_image(img->mlx, img->path, &img->width,
				&img->height);
		mlx_put_image_to_window(img->mlx, img->win, img->img, y, x);
	}
	if (i == 8)
	{
		img->path = "./imgs/characRight.xpm";
		img->img = mlx_xpm_file_to_image(img->mlx, img->path, &img->width,
				&img->height);
		mlx_put_image_to_window(img->mlx, img->win, img->img, y, x);
	}
}

static inline void
	printelem2(t_data *img, int i, size_t y, size_t x)
{
	if (i == 3)
	{
		img->path = "./imgs/exit.xpm";
		img->img = mlx_xpm_file_to_image(img->mlx, img->path, &img->width,
				&img->height);
		mlx_put_image_to_window(img->mlx, img->win, img->img, y, x);
	}
	if (i == 4)
	{
		img->path = "./imgs/grass.xpm";
		img->img = mlx_xpm_file_to_image(img->mlx, img->path, &img->width,
				&img->height);
		mlx_put_image_to_window(img->mlx, img->win, img->img, y, x);
	}
	if (i == 5)
	{
		img->path = "./imgs/dirt.xpm";
		img->img = mlx_xpm_file_to_image(img->mlx, img->path, &img->width,
				&img->height);
		mlx_put_image_to_window(img->mlx, img->win, img->img, y, x);
	}
}

void
	printelem(t_data *img, int i, size_t y, size_t x)
{
	if (i == 0)
	{
		img->path = "./imgs/tree.xpm";
		img->img = mlx_xpm_file_to_image(img->mlx, img->path, &img->width,
				&img->height);
		mlx_put_image_to_window(img->mlx, img->win, img->img, y, x);
	}
	if (i == 1)
	{
		img->path = "./imgs/characUp.xpm";
		img->img = mlx_xpm_file_to_image(img->mlx, img->path, &img->width,
				&img->height);
		mlx_put_image_to_window(img->mlx, img->win, img->img, y, x);
	}
	if (i == 2)
	{
		img->path = "./imgs/collec.xpm";
		img->img = mlx_xpm_file_to_image(img->mlx, img->path, &img->width,
				&img->height);
		mlx_put_image_to_window(img->mlx, img->win, img->img, y, x);
	}
	if (i < 6)
		printelem2(img, i, y, x);
	else
		printelem3(img, i, y, x);
}
