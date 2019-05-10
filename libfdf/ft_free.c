/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:16:36 by mwuckert          #+#    #+#             */
/*   Updated: 2019/01/14 08:27:54 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void		ft_free(void ***array)
{
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	while (array[i + 1] != NULL)
		i++;
	while (array[i][j + 1] != NULL)
		j++;
	while (array[i])
	{
		l = j;
		while (array[i][l])
		{
			free(array[i][l]);
			l--;
		}
		free(array[i]);
		i--;
	}
	free(array);
}