/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:48:19 by bboriko-          #+#    #+#             */
/*   Updated: 2021/03/07 17:43:04 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9999
# endif // BUFFER_SIZE
# ifndef FD_SIZE
#  define FD_SIZE 9999
# endif // !FD_SIZE
char	*ft_strdup(const char *str1);
char	*ft_strcpy(char *dest, const char *src);
int	ft_strlen(const char *str);
int get_next_line(int fd, char **line);
char	*ft_strjoin(const char *s1, const char *s2);
int			num_c(char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void				ft_putendl_fd(char *s, int fd);
char	*ft_strcat(char *dest, const char *src);
#endif //GET_NEXT_LINE_H
