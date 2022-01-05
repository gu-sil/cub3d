/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +	1	uuu#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:58:30 by dason             #+#    #+#             */
/*   Updated: 2022/01/05 14:37:46 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define FLOOR 0
# define WALL 1
# define ITEM 2
# define PLAYER_N 4
# define PLAYER_S 5
# define PLAYER_E 6
# define PLAYER_W 7

typedef struct s_map
{
	int		map_width;
	int		map_height;
	// int		texture_width;
	// int		texture_height;
	char	*no_texture_path;
	char	*so_texture_path;
	char	*we_texture_path;
	char	*ea_texture_path;
	char	*s_texture_path;
	int		floor_color;
	int		ceiling_color;
	char	**map;
}	t_map;

#endif
