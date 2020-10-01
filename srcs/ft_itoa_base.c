/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <blakeish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 12:50:44 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/03 20:04:29 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		ft_choose_letter(int n, int flag)
{
	char	x;

	x = n + flag - 33;
	return (x);
}

void		base_8(unsigned int n, t_ibb *b)
{
	while (n >= 0 && b->size > -1)
	{
		b->c = ft_itoa(n % 8);
		b->str[b->size] = *b->c;
		ft_strdel(&b->c);
		n /= 8;
		b->size--;
	}
	b->str[b->i] = '\0';
}

void		base_16(unsigned int n, t_ibb *b, int flag)
{
	while (n >= 0 && b->size > -1)
	{
		if (n % 16 > 9)
		{
			b->x = ft_choose_letter(n % 16, flag);
			b->str[b->size] = b->x;
		}
		else
		{
			b->c = ft_itoa(n % 16);
			b->str[b->size] = *b->c;
			ft_strdel(&b->c);
		}
		b->size--;
		n /= 16;
	}
	b->str[b->i] = '\0';
}

char		*ft_itoa_base(unsigned int n, int base, int flag)
{
	t_ibb	b;

	b.tmp = n;
	b.size = 0;
	while (b.tmp /= base)
		b.size++;
	b.i = b.size + 1;
	b.str = ft_strnew(b.size + 1);
	if (base == 8)
		base_8(n, &b);
	else if (base == 16)
		base_16(n, &b, flag);
	return (b.str);
}
