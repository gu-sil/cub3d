/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun <hyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:58:30 by dason             #+#    #+#             */
/*   Updated: 2022/01/17 09:45:59 by hyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define FLOOR '0'
# define WALL '1'
# define SPACE ' '
# define PLAYER '3'

typedef struct s_map
{
	int		texture_width;
	int		texture_height;
	void	*no_texture;
	void	*so_texture;
	void	*we_texture;
	void	*ea_texture;
	int		floor_color;
	int		ceiling_color;
	int		map_width;
	int		map_height;
	char	**map;
}	t_map;

#endif
