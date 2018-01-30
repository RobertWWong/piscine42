/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:57:21 by rowong            #+#    #+#             */
/*   Updated: 2018/01/15 21:17:36 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_need_to_change(char var)
{
	if (((var < '0') || (var > '9' && var < 'A')) ||
		(var > 'Z' && var < 'a') || var > 'z')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		cap_flag;
	int		i;
	int		var;

	i = 0;
	cap_flag = 1;
	while (str[i] != 0)
	{
		var = str[i];
		if (ft_need_to_change(var))
			cap_flag = 1;
		else if (cap_flag)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
			cap_flag = 0;
		}
		else if (!cap_flag)
			if (var >= 'A' && var <= 'Z')
				str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
