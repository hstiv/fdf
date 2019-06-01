/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:29:09 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/31 14:29:10 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static void		x_and_y(int keycode, t_fdf *param)
{
	if (keycode == 53)
		ft_close((void *)param);
	if (keycode == 13)
		param->y_add -= CON;
	if (keycode == 1)
		param->y_add += CON;
	if (keycode == 2)
		param->x_add += CON;
	if (keycode == 0)
		param->x_add -= CON;
	if (keycode == 6)
		param->z = 1;
}

static void		movement_col(int keycode, t_fdf *param)
{
	if (keycode == 124)
		param->l += 2;
	if (keycode == 123)
		param->l -= 2;
	if (keycode == 126)
		param->tall += 2;
	if (keycode == 125)
		param->tall -= 2;
	if (keycode == 116)
		param->col_ch += 100;
	if (keycode == 121)
		param->col_ch -= 100;
}

static void		iso_par(int keycode, t_fdf *param)
{
	if (keycode == 34)
	{
		param->iso = 1;
		param->par = 0;
	}
	if (keycode == 35)
	{
		param->iso = 0;
		param->par = 1;
	}
}

int				key_release(int keycode, t_fdf *param)
{
	if (keycode == 6)
		param->z = 0;
	return (0);
}

int				key_press(int keycode, t_fdf *param)
{
	x_and_y(keycode, param);
	iso_par(keycode, param);
	movement_col(keycode, param);
	mlx_clear_window(param->mlx_ptr, param->mlx_wind);
	ft_mappaint(param);
	return (0);
}
