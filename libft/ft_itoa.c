/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <blakeish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:08:50 by blakeish          #+#    #+#             */
/*   Updated: 2020/08/03 18:51:14 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				ft_int_len(unsigned int nb)
{
	unsigned int	sz;

	sz = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		sz++;
	}
	return (sz + 1);
}

int						ft_negative(int nb)
{
	if (nb < 0)
		return (nb * -1);
	else
		return (nb);
}

int						ft_sign(int nb)
{
	if (nb < 0)
		return (1);
	else
		return (0);
}

char					*ft_itoa(int nb)
{
	char	*str;
	int		n;
	int		s;
	int		i;
	int		neg;

	i = 0;
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	n = ft_negative(nb);
	neg = ft_sign(nb);
	s = ((unsigned int)ft_int_len(n) + 1 + neg);
	if (!(str = (char*)malloc(sizeof(char) * (s))))
		return (0);
	if (neg == 1)
		str[i] = '-';
	else
		i--;
	str[--s] = '\0';
	while (--s != i)
	{
		str[s] = (char)('0' + n % 10);
		n = n / 10;
	}
	return (str);
}
