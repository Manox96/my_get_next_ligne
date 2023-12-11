/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:24:31 by aennaqad          #+#    #+#             */
/*   Updated: 2023/12/11 17:12:35 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*append_char(char *str1, char*str2)
{
	char	*temp;

	temp = my_strjoin(str1, str2);
	free(str1);
	return (temp);
}

char	*nex_line(char *str)
{
	size_t		i;
	size_t		j;
	char		*nexto;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i])
		i++;
	nexto = malloc(((my_strlen(str) - i) + 1) * sizeof(char));
	if (!nexto)
		return (free(str), NULL);
	while (str[i])
	{
		nexto[j] = str[i];
		i++;
		j++;
	}
	nexto[j] = '\0';
	free(str);
	return (nexto);
}

char	*one_line(char *str)
{
	ssize_t		i;
	char		*myline;

	myline = NULL;
	i = 0;
	if (!str[0])
		return (free(str), NULL);
	while (str[i] && str[i] != '\n')
		i++;
	myline = ft_calloc((i + 2), sizeof(char));
	if (!myline)
		return (free(str), NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		myline[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		myline[i++] = '\n';
	myline[i] = '\0';
	return (myline);
}

char	*read_from_file(char *all, int fd)
{
	char		*buffer;
	ssize_t		byteread;

	if (!all)
		all = ft_calloc(1, sizeof(char));
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	byteread = 1;
	while (byteread > 0 && !(my_strchr(all, '\n')))
	{
		byteread = read(fd, buffer, BUFFER_SIZE);
		if (byteread == -1)
			return (free(buffer), NULL);
		buffer[byteread] = '\0';
		all = append_char(all, buffer);
		if (!all)
			return (NULL);
	}
	free(buffer);
	return (all);
}

char	*get_next_line(int fd)
{
	static char	*all[OPEN_MAX];
	char		*line;

	if (fd < 0 || read(fd, "", 0) < 0 || fd > OPEN_MAX
		|| BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
	{
		if (fd < 0 || fd > OPEN_MAX)
			return (NULL);
		else
			return (free(all[fd]), all[fd] = NULL, NULL);
	}
	all[fd] = read_from_file(all[fd], fd);
	line = one_line(all[fd]);
	if (!line)
		return (all[fd] = NULL, NULL);
	if (my_strlen(all[fd]) == 0)
		return (all[fd] = NULL, NULL);
	all[fd] = nex_line(all[fd]);
	return (line);
}
