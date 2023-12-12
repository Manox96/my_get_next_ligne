/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:09:53 by aennaqad          #+#    #+#             */
/*   Updated: 2023/12/12 11:23:35 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*my_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		else
			i++;
	}
	return (NULL);
}

size_t	my_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*mystrdup(const char *s1)
{
	char		*tab;
	int			i;
	size_t		lenght;

	i = 0;
	lenght = my_strlen(s1);
	tab = malloc(sizeof(char) * lenght);
	while (s1[i])
		*tab++ = s1[i++];
	return (tab);
}

char	*my_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*joined;

	i = -1;
	j = -1;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (mystrdup(s2));
	if (!s2)
		return (mystrdup(s1));
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

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tab;
	size_t			i;

	tab = (void *)malloc(((count * size) * sizeof(char)));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < (size * count))
	{
		*(tab + i) = 0;
		i++;
	}
	return (tab);
}
