/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:19:25 by mwuckert          #+#    #+#             */
/*   Updated: 2019/04/12 19:10:26 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int			fdf(const int fd)
{
	char	**map;
	t_fdf	*mlx_data;

	if (!(map = ft_valid_map(fd)))
		return (0);
	if (!(mlx_data = ft_new_fdf()) || !ft_rec(mlx_data, map))
		return (0);
	ft_run_window(mlx_data);
	if (mlx_data->dot)
		ft_free((void ***)mlx_data->dot);
	if (mlx_data)
		free(mlx_data);
	return (1);
}
