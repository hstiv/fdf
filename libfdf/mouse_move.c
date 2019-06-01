/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:51:35 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/31 13:51:39 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int					mouse_move(int x, int y, t_fdf *param)
{
	if (param->left_mouse == 1 && param->z == 1)
	{
		param->x_add = x;
		param->y_add = y;
	}
	mlx_clear_window(param->mlx_ptr, param->mlx_wind);
	ft_mappaint(param);
	return (0);
}
