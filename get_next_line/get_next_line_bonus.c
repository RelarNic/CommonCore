#include "get_next_line.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*dest;
	int		long_final;

	if (s1 == NULL)
		return (NULL);
	if (s2 == NULL)
		return ((char *)s1);
	long_final = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc((long_final + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	dest[0] = '\0';
	ft_strcat(dest, s1);
	ft_strcat(dest, s2);
	free(s1);
	return (dest);
}

char	*restore_words(char *words)
{
	int	i;
	int n;
	char	*new_result;

	if (!words)
		return (NULL);
	i = 0;
	while(words[i] != '\n' && words[i] != '\0')
		i++;
	if (words[i] == '\0')
	{
		free(words);
		return (NULL);
	}
	new_result = ft_calloc(sizeof(char), ft_strlen(words) - i + 1); //quitar primera frase, añadir /0
	n = 0;
	i++;
	while(words[i] != '\0') //saltar enter
		new_result[n++] = words[i++];
	free(words);
	return(new_result);
}

char *line_to_deliver(char *words)
{
	int	i;
	char	*final_sentence;

	i = 0;
	while(words[i] != '\n' && words[i] != '\0')
		i++;
	final_sentence = ft_calloc(sizeof(char),  i + 2); //longitud primera frase, enter y /0
	if(!final_sentence)
	{
		free(final_sentence);
		return(NULL);
	}
	i = 0;
	while(words[i] != '\n' && words[i] != '\0')
	{
		final_sentence[i] = words[i];
		i++;
	}
	if(words[i] == '\n')
		final_sentence[i] = words[i];
	return(final_sentence);
}

char *read_until_enter(int fd, char *word)
{
	int	chars_read;
	char *buf;

	buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buf)
		return(NULL);
	chars_read = 1; 
	while (chars_read > 0  && (ft_strchr(word, '\n') == NULL))
	{
		chars_read = read(fd, buf, BUFFER_SIZE);
		if (chars_read == -1)
		{
			free(buf);
			free(word);
			return(NULL);
		}
		buf[chars_read] = '\0';
		word = ft_strjoin_free(word, buf);
	}
	free(buf);
	return(word);
}

char *get_next_line(int fd)
{
	static char *words[1024];
	char		*final_sentence;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!words[fd])
		words[fd] = ft_calloc(1, 1);
	if (!words[fd])
		return (NULL);
	words[fd] = read_until_enter(fd, words[fd]);
	if (!words[fd] || !*words[fd])
	{
		free(words[fd]);
		words[fd] = NULL;
		return (NULL);
	}
	final_sentence = line_to_deliver(words[fd]);
	words[fd] = restore_words(words[fd]); //si ultimo buf fue xx/nyy, poder tener ese yy final para siguiente iteración
	return(final_sentence);
}
