/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_li.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 13:26:20 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/03 13:26:33 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int				ft_int_len_li(long int nb)
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

char					*ft_itoa_li(long int nb)
{
	char			*str;
	long int		n;
	int				s;
	int				i;
	long int		neg;

	i = 0;
	n = nb > 0 ? nb : nb * -1;
	neg = nb < 0 ? 1 : 0;
	if (neg == 1 && (unsigned long)n == 9223372036854775808U)
		return (ft_strdup("-9223372036854775808"));
	s = ((unsigned int)ft_int_len_li(n) + 1 + neg);
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
