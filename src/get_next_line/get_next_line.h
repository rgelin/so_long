/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:54:44 by rgelin            #+#    #+#             */
/*   Updated: 2021/10/01 14:21:57 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
void	ft_free(char **str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);

# define BUFFER_SIZE 1
#endif