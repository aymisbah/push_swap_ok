SRC = main.c swap.c parsing.c utils.c lst_functions.c \
		add_lst.c split.c tools.c push.c less_six.c \
		max_min.c sort.c sort_tools.c sort_tools_tw.c
		          

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror 
AR = ar cr
RM = rm -rf
NAME = pushswap.a
HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJB)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean

