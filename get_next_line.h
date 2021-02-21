/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:48:19 by bboriko-          #+#    #+#             */
/*   Updated: 2021/02/21 17:23:36 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>

char		*ft_strdup(const char *str1);
char	*ft_strcpy(char *dest, const char *src);
int	ft_strlen(const char *str);
int get_next_line(int fd, char **line);
char			*ft_strjoin(const char *s1, const char *s2);
char	*ft_strcat(char *dest, const char *src);
char		**ft_split(char const *s, char c);
static void	aux_ft_split(char **str, char c, const char *s);
static void	aux_ft_split(char **str, char c, const char *s);
int			num_c(char *s, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
