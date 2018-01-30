/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:14:19 by rowong            #+#    #+#             */
/*   Updated: 2018/01/12 13:17:19 by rowong           ###   ########.fr       */
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

char	*ft_strrev(char *str)
{
	int		front;
	int		back;
	char	bubble;

	front = 0;
	back = ft_strlen(str);
	bubble = ' ';
	while (front < back)
	{
		bubble = str[front];
		str[front++] = str[back - 1];
		str[back - 1] = bubble;
		back--;
	}
	return (str);
}
