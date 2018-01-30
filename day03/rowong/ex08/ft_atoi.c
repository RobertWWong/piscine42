/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:54:46 by rowong            #+#    #+#             */
/*   Updated: 2018/01/12 15:00:24 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		idx++;
	}
	return (idx);
}

int		ft_pow(int exponent)
{
	int base;

	base = 1;
	if (exponent == 0)
		return (base);
	while (exponent > 0)
	{
		base *= 10;
		exponent--;
	}
	return (base);
}

int		ft_atoi(char *str)
{
	int len;
	int count;
	int asciival;
	int digits[12];
	int retval;

	len = ft_strlen(str);
	asciival = 0;
	retval = 0;
	count = 0;
	while (count < len)
	{
		asciival = str[count] - 48;
		if (asciival < 0 || asciival > 9)
			break ;
		digits[count++] = asciival;
	}
	len = 0;
	while (len < count)
	{
		retval += digits[len] * ft_pow(count - len - 1);
		len++;
	}
	return (retval);
}
