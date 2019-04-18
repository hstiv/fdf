/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:19:02 by mwuckert          #+#    #+#             */
/*   Updated: 2019/04/12 19:18:26 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFDF_H
# define LIBFDF_H

# define BUFF_SIZE 100000
# define HEIGHT 1395
# define WIDTH 2560
# define LINE 20
# define BEG 70
# define COLOR 167772
# define CON 10
# define FDF "fdf"

# include <math.h>
# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_mlx
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_mlx;

typedef struct		s_fdf
{
	t_mlx			***dot;
	void			*mlx_wind;
	void			*mlx_ptr;
	void			*mlx_img;
	int				x_add;
	int				y_add;
	int				iso;
	int				par;
}					t_fdf;

void			ft_free(void ***array);
void			ft_mappaint(t_fdf *mlx_data);
void			ft_drawxstr(t_mlx *d0, t_mlx *d1, t_fdf *mlx);
char			**ft_valid_map(const int fd);
void			ft_rec(t_fdf *mlx_data, char **map);
void			ft_run_window(t_fdf* mlx_data);
t_mlx			*ft_new_dot();
t_fdf			*ft_new_fdf();

#endif
