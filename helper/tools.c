/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 02:18:36 by agaliste          #+#    #+#             */
/*   Updated: 2021/11/18 14:11:37 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

size_t	ft_strnllen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

void	printerror(char *error)
{
	write(1, "Error\n", 7);
	write(1, error, ft_strlen(error));
	write(1, "\n", 1);
	exit(1);
}

void	printmap(char **map)
{
	int	i;
	int	j;

	i = -1;
	if (!map)
		exit(1);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] && map[i][j] != '\n')
			write(1, &map[i][j], 1);
		write(1, "\n", 1);
	}
}

int	prgclose(int keycode, void *vars)
{
	(void)keycode;
	(void)vars;
	exit(0);
}

size_t	getleny(char **str)
{
	int	i;

	i = 0;
	if (!str)
		printerror("Failed getting Y length");
	while (str[i] != NULL && str[i][0] != '\n')
		i++;
	return (i);
}
