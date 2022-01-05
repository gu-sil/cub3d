/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_invalid_type_data.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:03:30 by dason             #+#    #+#             */
/*   Updated: 2022/01/05 18:18:08 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_type_data_r(char **map_type)
{
	int		i;
	int		j;
	int		width;
	int		height;

	i = 0;
	while (map_type[++i])
	{
		j = -1;
		while (map_type[i][++j])
		{
			if (!ft_isdigit(map_type[i][j]))
				error_exit("Invalid type data - It's not a number: R");
		}
	}
	width = ft_atoi(map_type[1]);
	height = ft_atoi(map_type[2]);
	if (!(320 <= width && width <= 4096) || \
		!(200 <= height && height <= 2160))
		error_exit("Invalid type data - Numbers are out of range: R");
}

void	check_type_data_texture(char **map_type)
{
	char	*pathname;
	int		fd;

	pathname = map_type[1];
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		error_exit("invalid type data - It's not a number: NO SO WE EA S");
	close(fd);
}

static void	check_fc_digit(char **map_type)
{
	char	**tmp;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (map_type[++i])
	{
		tmp = ft_split(map_type[i], ',');
		j = -1;
		while (tmp[++j])
		{
			k = -1;
			while (tmp[j][++k])
			{
				if (!ft_isdigit(tmp[j][k]))
				{
					free_double_pointer(&tmp);
					error_exit("Invalid type data - It's not a number: F C");
				}
			}
		}
		free_double_pointer(&tmp);
	}
}

static void	check_fc_range(char **map_type)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	while (map_type[++i])
	{
		tmp = ft_split(map_type[i], ',');
		j = -1;
		while (tmp[++j])
		{
			if (!(0 <= ft_atoi(tmp[j]) && ft_atoi(tmp[j]) <= 255))
			{
				free_double_pointer(&tmp);
				error_exit("Invalid type data - Numbers are out of range: F C");
			}
		}
		free_double_pointer(&tmp);
	}
}

void	check_type_data_fc(char **map_type)
{
	check_fc_digit(map_type);
	check_fc_range(map_type);
}