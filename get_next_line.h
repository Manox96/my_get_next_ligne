/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:48:23 by aennaqad          #+#    #+#             */
/*   Updated: 2023/12/06 16:38:27 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LIGNE
#define  GET_NEXT_LIGNE
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char *get_next_line(int fd);
char *my_strchr(const char *s, int c);
size_t my_strlen(const char *s);
char *my_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);



#endif
