#include "libfdf.h"

static void		iso(int *x, int *y, int z)
{
	int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = (previous_y + previous_x) * sin(0.523599) - z;
}

void			ft_drawxstr(t_mlx *d0, t_mlx *d1, t_fdf *mlx)
{
	int			x;
	int			y;
	int			delx;
	int			dely;
	int			diry;
	int			err;
	int			derr;

	x = d0->x + mlx->x_add;
	y = d0->y + mlx->y_add;
	dely = 0;
	(d1->x - d0->x > 0) ? (delx = d1->x - d0->x) : (delx = d0->x - d1->x);
	(d1->y - d0->y > 0) ? (dely = d1->y - d0->y) : (dely = d0->y - d1->y);
	err = 0;
	derr = dely;
	diry = d1->y - d0->y;
	(diry > 0) ? (diry = 1) : 0;
	(diry < 0) ? (diry = -1) : 0;
	while (x <= (d1->x + mlx->x_add))
	{
		(mlx->iso == 1) ? iso(&x, &y, d1->z) : 0;
		if (!(mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_wind, x, y, d1->color)))
			return ;
		err = err + derr;
		if (2 * err >= delx)
		{
			y += diry;
			err -= delx;
		}
		x++;
	}
}

static void			ft_drawystr(t_mlx *d0, t_mlx *d1, t_fdf *mlx)
{
	int			x;
	int			y;
	int			delx;
	int			dely;
	int			dirx;
	int			err;
	int			derr;

	x = d0->x + mlx->x_add;
	y = d0->y + mlx->y_add;
	(d1->x - d0->x > 0) ? (delx = d1->x - d0->x) : (delx = d0->x - d1->x);
	(d1->y - d0->y > 0) ? (dely = d1->y - d0->y) : (dely = d0->y - d1->y);
	err = 0;
	derr = delx;
	dirx = d1->x - d0->x;
	(dirx > 0) ? (dirx = 1) : 0;
	(dirx < 0) ? (dirx = -1) : 0;
	while (y <= (d1->y + mlx->y_add))
	{
		(mlx->iso == 1) ? iso(&x, &y, d1->z) : 0;
		if (!(mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_wind, x, y, d0->color)))
			return ;
		err = err + derr;
		if (2 * err >= dely)
		{
			x += dirx;
			err -= dely;
		}
		y++;
	}
}

static void		ft_print_hor(t_mlx **dot, t_fdf *mlx)
{
	int			x;

	x = 0;
	while (dot[x] != NULL && dot[x + 1] != NULL)
	{
		ft_drawxstr(dot[x], dot[x + 1], mlx);
		x++;
	}
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
		ft_print_hor(dot[y], mlx_data);
		y++;
	}
	y = 0;
	while (dot[y][x])
	{
		while (dot[y + 1] != NULL && dot[y][x] != NULL)
		{
			ft_drawystr(dot[y][x], dot[y + 1][x], mlx_data);
			y++;
		}
		y = 0;
		x++;
	}
}