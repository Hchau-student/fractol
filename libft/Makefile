FILES = ft_memset.c \
ft_bzero.c \
ft_putendl.c \
ft_putnbr_fd.c \
ft_putnbr.c \
ft_putchar.c \
ft_strjoin.c \
ft_strlen.c \
ft_strnew.c \
ft_putchar.c \
ft_putchar_fd.c \
ft_putstr.c \
ft_striter.c \
ft_striteri.c \
ft_strsub.c \
ft_putstr_fd.c \
ft_memalloc.c \
ft_memdel.c \
ft_strdel.c \
ft_itoa.c \
ft_strclr.c \
ft_strcmp.c \
ft_strequ.c \
ft_strncmp.c \
ft_strnequ.c \
ft_putendl_fd.c \
ft_itoa.c \
ft_memcpy.c \
ft_memccpy.c \
ft_memmove.c \
ft_memchr.c \
ft_memcmp.c \
ft_strdup.c \
ft_strcpy.c \
ft_strncpy.c \
ft_strcat.c \
ft_strncat.c \
ft_strlcat.c \
ft_atoi.c \
ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strstr.c \
ft_strnstr.c \
ft_strmap.c \
ft_strmapi.c \
ft_strtrim.c \
ft_strsplit.c \
ft_strcdup.c \
ft_freematr.c \
ft_one_delim.c \
ft_lstnew.c \
ft_lstdelone.c \
ft_lstdel.c \
ft_lstadd.c \
ft_lstiter.c \
ft_lstmap.c \
ft_lstclr.c \
ft_swap.c \
ft_twlstnew.c \
ft_twlstdelone.c \
ft_twlstdel.c \
ft_twlstadd.c \
ft_twlstiter.c \
ft_twlstmap.c \
ft_twlstclr.c \
ft_twlstdel_backw.c \
ft_strcpy_return.c \

OBJ = ft_memset.o \
ft_bzero.o \
ft_putendl.o \
ft_putnbr_fd.o \
ft_putnbr.o \
ft_putchar.o \
ft_strjoin.o \
ft_strlen.o \
ft_strnew.o \
ft_putchar.o \
ft_putchar_fd.o \
ft_putstr.o \
ft_striter.o \
ft_striteri.o \
ft_strsub.o \
ft_putstr_fd.o \
ft_memalloc.o \
ft_memdel.o \
ft_strdel.o \
ft_itoa.o \
ft_strclr.o \
ft_strcmp.o \
ft_strequ.o \
ft_strncmp.o \
ft_strnequ.o \
ft_putendl_fd.o \
ft_itoa.o \
ft_memcpy.o \
ft_memccpy.o \
ft_memmove.o \
ft_memchr.o \
ft_memcmp.o \
ft_strdup.o \
ft_strcpy.o \
ft_strncpy.o \
ft_strcat.o \
ft_strncat.o \
ft_strlcat.o \
ft_atoi.o \
ft_isalpha.o \
ft_isdigit.o \
ft_isalnum.o \
ft_isascii.o \
ft_isprint.o \
ft_toupper.o \
ft_tolower.o \
ft_strchr.o \
ft_strrchr.o \
ft_strstr.o \
ft_strnstr.o \
ft_strmap.o \
ft_strmapi.o \
ft_strtrim.o \
ft_strsplit.o \
ft_strcdup.o \
ft_freematr.o \
ft_one_delim.o \
ft_lstnew.o \
ft_lstdelone.o \
ft_lstdel.o \
ft_lstadd.o \
ft_lstiter.o \
ft_lstmap.o \
ft_lstclr.o \
ft_swap.o \
ft_twlstnew.o \
ft_twlstdelone.o \
ft_twlstdel.o \
ft_twlstadd.o \
ft_twlstiter.o \
ft_twlstmap.o \
ft_twlstclr.o \
ft_twlstdel_backw.o \
ft_strcpy_return.o \

FLAGS = -Wall -Werror -Wextra

INCLUDES = libft.h

NAME = libft.a

$(NAME):
		@gcc -c $(FLAGS) -I $(INCLUDES) $(FILES)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

all: $(NAME)

clean:
		@/bin/rm -Rf $(OBJ)

fclean:	clean
		@/bin/rm -Rf $(NAME)

re:	fclean all
