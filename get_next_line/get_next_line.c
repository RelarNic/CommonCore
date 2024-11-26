#include "get_next_line.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*dest;
	int		long_final;
	char	*empt;

	if (s1 == NULL)
		return (NULL);
	if (s2 == NULL)
		return ((char *)s1);
	long_final = ft_strlen(s1) + ft_strlen(s2);
	if (long_final == 0)
	{
		empt = malloc((1) * sizeof(char));
		if (empt == NULL)
			return (NULL);
		empt[0] = '\0';
		return (empt);
	}
	dest = malloc((long_final + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	dest[0] = '\0';
	ft_strcat(dest, s1);
	ft_strcat(dest, s2);
	free(s2);
	return (dest);
}

char	*restore_words(char *words)
{
	int	i;
	int n;
	char	*new_result;

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
	while(words[++i] != '\0') //saltar enter
		new_result[n++] = words[i];
	free(words);
	return(new_result);
}

char *read_until_enter(int fd, char *words, char *final_sentence)
{
	int	chars_read;
	char *buf;

	if (!words)
		words = ft_calloc(1, 1);
	buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	chars_read = 1; 
	while (chars_read < BUFFER_SIZE  && (ft_strchr_first_part(buf, '\n') == NULL))
	{
		chars_read = read(fd, buf, BUFFER_SIZE);
		if (chars_read == -1)
		{
			free(buf);
			free(words);
			return(NULL);
		}
		buf[chars_read] = '\0';
		if (ft_strchr_first_part(buf, '\n') == NULL)
			words = ft_strjoin_free(words, buf);
	}
	words = ft_strjoin_free(words, buf);
	buf = ft_strchr_first_part(buf, '\n');
	final_sentence = ft_strjoin_free(words, buf);
	free(buf);
	return(final_sentence);
}

char *get_next_line(int fd)
{
	static char *words;
	char		*final_sentence;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	final_sentence = ft_calloc(1,1); 
	final_sentence = read_until_enter(fd, words, final_sentence);
	if (words == NULL)
		return (words);
	words = restore_words(words); //si ultimo buf fue xx/nyy, poder tener ese yy final para siguiente iteración
	return(final_sentence);
}