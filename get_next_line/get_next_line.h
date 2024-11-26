#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char *get_next_line(int fd);
char	*ft_strjoin_free(char *s1, char *s2);
void	ft_bzero(void *s, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr_first_part(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strcat(char *dest, const char *src);
char *read_until_enter(int fd, char *words, char *final_sentence);
char	*restore_words(char *words);



#endif