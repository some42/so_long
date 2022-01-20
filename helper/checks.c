/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 23:30:07 by agaliste          #+#    #+#             */
/*   Updated: 2022/01/20 12:42:25 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int
	checklinelen(char **line, t_data img)
{
	size_t	i;

	i = -1;
	while (++i < img.y_size)
	{
		if (ft_strnllen(line[i]) != img.x_size)
			return (1);
	}
	return (0);
}

int
	checkbujero(t_data img, int i)
{
	if (i == 0 && img.map[img.pos[0] - 1][img.pos[1]] == 'E')
		return (0);
	if (i == 1 && img.map[img.pos[0] + 1][img.pos[1]] == 'E')
		return (0);
	if (i == 2 && img.map[img.pos[0]][img.pos[1] - 1] == 'E')
		return (0);
	if (i == 3 && img.map[img.pos[0]][img.pos[1] + 1] == 'E')
		return (0);
	return (1);
}

void
	checkcoin(t_data *img, int i)
{
	if (i == 0 && img->map[img->pos[0] - 1][img->pos[1]] == 'C')
	{
		img->coin += 1;
		img->map[img->pos[0] - 1][img->pos[1]] = '0';
	}
	if (i == 1 && img->map[img->pos[0] + 1][img->pos[1]] == 'C')
	{
		img->coin += 1;
		img->map[img->pos[0] + 1][img->pos[1]] = '0';
	}
	if (i == 2 && img->map[img->pos[0]][img->pos[1] - 1] == 'C')
	{
		img->coin += 1;
		img->map[img->pos[0]][img->pos[1] - 1] = '0';
	}
	if (i == 3 && img->map[img->pos[0]][img->pos[1] + 1] == 'C')
	{
		img->coin += 1;
		img->map[img->pos[0]][img->pos[1] + 1] = '0';
	}
}
