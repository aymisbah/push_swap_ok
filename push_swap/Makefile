SRC = main.c swap.c parsing.c utils.c lst_functions.c \
		add_lst.c split.c tools.c push.c less_six.c \
		max_min.c sort.c sort_tools.c sort_tools_tw.c

SRC_B = get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c  \
		swap_bonus.c parsing_bonus.c utils_bonus.c lst_functions_bonus.c \
		add_lst_bonus.c split_bonus.c  tools_bonus.c push_bonus.c

OBJ = ${SRC:.c=.o}

OBJ_B = ${SRC_B:.c=.o}

CC = cc

NAME = push_swap

NAME_B = checker

RM = rm -f

GFLAGS = -Wall -Wextra -Werror 

all : ${NAME}

%.o: %.c push_swap.h 
	${CC} ${GFLAGS} -c $< -o $@ 

%bonus.o: %bonus.c push_swap_bonus.h 
	${CC} ${GFLAGS} -c $< -o $@ 

${NAME} : ${OBJ}
	${CC} ${OBJ} -o ${NAME}

bonus: ${OBJ_B}
	${CC}  ${OBJ_B} -o ${NAME_B}

clean : 
	${RM} ${OBJ} ${OBJ_B} 

fclean : clean
	${RM} ${NAME} ${NAME_B}

re : fclean all

.PHONY: clean fclean all bonus
