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

void			put_man(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->mlx_wind, 5,
	15, (fdf->iso) ? fdf->green : fdf->red, fdf->isometric);
	mlx_string_put(fdf->mlx_ptr, fdf->mlx_wind, 5,
	35, (fdf->par) ? fdf->green : fdf->red, fdf->parallel);
	mlx_string_put(fdf->mlx_ptr, fdf->mlx_wind, 5,
	55, (fdf->rot) ? fdf->green : fdf->red, "      Rotation in 3D");
	mlx_string_put(fdf->mlx_ptr, fdf->mlx_wind, 5,
	75, (fdf->mv) ? fdf->green : fdf->red, fdf->move);
	mlx_string_put(fdf->mlx_ptr, fdf->mlx_wind, 5,
	95, (fdf->hi) ? fdf->green : fdf->red, fdf->height);
	mlx_string_put(fdf->mlx_ptr, fdf->mlx_wind, 5,
	115, (fdf->sl) ? fdf->green : fdf->red, fdf->scale);
}

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
	put_man(mlx_data);
	mlx_loop(mlx_data->mlx_ptr);
}
