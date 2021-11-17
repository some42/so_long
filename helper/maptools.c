/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:28:38 by agaliste          #+#    #+#             */
/*   Updated: 2021/11/07 21:30:06 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

static void	mup(t_data *img, char aux)
{
	img->map[img->pos[0]][img->pos[1]] = img->map[img->pos[0] - 1][img->pos[1]];
	img->map[img->pos[0] - 1][img->pos[1]] = aux;
	img->ppos[0] = img->pos[0];
	img->ppos[1] = img->pos[1];
	img->pos[0] -= 1;
}

static void	mdown(t_data *img, char aux)
{
	img->map[img->pos[0]][img->pos[1]] = img->map[img->pos[0] + 1][img->pos[1]];
	img->map[img->pos[0] + 1][img->pos[1]] = aux;
	img->ppos[0] = img->pos[0];
	img->ppos[1] = img->pos[1];
	img->pos[0] += 1;
}

static void	mleft(t_data *img, char aux)
{
	img->map[img->pos[0]][img->pos[1]] = img->map[img->pos[0]][img->pos[1] - 1];
	img->map[img->pos[0]][img->pos[1] - 1] = aux;
	img->ppos[0] = img->pos[0];
	img->ppos[1] = img->pos[1];
	img->pos[1] -= 1;
}

static void	mright(t_data *img, char aux)
{
	img->map[img->pos[0]][img->pos[1]] = img->map[img->pos[0]][img->pos[1] + 1];
	img->map[img->pos[0]][img->pos[1] + 1] = aux;
	img->ppos[0] = img->pos[0];
	img->ppos[1] = img->pos[1];
	img->pos[1] += 1;
}

int	modifymap(t_data *img, int i)
{
	char	aux;

	checkcoin(img, i);
	if (!(checkbujero((*img), i)))
	{
		if (img->coin == img->cocur)
			exit(0);
	}
	aux = img->map[img->pos[0]][img->pos[1]];
	if (i == 0 && img->map[img->pos[0] - 1][img->pos[1]] != '1'
		&& img->map[img->pos[0] - 1][img->pos[1]] != 'E')
		mup(img, aux);
	else if (i == 1 && img->map[img->pos[0] + 1][img->pos[1]] != '1'
		&& img->map[img->pos[0] + 1][img->pos[1]] != 'E')
		mdown(img, aux);
	else if (i == 2 && img->map[img->pos[0]][img->pos[1] - 1] != '1'
		&& img->map[img->pos[0]][img->pos[1] - 1] != 'E')
		mleft(img, aux);
	else if (i == 3 && img->map[img->pos[0]][img->pos[1] + 1] != '1'
		&& img->map[img->pos[0]][img->pos[1] + 1] != 'E')
		mright(img, aux);
	else
		return (1);
	return (0);
}
