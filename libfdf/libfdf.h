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
# define COLOR 50
# define CON 5
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
	int				col_bool;
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
	int				right_mouse;
	int				left_mouse;
	int				tall;
	int				l;
	int				err;
	int				derr;
	int				col_ch;
	char			*move;
	char			*scale;
	char			*height;
	char			*isometric;
	char			*parallel;
	int				green;
	int				red;
	int				sl;
	int				mv;
	int				hi;
	int				rot;
	int				c;
	int				v;
	int				x;
	int				y;
	int				z;
	int				space;
}					t_fdf;

void				rotate(t_mlx *dot, t_fdf *f, int x, int y);
void				z_rotate(t_mlx *dot, t_fdf *f);
void				x_rotate(t_mlx *dot, t_fdf *f);
void				y_rotate(t_mlx *dot, t_fdf *f);
void				put_man(t_fdf *fdf);
int					mouse_move(int x, int y, t_fdf *param);
int					key_release(int keycode, t_fdf *fdf);
int					mouse_release(int button, int x, int y, t_fdf *fdf);
int					mouse_press(int button, int x, int y, t_fdf *param);
int					ft_close(void *param);
int					key_press(int keycode, t_fdf *param);
void				ft_free(void ***array);
void				ft_mappaint(t_fdf *mlx_data);
void				ft_bresenham(t_mlx *d0, t_mlx *d1, t_fdf *mlx);
char				**ft_valid_map(const int fd);
void				ft_rec(t_fdf *mlx_data, char **map);
void				ft_run_window(t_fdf *mlx_data);
t_mlx				*ft_new_dot();
t_fdf				*ft_new_fdf();

#endif
