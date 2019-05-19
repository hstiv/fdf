/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:11:41 by mwuckert          #+#    #+#             */
/*   Updated: 2019/04/12 19:25:15 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static int		ft_close(void *param)
{
	t_fdf		*tmp;

	tmp = (t_fdf *)param;
	exit(0);
	return (0);
}

int				key_press(int keycode, t_fdf *param)
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
	mlx_clear_window(param->mlx_ptr, param->mlx_wind);
	ft_mappaint(param);
	return (0);
}

int				mouse(int keycode, t_fdf *mlx)
{
	if (keycode == 4)
		mlx->tall += 10;
	else if (keycode == 5)
		mlx->tall -= 10;
	return (0);
}

void			ft_run_window(t_fdf *mlx_data)
{
	mlx_data->mlx_ptr = mlx_init();
	mlx_data->mlx_wind = mlx_new_window(mlx_data->mlx_ptr, WIDTH, HEIGHT, FDF);
	ft_mappaint(mlx_data);
	mlx_hook(mlx_data->mlx_wind, 17, (1L << 17), ft_close, mlx_data);
	mlx_hook(mlx_data->mlx_wind, 2, 0, key_press, mlx_data);
	mlx_hook(mlx_data->mlx_wind, 4, 0, mouse, mlx_data);
	mlx_loop(mlx_data->mlx_ptr);
}
