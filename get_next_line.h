#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlin.h>
# include <limits.h>
# include <string.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*readbuff(int fd, char *depot);
char	*new_line(char *depot);
char	*ft_strchar(char *depot, int c);
char	*ft_free(char **str);
char	*ft_strjoin(char *depot, char *buf);
char	*ft_substr(char *depot, unsigned int start, size_t len);
size_t	ft_strlen(char *str);
char	*clean_depot(char *depot);

#endif
