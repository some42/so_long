/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 03:10:16 by agaliste          #+#    #+#             */
/*   Updated: 2021/11/08 19:51:15 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

static void	drawground(t_data *img, size_t i, size_t x, size_t y)
{
	size_t	j;

	while (img->map[++i])
	{
		j = -1;
		y = 0;
		while (img->map[i][++j])
		{
			if (img->map[i][j] == '1')
				printelem(img, 4, y, x);
			else
				printelem(img, 5, y, x);
			if (img->map[i][j] == 'P')
			{
				img->pos[0] = i;
				img->pos[1] = j;
				img->p_x = x;
				img->p_y = y;
			}
			y += 32;
		}
		x += 32;
	}
}

static void	drawelse(t_data img, size_t i, size_t x, size_t y)
{
	size_t	j;

	while (img.map[++i])
	{
		j = -1;
		y = 0;
		while (img.map[i][++j])
		{
			if (img.map[i][j] == '1')
				printelem(&img, 0, y, x);
			if (img.map[i][j] == 'P')
				printelem(&img, 1, y, x);
			if (img.map[i][j] == 'C')
				printelem(&img, 2, y, x);
			if (img.map[i][j] == 'E')
				printelem(&img, 3, y, x);
			y += 32;
		}
		x += 32;
	}
}

static void	drawupdt(t_data img, size_t arg, size_t x, size_t y)
{
	size_t	j;
	size_t	i;

	i = -1;
	while (img.map[++i])
	{
		j = -1;
		y = 0;
		while (img.map[i][++j])
		{
			if (i == img.ppos[0] && j == img.ppos[1])
				printelem(&img, 5, y, x);
			if (img.map[i][j] == 'P')
				printelem(&img, arg, y, x);
			y += 32;
		}
		x += 32;
	}
}

void	changesprt(t_data img, size_t arg, size_t x, size_t y)
{
	size_t	j;
	size_t	i;

	i = -1;
	while (img.map[++i])
	{
		j = -1;
		y = 0;
		while (img.map[i][++j])
		{
			if (i == img.pos[0] && j == img.pos[1])
				printelem(&img, 5, y, x);
			if (img.map[i][j] == 'P')
				printelem(&img, arg, y, x);
			y += 32;
		}
		x += 32;
	}
}

void	draw(t_data *img, int arg)
{
	if (arg == 0)
	{
		drawground(img, -1, 0, 0);
		drawelse((*img), -1, 0, 0);
	}
	else
		drawupdt(*img, arg, 0, 0);
}
