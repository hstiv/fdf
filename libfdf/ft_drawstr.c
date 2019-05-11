/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:37:01 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/06 17:37:04 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static void		iso(t_mlx *clone, int x, int y, t_fdf *mlx)
{
	int			prev_x;
    int 		prev_y;

	prev_x = x * mlx->l;
    prev_y = y * mlx->l;
    clone->x = (prev_x - prev_y) * cos(30 / 57.2958) + mlx->x_add;
	clone->y = (prev_y + prev_x) * sin(30 / 57.2958) + (mlx->y_add - clone->z);
}

static void		cloner(t_mlx *clone, t_fdf *mlx, int y, int x)
{
	t_mlx	*dot;

	dot = mlx->dot[y][x];
	clone->color = dot->color;
	clone->z = (dot->z) ? (dot->z + mlx->tall) : 0;
	if (mlx->iso == 0)
	{
		clone->x = x * mlx->l + mlx->x_add;
		clone->y = y * mlx->l + (mlx->y_add - clone->z);
//		clone->y -= clone->z;
	}
	clone->z = (dot->z > 0) ? dot->z + mlx->tall : 0;
	if (mlx->iso == 1)
		iso (clone, x, y, mlx);
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
