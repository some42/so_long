/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 03:35:03 by agaliste          #+#    #+#             */
/*   Updated: 2022/01/20 12:40:13 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void
	moveup(t_data *img)
{
	if (!modifymap(img, 0))
	{
		draw(img, 1);
		img->moves += 1;
		write(1, "Moves: ", 8);
		ft_putnbr_fd(img->moves, 1);
		write(1, "\n", 1);
	}
	else
		changesprt((*img), 1, 0, 0);
}

void
	movedown(t_data *img)
{
	if (!modifymap(img, 1))
	{
		draw(img, 6);
		img->moves += 1;
		write(1, "Moves: ", 8);
		ft_putnbr_fd(img->moves, 1);
		write(1, "\n", 1);
	}
	else
		changesprt((*img), 6, 0, 0);
}

void
	moveleft(t_data *img)
{
	if (!modifymap(img, 2))
	{
		draw(img, 7);
		img->moves += 1;
		write(1, "Moves: ", 8);
		ft_putnbr_fd(img->moves, 1);
		write(1, "\n", 1);
	}
	else
		changesprt((*img), 7, 0, 0);
}

void
	moveright(t_data *img)
{
	if (!modifymap(img, 3))
	{
		draw(img, 8);
		img->moves += 1;
		write(1, "Moves: ", 8);
		ft_putnbr_fd(img->moves, 1);
		write(1, "\n", 1);
	}
	else
		changesprt((*img), 8, 0, 0);
}
