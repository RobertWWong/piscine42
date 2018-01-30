/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:43:13 by rowong            #+#    #+#             */
/*   Updated: 2018/01/13 17:23:43 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int count;

	count = 5;
	if (nb <= 1)
		return (0);
	if (nb <= 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	while (count * count <= nb)
	{
		if (nb % count == 0 || nb % (count + 2) == 0)
			return (0);
		count += 6;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	int next_equal;
	int found;

	next_equal = nb;
	found = 0;
	while (!found)
	{
		if (ft_is_prime(next_equal))
			return (next_equal);
		next_equal++;
	}
	return (next_equal);
}
