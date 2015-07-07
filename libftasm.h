#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

void	ft_bzero(char *s, size_t n);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strcat(char *s, char *s1);
int		ft_puts(char * c);

char	*ft_strdup(char *s);
size_t	ft_strlen(char *s);
void	*ft_memset(void *b, int c, size_t l);
void	*ft_memcpy(void *b, void *c, size_t l);

void	ft_cat(int fd);

int		ft_isinteger(char *);
int		ft_isfloat(char *);
void	ft_putchar(char);
int		ft_isspace(int);
char	*ft_strchr(char *, char);
