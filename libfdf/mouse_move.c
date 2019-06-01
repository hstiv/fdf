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
	if (param->left_mouse && param->right_mouse)
	{
		param->x_add = x;
		param->y_add = y;
		param->mv = 1;
	}
	if (param->left_mouse && param->rot && param->c)
		param->x++;
	if (param->right_mouse && param->rot && param->c)
		param->y++;
	if (param->left_mouse && param->rot && param->v)
		param->x--;
	if (param->right_mouse && param->rot && param->v)
		param->y--;
	mlx_clear_window(param->mlx_ptr, param->mlx_wind);
	ft_mappaint(param);
	put_man(param);
	return (0);
}
