/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 12:49:56 by rowong            #+#    #+#             */
/*   Updated: 2018/01/20 13:37:45 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		match(char *s1, char *s2)
{
	if ((!*s1 && !*s2))
		return (1);
	if (*s2 == '*' && *(s2 + 1) != '\0' && !*s1)
		return (0);
	if (*s2 == *s1)
		return (match(s1 + 1, s2 + 1));
	if (*s2 == '*')
		return (match(s1, s2 + 1) || match(s1 + 1, s2));
	return (0);
}

// #include <stdio.h>

// int main(int argc, char const *argv[])
// {
// 	char *f = "Hello World.\\ no-today";

// 	char *m1 = "*oday";
// 	char *m2 = "*no";
// 	char *m3 = "o*.";
// 	char *m4 = "*o***-tod*";
// 	char *m5 = "o*na";

// 	m5++;
// 	m5++;
// 	m5++;
// 	// --m5;
// 	printf("%d\n", match(f, m1) );
// 	printf("%d\n\n", match(f, m2) );
// 	printf("%d\n\n", match(f, m3) );
// 	printf("%d\n", match(f, m4) );	
// 	printf("%d\n", match(f, m5) );

// 	return 0;
// }