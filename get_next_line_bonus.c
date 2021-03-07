/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:48:29 by bboriko-          #+#    #+#             */
/*   Updated: 2021/03/07 16:50:58 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*static int	there_is_line(char *r_text)
{
	int cont;

	cont = 0;
	if (r_text == NULL)
		return (-29);
	while (r_text[cont] != '\0')
	{
		if (r_text[cont] == '\n')
			return (-1);
		cont++;
	}
	return (cont);
}*/

static int		length_jump_of_line(char *r_text, int q_v_devolver)
{
	int len;

	len = 0;
	while (r_text[len])
	{
		if (r_text[len] == '\n')
		{
			while (r_text[len] == '\n')
			{
				len++;
			}
			if(q_v_devolver == 1)
				return (-1);
			else
				return (len);
		}
		len++;
	}
	return (len);
}

static	char	*save_line(char *r_text)
{
	char *str;

	str = ft_substr(r_text, length_jump_of_line(r_text, 2) + 1,
		ft_strlen(r_text) - 1);
	free(r_text);
	r_text = NULL;
	return (str);
}

static char	*save_buffer(char *buffer, char *r_text, int r_len)
{
	char	*temp;
	buffer[r_len] = '\0';
	printf("buffer > %s\n", buffer);
	temp = ft_strjoin(r_text, buffer);
	free(r_text);
	r_text = NULL;
	return (temp);
}

int	get_next_line(int fd, char **line)
{
	char		*buffer;
	int			r_len;
	static char	*r_text[FD_SIZE];

	if (fd < 0 || line == NULL)
		return (-1);
	if (!r_text[fd])
		r_text[fd] = ft_strdup("");
	if (!(buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	while ((r_len = read(fd, buffer, BUFFER_SIZE)) == BUFFER_SIZE)
		r_text[fd] = save_buffer(buffer, r_text[fd], r_len);
	if (r_len <= 0)
	{
		free(r_text[fd]);
		free(buffer);
		return ( r_len == 0? 0: -1);
	}
	if (r_len != BUFFER_SIZE && r_len > 0)
		r_text[fd] = save_buffer(buffer, r_text[fd], r_len);
	free(buffer);
	*line = ft_substr(r_text[fd], 0, length_jump_of_line(r_text[fd], 2));
	r_text[fd] = save_line(r_text[fd]);
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
