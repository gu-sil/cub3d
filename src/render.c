/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun <hyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:18:57 by hyun              #+#    #+#             */
/*   Updated: 2022/01/17 14:25:48 by hyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "stdio.h"

t_vec2	cal_dir(t_info *info, int camera_step)
{
	double	cam_x;
	t_vec2	dir;
	t_vec2	left_corner;

	cam_x = 2 * (double)camera_step / (double)WIN_WIDTH;

	left_corner = v2_minus(info->p_dir, info->p_fov);
	dir = v2_plus(left_corner, v2_scala(cam_x, info->p_fov));
	return (dir);
}

int	draw_line(t_img *img, int *line, int x)
{
	int	y;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		img->data[y * WIN_WIDTH + x] = line[y];
	}
	return (0);
}



int	render(t_info *info)
{
	int		w;
	t_vec2	dir;
	t_img	*img;
	int		*line;

	img = (t_img *)malloc(sizeof(t_img));
	img->img_ptr = mlx_new_image(info->mlx_info.mlx, WIN_WIDTH, WIN_HEIGHT);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l, &img->endian);
	w = -1;
	while (++w < WIN_WIDTH)
	{
		dir = cal_dir(info, w);
		printf("dir= %f, %f\n", dir.y, dir.x);
		line = raycast(info, dir);
		draw_line(img, line, w);
	}
	mlx_put_image_to_window(info->mlx_info.mlx, info->mlx_info.mlx_win, img->img_ptr, 0, 0);
	return (0);
}
