/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:54:09 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/31 14:18:31 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static int		if_color(int *i, int *l, t_mlx *dot, char *s)
{
	char		*str;

	if (!(str = ft_strnew(11)))
		return (0);
	if (s[*i] == ',')
	{
		(*i) += 3;
		*l = 0;
		while (s[*i] <= 70 && s[*i] != '\0')
		{
			str[*l] = s[*i];
			(*l)++;
			(*i)++;
		}
		s[*l] = '\0';
		dot->color = ft_atoi_base(str, 16);
		dot->col_bool = 1;
	}
	else
		dot->color = COLOR;
	free(str);
	return (1);
}

static int		ft_width(t_mlx *dot, char *s)
{
	char		*str;
	int			i;
	int			l;

	i = 0;
	l = 0;
	if (!(str = ft_strnew(11)))
		return (0);
	while (s[i] != ',' && s[i] != '\0')
	{
		str[l] = s[i];
		l++;
		i++;
	}
	dot->z = ft_atoi(str);
	if (!if_color(&i, &l, dot, s))
		return (0);
	free(str);
	return (1);
}

static int		ft_recorder(char **s, t_mlx **dot, int y)
{
	int			x;

	x = 0;
	y = 0;
	while (s[x] != NULL)
	{
		if (!(dot[x] = ft_new_dot()))
			return (0);
		if (!ft_width(dot[x], s[x]))
			return (0);
		x++;
	}
	ft_arraydel((void **)s);
	return (1);
}

int				ft_rec(t_fdf *mlx_data, char **map)
{
	int			y;
	int			p;
	t_mlx		***dot;

	y = 0;
	p = 0;
	while (map[y][p])
		p++;
	while (map[y])
		y++;
	dot = (t_mlx ***)ft_memalloc(sizeof(t_mlx**) * (y + 1));
	mlx_data->dot = dot;
	y = 0;
	while (map[y] != NULL)
	{
		if (!dot || !dot[y])
			if (!dot || !(dot[y] = (t_mlx **)ft_memalloc(sizeof(t_mlx *) * (p + 1))))
				return (0);
		if (!(ft_recorder(ft_strsplit(map[y], 32), dot[y], y)))
			return (0);
		y++;
	}
	ft_arraydel((void **)map);
	return (1);
}
