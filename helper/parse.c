/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 22:09:49 by agaliste          #+#    #+#             */
/*   Updated: 2021/11/18 14:11:23 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	parseinput(const int argc, const char *argv)
{
	char	*tmp;

	if (argc > 2)
		printerror("Argument: Only one argument is valid");
	if (argc < 2)
		printerror("Argument: Please provide a .ber map file");
	tmp = ft_strnstr(ft_strrchr(argv, '.'), ".ber", 4);
	if (tmp && ft_strlen(tmp) == 4)
		return ;
	else
		printerror("Argument: Only .ber map file accepted");
}

char	**parsemap(int fd)
{
	char	**map;
	char	*line;
	int		i;
	int		len;

	i = 1;
	if (!fd || fd < 0 || fd > 256)
		printerror("Map: Map does not exist");
	line = get_next_line(fd);
	if (!line || line[0] != '1')
		printerror("Map: Invalid map");
	len = ft_strnllen(line);
	if (len < 3)
		printerror("Map: Invalid map");
	map = ft_calloc(1, sizeof(char *) * len);
	map[0] = line;
	while (line)
	{
		line = get_next_line(fd);
		map = (char **) ft_realloc(map, sizeof(char *) * len * i);
		map[i++] = line;
	}
	return (map);
}
