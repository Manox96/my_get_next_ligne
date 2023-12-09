/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:36:48 by aennaqad          #+#    #+#             */
/*   Updated: 2023/12/09 18:25:16 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*append_char(char *str1 ,char*str2)
{
	char	*temp;

	temp = my_strjoin(str1, str2);
	free(str1);
	return temp;
}

char	*nex_line(char *str)
{
	size_t	i = 0;
	size_t	j = 0;
	char		*nexto;

	while (str[i] && str[i] != '\n')
		i++;
	i++;
	nexto = ft_calloc(my_strlen(str) - i, sizeof(char));
	if(!nexto)
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
/*--------------------------this for get one line from buffer -------------------------------*/
static char	*one_line(char *str)
{
	ssize_t	i;
	char		*myline;

	i = 0;
	if (!str[0])
		return (free(str), NULL);
	while (str[i] && str[i] != '\n')
		i++;
	myline = ft_calloc(i + 2, sizeof(char));
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
/*--------------------------this for get all line and make it into buffer-------------------------------*/
static char	*read_from_file(char *buffer ,int fd)
{
	char		*tab;
	ssize_t	byteread;

	if (!buffer)
		buffer = ft_calloc(1,1);
	tab = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!tab)
		return (NULL);
	byteread = 1;
	while (byteread > 0 && !(my_strchr(buffer, '\n')))
	{
		byteread = read(fd, tab, BUFFER_SIZE);
		if (byteread == -1)
			return (free(tab), NULL);
		tab[byteread] = '\0';
		buffer = append_char(buffer, tab);
	}
	free(tab);
	return (buffer);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char			*line;
	if (fd < 0 || read(fd, "", 0) < 0 ||BUFFER_SIZE < 0)
		return (NULL);
	buffer = read_from_file(buffer,fd);
	line = one_line(buffer);
	if (my_strlen(buffer) == 0)
		return (NULL);
	buffer = nex_line(buffer);
	return (line);
}
// int main()
// {
// 	int fd = open("fileee.txt",O_RDONLY);
// 	char *lineonet;
// 	char *lineone;
// 	char *lineone1;
// 	char *lineone2;


// 	lineone = get_next_line(fd);
// 	printf("line one : %s",lineone);
// 	free(lineone);
// 	printf("*-----*\n");
// 	lineonet = get_next_line(fd);
// 	printf("line two : %s",lineonet);
// 	free(lineonet);
// 	printf("*-----*\n");
// 	lineone1 = get_next_line(fd);
// 	printf("line three : %s",lineone1);
// 	free(lineone1);
// 	printf("*-----*\n");

// 	lineone2 = get_next_line(fd);
// 	printf("line four : %s",lineone2);
// 	free(lineone2);
// 	return 0;
// }


