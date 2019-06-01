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

int				ft_close(void *param)
{
	t_fdf		*tmp;

	tmp = (t_fdf *)param;
	exit(0);
	return (0);
}

void			ft_run_window(t_fdf *mlx_data)
{
	mlx_data->mlx_ptr = mlx_init();
	mlx_data->mlx_wind = mlx_new_window(mlx_data->mlx_ptr, WIDTH, HEIGHT, FDF);
	ft_mappaint(mlx_data);
	mlx_hook(mlx_data->mlx_wind, 17, (1L << 17), ft_close, mlx_data);
	mlx_hook(mlx_data->mlx_wind, 2, 0, key_press, mlx_data);
	mlx_hook(mlx_data->mlx_wind, 3, 0, key_release, mlx_data);
	mlx_hook(mlx_data->mlx_wind, 4, 0, mouse_press, mlx_data);
	mlx_hook(mlx_data->mlx_wind, 6, 0, mouse_move, mlx_data);
	mlx_hook(mlx_data->mlx_wind, 5, 0, mouse_release, mlx_data);
	mlx_loop(mlx_data->mlx_ptr);
}
