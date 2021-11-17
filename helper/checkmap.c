/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:11:55 by agaliste          #+#    #+#             */
/*   Updated: 2021/11/10 21:44:02 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

static void	checkborder(char line)
{
	if (line != '1')
		printerror("Map error: Invalid map borders\n");
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
	if (!(eocur > 0 && pocur == 1 && img->cocur > 0))
		printerror("Map error: Not enought players, escapes or coins\n");
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
			if (i == 0 || j == 0 || j == img->x_size || i == img->y_size)
				checkborder(map[i][j]);
			if (!(map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == '1'
					|| map[i][j] == '0' || map[i][j] == 'E'))
				printerror("Map error: Invalid element on map\n");
		}
	}
	checkelemnts(map, img);
}

void	checkmapcontent(char **map, t_data *img)
{
	if (!map)
		printerror("Map error: No map");
	if (img->x_size == img->y_size)
		printerror("Map error: Square maps are not valid");
	if (checklinelen(map, (*img)) || img->y_size < 3)
		printerror("Map error: Invalid map");
	checkmapcontent2(map, img);
}
