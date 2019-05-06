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

static void		iso(int *x, int *y, int z)
{
	int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(30/57.2958);
	*y = (previous_y + previous_x) * sin(30/57.2958) - z;
}

static void		cloner(t_mlx *clone, t_fdf *mlx, int y, int x)
{
	t_mlx	*dot;

	dot = mlx->dot[y][x];
	clone->color = dot->color;
	clone->x = dot->x + mlx->x_add;
	clone->y = dot->y + mlx->y_add;
	clone->z = dot->z;
	if (mlx->iso == 1)
		iso (&clone->x, &clone->y, clone->z);
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
		ft_drawxstr(clone1, clone2, mlx);
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
			ft_drawystr(clone1, clone2, mlx);
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
