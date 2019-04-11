#include "libfdf.h"

t_mlx		*ft_new_dot()
{
	t_mlx	*dot;

	dot = (t_mlx *)malloc(sizeof(t_mlx));
	if (dot)
	{
		dot->color = 0;
		dot->x = 0;
		dot->y = 0;
		dot->z = 0;
	}
	return (dot);
}

t_fdf		ft_new_fdf()
{
	t_fdf	*data;

	data = (t_fdf *)malloc(sizeof(t_fdf))
	if (data)
	{
		data->dot = NULL;
		data->mlx_wind = NULL;
		data->mlx_ptr = NULL;
	}
	return (data);
}
