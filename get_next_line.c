#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*depot;

	depot = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((depot && !ft_strchar(depot, '\n')) || !depot)
		depot = readbuff(fd, depot);
	if (!depot)
		return (NULL);
	line = new_line(depot);
	if (!line)
		return (ft_free(&depot));
	depot = clean_depot(depot);
	return (line);
}

char	*new_line(char *depot)
{
	char	*line;
	char	*p;
	int	len;

	p = ft_strchar(depot, '\n');
	len = p - depot + 1;
	line = ft_substr(depot, 0, len);
	if (!line)
		return (NULL);
	return (line);
}


char	*clean_depot(char *depot)
{
	char	*new_depot;
	char	*p;
	int	len;

	p = ft_strchar(depot, '\n');
	if (!p)
	{
		new_depot = NULL;
		return (ft_free(&depot));
	}
	else
		len = (p - depot) + 1;
	if (!depot[len])
		return (ft_free(&depot));
	new_depot = ft_substr(depot, len, ft_strlen(depot) - len);
	ft_free(&depot);
	if (!new_depot)
		return (NULL);
	return (new_depot);
}

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}
