/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:43:10 by agaliste          #+#    #+#             */
/*   Updated: 2021/11/18 15:12:38 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>

/*
** STRUCTS
*/

typedef struct s_data {
	void	*img;
	char	*addr;
	void	*win;
	void	*mlx;
	char	*path;
	int		width;
	int		height;
	char	**map;
	size_t	pos[2];
	size_t	ppos[2];
	int		coin;
	int		moves;
	int		cocur;
	size_t	x_size;
	size_t	y_size;
	int		p_x;
	int		p_y;
}				t_data;

/*
** Main func
*/

void	parseinput(const int argc, const char *argv);
char	**parsemap(int fd);

/*
** Helper functions
*/

void	printerror(char *error);
int		prgclose(int keycode, void *vars);
size_t	getleny(char **str);
void	moveup(t_data *img);
void	moveleft(t_data *img);
void	movedown(t_data *img);
void	moveright(t_data *img);
int		checklines(char **line);
size_t	ft_strnllen(const char *str);

/*
** Checks functions
*/

int		checklinelen(char **line, t_data img);
int		checkbujero(t_data img, int i);
void	checkcoin(t_data *img, int i);

/*
** Maptools functions
*/

void	draw(t_data *img, int arg);
void	changesprt(t_data img, size_t arg, size_t x, size_t y);
int		odifymap(t_data *img, int i);
int		modifymap(t_data *img, int i);

/*
** Checkmap functions
*/

void	checkmapcontent(char **line, t_data *img);

/*
** Printelem functions
*/

void	printelem(t_data *img, int i, size_t y, size_t x);

/*
** MLX FUNCTIONS
*/

int		key_hook(int keycode, void *vars);

#endif