/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:22:44 by blakeish          #+#    #+#             */
/*   Updated: 2019/09/12 23:40:29 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char*)s;
	while (*tmp)
		tmp++;
	if (c == '\0')
		return ((char*)tmp);
	while (--tmp >= s)
		if (c == *tmp)
			return ((char*)tmp);
	return (NULL);
}
