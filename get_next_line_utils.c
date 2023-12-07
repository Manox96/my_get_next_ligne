/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:09:53 by aennaqad          #+#    #+#             */
/*   Updated: 2023/12/06 11:11:42 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>


char *my_strchr(const char *s, int c)
{
	int i;
	char *tab;
	i = 0;

	while (s[i])
	{
		if (s[i] == c)
			return (char *)(s + i);
		else
			i++;
	}
	return (NULL);
}

size_t my_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *my_strdup(const char *s1)
{
	int i;
	size_t lenght;
	char *tab;

	i = 0;
	lenght = my_strlen(s1);
	tab = malloc(sizeof(char) * lenght);
	while (s1[i])
		*tab++ = s1[i++];
	return (tab);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mystr;
	size_t	i;
	size_t	newlen;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= my_strlen(s))
		return (my_strdup(""));
	newlen = my_strlen(s + start);
	if (len > newlen)
		len = newlen;
	mystr = malloc((len + 1) * sizeof(char));
	if (!mystr)
		return (NULL);
	while (i < len)
	{
		mystr[i] = s[start + i];
		i++;
	}
	mystr[i] = '\0';
	return (mystr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*joined;

	i = -1;
	j = -1;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (my_strdup(s2));
	if (!s2)
		return (my_strdup(s1));
	joined = malloc(((my_strlen(s1) + my_strlen(s2)) + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	while (s1[++i])
		joined[i] = s1[i];
	while (s2[++j])
		joined[i + j] = s2[j];
	joined[i + j] = '\0';
	return (joined);
}

