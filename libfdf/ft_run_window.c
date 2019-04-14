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

void	ft_run_window(t_fdf *mlx_data)
{
	mlx_data->mlx_ptr = mlx_init();
	mlx_data->mlx_wind = mlx_new_window(mlx_data->mlx_ptr, WIDTH, HEIGHT, FDF);
	ft_mappaint(mlx_data);
	mlx_loop(mlx_data->mlx_ptr);
}
