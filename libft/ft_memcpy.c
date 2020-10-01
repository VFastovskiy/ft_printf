/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:28:44 by blakeish          #+#    #+#             */
/*   Updated: 2019/09/23 18:10:42 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*s;

	s = (char*)src;
	i = 0;
	if (n == 0 || (char*)dst == (char*)src)
		return (dst);
	while (i < n)
	{
		((char*)dst)[i] = s[i];
		i++;
	}
	return (dst);
}
