/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:19:02 by mwuckert          #+#    #+#             */
/*   Updated: 2019/04/11 18:19:07 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFDF_H
# define LIBFDF_H

# define BUFF_SIZE 100000

# include "libft.h"
# include "unistd.h"

typedef struct		s_cor
{
	int				x;
	int				y;
	int				z;
}					t_cor;

typedef struct		s_mlx;
{
	void			*mlx_color;
	t_cor			*mlx_cor;
	struct s_mlx	*next;
}					t_mlx;

typedef struct		s_fdf;
{
	t_mlx			*dot;
	void			*mlx_wind;
	void			*mlx_ptr;
}					t_fdf;

char				*ft_valid_map(const int fd);

#endif
