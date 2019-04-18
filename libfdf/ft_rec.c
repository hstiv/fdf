/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:54:09 by hstiv             #+#    #+#             */
/*   Updated: 2019/04/13 19:36:34 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static void		ft_width(t_mlx *dot, char *s)
{
	char		*str;
	int			i;
	int			l;

	i = 0;
	l = 0;
	str = ft_strnew(11);
	while (s[i] != ',' && s[i] != '\0')
	{
		str[l] = s[i];
		l++;
		i++;
	}
	dot->z += ft_atoi(str);
	dot->y -= (dot->z * 2);
	if (s[i] == ',')
	{
		i += 3;
		l = 0;
		while (s[i] <= 70 && s[i] != '\0')
		{
			str[l] = s[i];
			l++;
			i++;
		}
		s[l] = '\0';
		dot->color = ft_atoi_base(str, 16);
	}
	else
		dot->color = COLOR;
	free(str);
	
}

static void		ft_recorder(char **s, t_mlx **dot, int y)
{
	int			x;

	x = 0;
	while (s[x] != NULL)
	{
		dot[x] = ft_new_dot();
		dot[x]->x += (x > 0 || x < 0) ? (x * LINE + BEG) : (BEG);
		dot[x]->y += (y > 0 || y < 0) ? (y * LINE + BEG) : (BEG);
		ft_width(dot[x], s[x]);
		x++;
	}
	ft_arraydel((void **)s);
}

void			ft_rec(t_fdf *mlx_data, char **map)
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
		(!dot[y]) ? (dot[y] = (t_mlx **)ft_memalloc(sizeof(t_mlx *) * (p + 1))) : 0;
		ft_recorder(ft_strsplit(map[y], 32), dot[y], y);
		y++;
	}
	ft_arraydel((void **)map);
}
