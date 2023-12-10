/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:09:53 by aennaqad          #+#    #+#             */
/*   Updated: 2023/12/09 17:32:32 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

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

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*my_strdup(const char *s1)
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

/*-----------------Calloc-----------------------*/

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tab;
	size_t			i;

	if (count * size > SIZE_MAX)
		return (NULL);
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

/*-----------------End Calloc Functions-----------------------*/
