/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:08:50 by blakeish          #+#    #+#             */
/*   Updated: 2020/08/03 18:35:43 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*ft_itoa_long(long nb)
{
	char	*str;
	long	n;
	int		s;
	int		i;
	int		neg;

	i = 0;
	n = ft_negative(nb);
	neg = ft_sign(nb);
	s = (ft_int_len(n) + 1 + neg);
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

char			*ft_itoa_ulonglong(unsigned long long nb)
{
	char		*str;
	long double	n;
	int			s;
	int			i;

	n = nb;
	i = 0;
	s = (ft_int_len_ull(n) + 1);
	if (!(str = (char*)malloc(sizeof(char) * (s))))
		return (0);
	i--;
	str[--s] = '\0';
	while (--s != i)
	{
		str[s] = (char)('0' + (unsigned long long)n % 10);
		n = n / 10.0;
	}
	return (str);
}

char			*ft_itoa_double(double nb)
{
	char	*str;
	double	n;
	int		s;
	int		i;

	n = nb;
	i = 0;
	s = (ft_int_len_d(n) + 1);
	if (!(str = (char*)malloc(sizeof(char) * (s))))
		return (0);
	i--;
	str[--s] = '\0';
	while (--s != i)
	{
		str[s] = (char)('0' + (unsigned long long)n % 10);
		n = n / 10.0;
	}
	return (str);
}

char			*ft_itoa_long_double(long double nb)
{
	char		*str;
	long double	n;
	int			s;
	int			i;

	n = nb;
	i = 0;
	s = (ft_int_len_ld(n) + 1);
	if (!(str = (char*)malloc(sizeof(char) * (s))))
		return (0);
	i--;
	str[--s] = '\0';
	while (--s != i)
	{
		str[s] = (char)('0' + (unsigned long long)n % 10);
		n = n / 10.0;
	}
	return (str);
}
