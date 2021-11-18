/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 23:06:04 by agaliste          #+#    #+#             */
/*   Updated: 2021/11/18 14:43:03 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	key_hook(int keycode, void *var)
{
	t_data	*img;

	img = (t_data *)var;
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->win);
		mlx_destroy_image(img->mlx, img->img);
		exit (0);
	}
	if (keycode == 13 || keycode == 126)
		moveup(img);
	if (keycode == 1 || keycode == 125)
		movedown(img);
	if (keycode == 0 || keycode == 123)
		moveleft(img);
	if (keycode == 2 || keycode == 124)
		moveright(img);
	return (0);
}
