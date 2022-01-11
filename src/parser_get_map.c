/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:18:10 by dason             #+#    #+#             */
/*   Updated: 2022/01/11 22:18:35 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	is_space_nearby(char **map, int x, int y)
{
	int		start_x;
	int		end_x;
	int		start_y;
	int		end_y;

	start_y = y - 1;
	end_y = y + 1;
	while (start_y <= end_y)
	{
		start_x = x - 1;
		end_x = x + 1;
		while (start_x <= end_x)
		{
			if (start_x< 0 || start_y < 0)
				error_exit("The map is not closed.");
			if (map[start_y][start_x] == ' ' || \
				map[start_y][start_x] == '\0')
				error_exit("The map is not closed.");
			start_x++;
		}
		start_y++;
	}
}

static void check_closed_map(char **map)
{
	printf("# check map\n");
	int i;
	int j;

	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == '0')
				is_space_nearby(map, i, j);
		}
	}
}

void get_map(t_info *info, char **tmp_file_data)
{
	char **map;
	char *line;
	int m_i;
	int i;

	m_i = 0;
	map = (char **)ft_calloc(info->map_info.map_height + 1, sizeof(char *));
	if (!map)
		error_exit("Malloc allocation failed.");
	i = -1;
	while (tmp_file_data[++i])
	{
		if (i == 5)
			break;
	}
	while (tmp_file_data[++i])
	{
		line = tmp_file_data[i];
		map[m_i++] = ft_strdup(line);
	}
	info->map_info.map = map;
	check_closed_map(info->map_info.map);
}
