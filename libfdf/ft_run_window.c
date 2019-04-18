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
	(void)param;
	exit(0);
	return (0);
}

int				key_press(int keycode, t_fdf *param)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 126)
		param->y_add -= CON;
	else if (keycode == 125)
		param->y_add += CON;
	else if (keycode == 124)
		param->x_add += CON;
	else if (keycode == 123)
		param->x_add -= CON;
	else if (keycode == 34)
	{
		param->iso = 1;
		param->par = 0;
	}
	else if (keycode == 35)
	{
		param->iso = 0;
		param->par = 1;
	}
	mlx_clear_window(param->mlx_ptr, param->mlx_wind);
	ft_mappaint(param);
	return (0);
}

/*int				key_release(int keycode, t_fdf *param)
{
	(void)param;
	if (keycode == 53)
		keycode = 0;
	return (0);
}*/

void			ft_run_window(t_fdf *mlx_data)
{
	mlx_data->mlx_ptr = mlx_init();
	mlx_data->mlx_wind = mlx_new_window(mlx_data->mlx_ptr, WIDTH, HEIGHT, FDF);
	ft_mappaint(mlx_data);
	mlx_hook(mlx_data->mlx_wind, 17, (1L << 17), ft_close, mlx_data);
	mlx_hook(mlx_data->mlx_wind, 2, 0, key_press, mlx_data);
	mlx_loop(mlx_data->mlx_ptr);
}
