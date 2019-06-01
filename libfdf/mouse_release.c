/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:51:47 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/31 14:20:00 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int					mouse_release(int button, int x, int y, t_fdf *param)
{
	if (button == 1)
	{
		param->left_mouse = 0;
		if (param->mv)
			param->mv = 0;
		if (param->hi)
			param->hi = 0;
	}
	if (button == 2)
	{
		param->right_mouse = 0;
		if (param->sl)
			param->sl = 0;
	}
	x = 0;
	y = 0;
	mlx_clear_window(param->mlx_ptr, param->mlx_wind);
	ft_mappaint(param);
	put_man(param);
	return (0);
}
