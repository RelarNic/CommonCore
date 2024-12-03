#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	size_t	i;
	void	*ptr;

	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		((char *)ptr)[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strcat(char *dest, const char *src)
{
	char	*temp;

	temp = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (temp);
}

// void cleanup_gnl(char **words) 
// {
// 	int	i;

// 	i = 0;
// 	while (i<1024)
// 	{
// 		if(words[i])
// 		{
// 			free(words[i]);
// 			words[i] = NULL;
// 		}
// 		i++;
// 	}
// }