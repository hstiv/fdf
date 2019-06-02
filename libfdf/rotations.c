/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 18:20:46 by hstiv             #+#    #+#             */
/*   Updated: 2019/06/01 18:20:48 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void				x_rotate(t_mlx *dot, t_fdf *f)
{
	int				y;
	int				x;
	int				z;

	y = dot->y;
	x = dot->x;
	z = dot->z;
	dot->y = (y * cos(f->x / 57.2958)) + (z * sin(f->x / 57.2958)) + f->y_add;
	dot->z = -(y * sin(f->x / 57.2958)) + (z * cos(f->x / 57.2958));
}

void				y_rotate(t_mlx *dot, t_fdf *f)
{
	int				y;
	int				x;
	int				z;

	y = dot->y;
	x = dot->x;
	z = dot->z;
	dot->x = (x * cos(f->y / 57.2958)) + (z * sin(f->y / 57.2958)) + f->x_add;
	dot->z = -(x * sin(f->y / 57.2958)) + (z * cos(f->y / 57.2958));
}

void				rotate(t_mlx *dot, t_fdf *f, int x, int y)
{
	dot->x = x * f->l;
	dot->y = y * f->l;
	y_rotate(dot, f);
	x_rotate(dot, f);
}
