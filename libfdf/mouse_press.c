/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:51:05 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/31 13:52:32 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int				mouse_press(int button, int x, int y, t_fdf *param)
{
	if (button == 1)
		param->left_mouse = 1;
	if (button == 2)
		param->right_mouse = 1;
	if (param->left_mouse == 1 && param->z == 1)
	{
		param->x_add = x;
		param->y_add = y;
	}
	if (param->left_mouse == 1 && button == 4)
		param->tall += 1;
	if (param->left_mouse == 1 && button == 5)
		param->tall -= 1;
	if (param->right_mouse == 1 && button == 4)
		param->l += 5;
	if (param->right_mouse && button == 5)
		param->l -= 5;
	mlx_clear_window(param->mlx_ptr, param->mlx_wind);
	ft_mappaint(param);
	return (0);
}
