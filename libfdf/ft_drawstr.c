/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:37:01 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/31 13:54:29 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static void		iso(t_mlx *clone, int x, int y, t_fdf *mlx)
{
	int			prev_x;
	int			prev_y;

	prev_x = x * mlx->l;
	prev_y = y * mlx->l;
	clone->x = (prev_x - prev_y) * cos(30 / 57.2958) + mlx->x_add;
	clone->y = (prev_y + prev_x - clone->z) * sin(30 / 57.2958) + mlx->y_add;
}

static void		cloner(t_mlx *clone, t_fdf *mlx, int y, int x)
{
	clone->color = mlx->dot[y][x]->color;
	if (!mlx->dot[y][x]->col_bool)
		clone->color += mlx->col_ch;
	clone->z = mlx->dot[y][x]->z;
	clone->z *= mlx->tall;
	if (!mlx->iso && !mlx->rot)
	{
		clone->x = x * mlx->l + mlx->x_add;
		clone->y = y * mlx->l + (mlx->y_add - clone->z);
	}
	if (mlx->iso == 1 && !mlx->rot)
		iso(clone, x, y, mlx);
	if (mlx->rot == 1)
		rotate(clone, mlx, x, y);
}

static void		ft_print_hor(t_mlx **dot, t_fdf *mlx, int y)
{
	int			x;
	t_mlx		*clone1;
	t_mlx		*clone2;

	x = 0;
	clone1 = ft_new_dot();
	clone2 = ft_new_dot();
	while (dot[x] != NULL && dot[x + 1] != NULL)
	{
		cloner(clone1, mlx, y, x);
		cloner(clone2, mlx, y, x + 1);
		ft_bresenham(clone1, clone2, mlx);
		x++;
	}
	free(clone1);
	free(clone2);
}

static void		ft_print_ver(t_mlx ***dot, t_fdf *mlx)
{
	int			y;
	int			x;
	t_mlx		*clone1;
	t_mlx		*clone2;

	x = 0;
	clone1 = ft_new_dot();
	clone2 = ft_new_dot();
	y = 0;
	while (dot[y][x])
	{
		y = 0;
		while (dot[y + 1] != NULL && dot[y][x] != NULL)
		{
			cloner(clone1, mlx, y, x);
			cloner(clone2, mlx, y + 1, x);
			ft_bresenham(clone1, clone2, mlx);
			y++;
		}
		x++;
	}
	free(clone1);
	free(clone2);
}

void			ft_mappaint(t_fdf *mlx_data)
{
	int			y;
	t_mlx		***dot;
	int			x;

	y = 0;
	x = 0;
	dot = mlx_data->dot;
	while (dot[y] != NULL)
	{
		ft_print_hor(dot[y], mlx_data, y);
		y++;
	}
	ft_print_ver(dot, mlx_data);
}
