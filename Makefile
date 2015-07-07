NAME = libfts.a

FTO = ft_isalpha.o\
	  ft_isprint.o\
	  ft_tolower.o\
	  ft_bzero.o\
	  ft_isascii.o\
	  ft_puts.o\
	  ft_toupper.o\
	  ft_isalnum.o\
	  ft_isdigit.o\
	  ft_strcat.o\
	  ft_strlen.o\
	  ft_memset.o\
	  ft_memcpy.o\
	  ft_strdup.o\
	  ft_isfloat.o\
	  ft_isspace.o\
	  ft_isinteger.o\
	  ft_putchar.o\
	  ft_strchr.o\
	  ft_cat.o

all: $(NAME)

$(NAME):
	nasm -f macho64 ft_isalpha.s
	nasm -f macho64 ft_isprint.s
	nasm -f macho64 ft_tolower.s
	nasm -f macho64 ft_bzero.s
	nasm -f macho64 ft_isascii.s
	nasm -f macho64 ft_puts.s
	nasm -f macho64 ft_toupper.s
	nasm -f macho64 ft_isalnum.s
	nasm -f macho64 ft_isdigit.s
	nasm -f macho64 ft_strcat.s
	nasm -f macho64 ft_strlen.s
	nasm -f macho64 ft_memset.s
	nasm -f macho64 ft_memcpy.s
	nasm -f macho64 ft_strdup.s
	nasm -f macho64 ft_cat.s
	nasm -f macho64 ft_isfloat.s
	nasm -f macho64 ft_isinteger.s
	nasm -f macho64 ft_putchar.s
	nasm -f macho64 ft_isspace.s
	nasm -f macho64 ft_strchr.s
	ar rc $(NAME) $(FTO)

clean:
	rm -rf $(FTO)

fclean: clean
	rm -rf $(NAME)
	rm -rf test_bonus
	rm -rf test_obli

re: fclean all

obl:
	gcc -o test_obli mainO.c $(NAME)

bonus:
	gcc -o test_bonus mainB.c $(NAME)
