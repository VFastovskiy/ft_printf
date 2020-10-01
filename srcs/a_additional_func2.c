/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_additional_func2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <blakeish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 18:33:38 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/03 18:49:29 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_int_len_d(double nb)
{
	int	sz;

	sz = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		sz++;
	}
	return (sz + 1);
}

int				ft_int_len(long long nb)
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

int				ft_int_len_ld(long double nb)
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

int				ft_int_len_ull(unsigned long long int nb)
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
