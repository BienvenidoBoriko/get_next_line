/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:48:29 by bboriko-          #+#    #+#             */
/*   Updated: 2021/02/28 21:19:13 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	there_is_line(char *r_text)
{
	int len;
	int cont;

	len = 0;
	cont = 0;
	if (r_text == NULL)
		return (-29);
	while (r_text[cont] != '\0')
	{
		if (r_text[cont] == '\n')
			return (-1);
		len++;
		cont++;
	}
	return (len);
}

int		long_hasta_salto(char *r_text)
{
	int len;

	len = 0;
	while (*r_text)
	{
		if (*r_text == '\n')
			return (len);
		len++;
		r_text++;
	}
	return (len);
}

static	char	*save_line(char *r_text)
{
	char *str;

	str = ft_strdup(ft_substr(r_text, long_hasta_salto(r_text) - 1,
		ft_strlen(r_text) - 1));
	free(r_text);
	return (str);
}

static char	*save_buffer(char *buffer, char *r_text)
{
	char	*temp;

	temp = ft_strjoin(r_text, buffer);
	free(r_text);
	return (temp);
}

int	get_next_line(int fd, char **line)
{
	char		*buffer;
	int			r_len;
	static char	*r_text;

	if (!r_text)
		r_text = ft_strdup("");
	if (!(buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	while (((r_len = read(fd, buffer, BUFFER_SIZE)) == BUFFER_SIZE)
		&& (there_is_line(r_text) != -1))
	{
		buffer[r_len] = '\0';
		r_text = save_buffer(buffer, r_text);
	}
	if (r_len < BUFFER_SIZE)
		r_text = save_buffer(buffer, r_text);
	free(buffer);
	*line = ft_substr(r_text, 0, long_hasta_salto(r_text));
	r_text = save_line(r_text);
	if (r_len < 0)
	{
		free(r_text);
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		free(line);
	}
	if (argc == 2)
		close(fd);
}
