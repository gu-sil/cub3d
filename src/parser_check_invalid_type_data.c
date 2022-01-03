/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_invalid_type_data.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:03:30 by dason             #+#    #+#             */
/*   Updated: 2022/01/03 16:09:15 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool check_r(char **map_type)
{
	int		i;
	int		j;

	i = 0;
	while (map_type[++i])
	{
		j = -1;
		while (map_type[i][++j])
		{
			if (!ft_isdigit(map_type[i][j]))
				return (false);
		}
	}
	return (true);
}

static bool check_fc_digit(char **map_type)
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
					return (false);
				}
			}
			if (!(0 <= ft_atoi(tmp[j]) && ft_atoi(tmp[j]) <= 255))
			{
				free_double_pointer(&tmp);
				return (false);
			}
		}
		free_double_pointer(&tmp);
	}
	return (true);
}

static bool	check_texture_file_exist(char **map_type)
{
	char	*pathname;
	int		fd;

	pathname = map_type[1];
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

void	check_invalid_type_data(char **map_type, int type_id)
{
	if (type_id == TYPE_R && \
		check_r(map_type) == false)
		error_exit("Invalid type data.: R");
	if ((type_id == TYPE_NO || type_id == TYPE_SO || \
		type_id == TYPE_WE || type_id == TYPE_EA || \
		type_id == TYPE_S) && \
		check_texture_file_exist(map_type) == false)
		error_exit("Invalid type data.: NO SO WE EA S");

	if ((type_id == TYPE_F || type_id == TYPE_C) && \
		check_fc_digit(map_type) == false)
		error_exit("Invalid type data.: F C");
}
