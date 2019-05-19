#include "libfdf.h"

t_mlx		*ft_new_dot()
{
	t_mlx	*dot;

	dot = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	if (dot)
	{
		dot->color = 0;
		dot->x = 0;
		dot->y = 0;
		dot->z = 0;
		dot->col_bool = 0;
	}
	return (dot);
}

t_fdf		*ft_new_fdf()
{
	t_fdf	*data;

	data = (t_fdf *)ft_memalloc(sizeof(t_fdf));
	if (data)
	{
		data->dot = NULL;
		data->mlx_wind = NULL;
		data->mlx_ptr = NULL;
		data->mlx_img = NULL;
		data->x_add = 70;
		data->y_add = 70;
		data->iso = 0;
		data->par = 1;
		data->tall = 1;
		data->l = 10;
		data->col_ch = 100;
	}
	return (data);
}
