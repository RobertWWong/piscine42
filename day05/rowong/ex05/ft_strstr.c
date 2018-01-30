/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:36:27 by rowong            #+#    #+#             */
/*   Updated: 2018/01/15 14:37:03 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*substr;
	char	*origin;
	int		idx;

	idx = 0;
	while (*str != '\0')
	{
		origin = str;
		substr = to_find;
		while (*str && *substr && *str == *substr)
		{
			str++;
			substr++;
		}
		if (!*substr)
			return (origin);
		str = origin + 1;
	}
	return (0);
}
