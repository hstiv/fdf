/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:36:45 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/06 17:36:48 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void			ft_drawxstr(t_mlx *d0, t_mlx *d1, t_fdf *mlx)
{
	int			x;
	int			y;
	int			delx;
	int			dely;
	int			diry;
	int			err;
	int			derr;

	x = d0->x;
	y = d0->y;
	dely = 0;
	(d1->x - d0->x > 0) ? (delx = d1->x - d0->x) : (delx = d0->x - d1->x);
	(d1->y - d0->y > 0) ? (dely = d1->y - d0->y) : (dely = d0->y - d1->y);
	err = 0;
	derr = dely;
	diry = d1->y - d0->y;
	(diry > 0) ? (diry = 1) : 0;
	(diry < 0) ? (diry = -1) : 0;
	while (x <= d1->x)
	{
		if (!(mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_wind, x, y, d1->color)))
			return ;
		err = err + derr;
		if (2 * err >= delx)
		{
			y += diry;
			err -= delx;
		}
		x++;
	}
}

void			ft_drawystr(t_mlx *d0, t_mlx *d1, t_fdf *mlx)
{
	int			x;
	int			y;
	int			delx;
	int			dely;
	int			dirx;
	int			err;
	int			derr;

	x = d0->x;
	y = d0->y;
	(d1->x - d0->x > 0) ? (delx = d1->x - d0->x) : (delx = d0->x - d1->x);
	(d1->y - d0->y > 0) ? (dely = d1->y - d0->y) : (dely = d0->y - d1->y);
	err = 0;
	derr = delx;
	dirx = d1->x - d0->x;
	(dirx > 0) ? (dirx = 1) : 0;
	(dirx < 0) ? (dirx = -1) : 0;
	while (y <= d1->y)
	{
		if (!(mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_wind, x, y, d0->color)))
			return ;
		err = err + derr;
		if (2 * err >= dely)
		{
			x += dirx;
			err -= dely;
		}
		y++;
	}
}
