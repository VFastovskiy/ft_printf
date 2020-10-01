/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:16:14 by blakeish          #+#    #+#             */
/*   Updated: 2019/09/23 18:13:26 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*s;
	char	*d;
	size_t	i;

	i = 0;
	s = (char *)src;
	d = (char *)dst;
	if (n == 0 || (char*)dst == (char*)src)
		return (dst);
	if (s <= d)
		while (n--)
			d[n] = s[n];
	else
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	return (dst);
}
