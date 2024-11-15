/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:15:13 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/11 12:57:16 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*to_read_file(int fd, char *buffer);
char	*to_join(char *tmp, char *buffer);
char	*to_substract_line(char *buffer);
void	to_upd_buffer(char *buffer);
char	*ft_strjoin(char const *buffer, char const *tmp);
char	*ft_strchrr(const char *buffer, int a);
int		f_strlen(const char *str);
char	*ft_strdupp(const char *str);

#endif
