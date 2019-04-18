/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:12:15 by mwuckert          #+#    #+#             */
/*   Updated: 2018/12/30 18:10:22 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *dup;
	char *addr;

	if (!(dup = (char*)(malloc(sizeof(*s1) * ft_strlen(s1) + 1))))
		return (0);
	addr = dup;
	while (*s1)
		*dup++ = *s1++;
	*dup = '\0';
	return (addr);
}
