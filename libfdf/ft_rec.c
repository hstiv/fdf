#include "libfdf.h"

static void		ft_width(char *s, int *i, int y, t_mlx *dot)
{
	char		str[11];
	char		color[30];
	int		l;
	t_mlx		*tmp;

	l = 0;
	dot->y = y;
	while (s[*i] != '32' && s[*i] != '\n'
			&& s[*i] != '\0' && s[*i] != ',')
	{
		str[l] = s[*i];
		l++;
		*(i)++;
	}
	dot->z = ft_atoi(str);
	if (s[*i] != ',' )
		color[0] = 0;
}

void			ft_rec(t_fdf *mlx_data, char *map)
{
	int			i;
	int			x;
	int			y;
	int			p;
	t_mlx			*dot;

	i = 0;
	x = 0;
	y = 0;
	p = 0;
	dot = mlx_data->dot;
	while (map[i] !='\n' && map[i++] != '\0')
		p++;
	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			y++;
		if (map[i] != ',' && map[i] != '\n' && map[i] != ' ' && map[i] != '\0'
			&& (map[i + 1] >= 48 || map[i + 1] == '-' && map[i + 2] > 48))
		{
			if (!dot)
				dot = ft_new_dot();
			dot->x = (y > p) ? (i - (y * p)) : i;
			ft_width(map, &i, y, dot);
			dot = dot->next;
		}
		i++;
	}
}
