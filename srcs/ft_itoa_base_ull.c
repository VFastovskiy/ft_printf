/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ull.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <blakeish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 18:29:00 by blakeish          #+#    #+#             */
/*   Updated: 2020/08/03 20:13:38 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_itoa_base_ull_16(unsigned long long int n, t_ib *ib, int flag)
{
	while (n >= 0 && ib->size > -1)
	{
		if (n % 16 > 9)
		{
			ib->x = ft_choose_letter(n % 16, flag);
			ib->str[ib->size] = ib->x;
		}
		else
		{
			ib->c = ft_itoa(n % 16);
			ib->str[ib->size] = *ib->c;
			ft_strdel(&ib->c);
		}
		ib->size--;
		n /= 16;
	}
	ib->str[ib->i] = '\0';
}

void	ft_itoa_base_ull_8(unsigned long long int n, t_ib *ib)
{
	while (n >= 0 && ib->size > -1)
	{
		ib->c = ft_itoa(n % 8);
		ib->str[ib->size] = *ib->c;
		ft_strdel(&ib->c);
		n /= 8;
		ib->size--;
	}
	ib->str[ib->i] = '\0';
}

char	*ft_itoa_base_ull(unsigned long long int n, int base, int flag)
{
	t_ib						ib;
	unsigned long long int		tmp;

	tmp = n;
	ib.size = 0;
	while (tmp /= base)
		ib.size++;
	ib.i = ib.size + 1;
	ib.str = ft_strnew(ib.size + 1);
	if (base == 8)
		ft_itoa_base_ull_8(n, &ib);
	else if (base == 16)
		ft_itoa_base_ull_16(n, &ib, flag);
	return (ib.str);
}
