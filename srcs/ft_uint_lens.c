/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_lens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 13:33:39 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/03 13:33:45 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned int				ft_int_len_ui(unsigned int nb)
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

unsigned int				ft_int_len_uli(unsigned long int nb)
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

unsigned int				ft_int_len_ulli(unsigned long long int nb)
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
