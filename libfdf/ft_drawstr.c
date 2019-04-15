#include "libfdf.h"

void			ft_drawstr(t_mlx *d0, t_mlx *d1, t_fdf *mlx)
{
	int			x;
	int			y;
	int			delx;
	int			dely;
	int			diry;
	int			err;
	int			derr;

	x = d0->x;
	y = d0->y;
	dely = 0;
	(d1->x - d0->x > 0) ? (delx = d1->x - d0->x) : (delx = d0->x - d1->x);
	(d1->y - d0->y > 0) ? (dely = d1->y - d0->y) : (dely = d0->y - d1->y);
	err = 0;
	derr = dely;
	diry = d1->y - d0->y;
	(diry > 0) ? (diry = 1) : 0;
	(diry < 0) ? (diry = -1) : 0;
	while (x <= d1->x)
	{
		if (!(mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_wind, x, y, COLOR)))
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

	x = d0->x;
	y = d0->y;
	(d1->x - d0->x > 0) ? (delx = d1->x - d0->x) : (delx = d0->x - d1->x);
	(d1->y - d0->y > 0) ? (dely = d1->y - d0->y) : (dely = d0->y - d1->y);
	err = 0;
	derr = delx;
	dirx = d1->x - d0->x;
	(dirx > 0) ? (dirx = 1) : 0;
	(dirx < 0) ? (dirx = -1) : 0;
	while (y <= d1->y)
	{
		if (!(mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_wind, x, y, COLOR)))
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
		ft_drawstr(dot[x], dot[x + 1], mlx);
		x++;
	}
}

void			ft_mappaint(t_fdf *mlx_data)
{
	int			y;
	t_mlx		***dot;
	int			x;
	int			p;

	y = 0;
	x = 0;
	dot = mlx_data->dot;
	while (dot[y] != NULL)
	{
		ft_print_hor(dot[y], mlx_data);
		y++;
	}
	p = y;
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