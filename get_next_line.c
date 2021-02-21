/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:48:29 by bboriko-          #+#    #+#             */
/*   Updated: 2021/02/21 18:17:04 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

static there_is_line(char *r_text)
{
	int len;

	len = 0;
	while (*r_text != '\0')
	{
		if(*r_text = '\n')
			return (++len);
		len++;
		r_text++;
	}
	return (len);
}

static int save(char *r_text, char **line)
{
	*line = ft_substr(r_text, 0, there_is_line(r_text));
}

static int	save_buffer(char *r_text, char *line)
{
	char *str;
}

int	get_next_line(int fd, char **line)
{
	char		*buffer;
	char		*r_line;
	int			r_len;
	static char	*r_text;

	if (!(buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	while (((r_len = read(fd, buffer, BUFFER_SIZE)) > 0) && 
	(!there_is_line(r_text)))
	{
		if (r_len < 0)
		{
			free(buffer);
			return (-1);
		}
		buffer[r_len] = '\0';
		r_text = ft_strjoin(r_text, buffer);
	}
	*line = ft_substr(r_text, 0, there_is_line(r_text));
	save_line(r_text);
	return (1);
}

int	main(void)
{
	printf("buffer = %d", BUFFER_SIZE);
}
