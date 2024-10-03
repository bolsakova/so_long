/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:15:04 by tbolsako          #+#    #+#             */
/*   Updated: 2024/06/19 14:19:06 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	to_upd_buffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i])
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
	return ;
}

char	*to_substract_line(char *buffer)
{
	char	*line_res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line_res = (char *)malloc((i + 2) * sizeof(char));
	if (!line_res)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		line_res[j++] = buffer[i++];
	if (buffer[i] && buffer[i] == '\n')
		line_res[j++] = buffer[i];
	line_res[j] = 0;
	return (line_res);
}

char	*to_join(char *tmp, char *buffer)
{
	char	*tmp_2;

	tmp_2 = ft_strjoin(tmp, buffer);
	free(tmp);
	if (!tmp_2)
		return (NULL);
	return (tmp_2);
}

char	*to_read_file(int fd, char *buffer)
{
	ssize_t	reading_bytes;
	char	*tmp;

	tmp = ft_strdup(buffer);
	if (!tmp)
		return (NULL);
	reading_bytes = 1;
	while (reading_bytes > 0 && !ft_strchr(tmp, '\n'))
	{
		reading_bytes = read(fd, buffer, BUFFER_SIZE);
		if (reading_bytes == -1)
		{
			buffer[0] = 0;
			free(tmp);
			return (NULL);
		}
		buffer[reading_bytes] = '\0';
		if (reading_bytes == 0)
			return (tmp);
		tmp = to_join(tmp, buffer);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line_res;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
	{
		buffer[0] = 0;
		return (NULL);
	}
	line = to_read_file(fd, buffer);
	if (!line)
		return (NULL);
	line_res = to_substract_line(line);
	free(line);
	if (!line_res)
		return (NULL);
	if (buffer[0])
		to_upd_buffer(buffer);
	return (line_res);
}

// int	main(void)
// {
// 	int	fd;

// 	// char	*line;
// 	fd = open("abaaxdsrs12", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	// while ((line = get_next_line(fd)) != NULL)
// 	// {
// 	// 	printf("%s", line);
// 	// 	free(line);
// 	// }
// 	close(fd);
// }
