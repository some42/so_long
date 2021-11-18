/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:11:55 by agaliste          #+#    #+#             */
/*   Updated: 2021/11/18 14:43:43 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

static void	checkborder(char line)
{
	if (line != '1')
		printerror("Map: Invalid map borders\n");
}

static void	checkelemnts(char **map, t_data *img)
{
	size_t	i;
	size_t	j;
	int		eocur;
	int		pocur;

	i = -1;
	eocur = 0;
	pocur = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				pocur += 1;
			if (map[i][j] == 'C')
				img->cocur += 1;
			if (map[i][j] == 'E')
				eocur += 1;
		}
	}
	if (!(eocur == 1 && pocur == 1 && img->cocur > 0))
		printerror("Map: Only 1 Escape, 1 Player and at least 1 coin allowed\n");
}

static void	checkmapcontent2(char **map, t_data *img)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] != '\n' && map[i][j] != '\0')
		{
			if (i == 0 || j == 0 || j == img->x_size - 1
				|| i == img->y_size - 1)
				checkborder(map[i][j]);
			if (!(map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == '1'
					|| map[i][j] == '0' || map[i][j] == 'E'))
				printerror("Map: Invalid element on map\n");
		}
	}
	checkelemnts(map, img);
}

void	checkmapcontent(char **map, t_data *img)
{
	if (!map)
		printerror("Map: No map");
	if (img->x_size == img->y_size)
		printerror("Map: Square maps are not valid");
	if (checklinelen(map, (*img)) || img->y_size < 3)
		printerror("Map: Invalid map");
	checkmapcontent2(map, img);
}
