NAME = so_long

SRC = draw_map.c ft_parse.c ft_putnbr.c game.c read_map.c so_long.c valide_map.c \
		get_file/get_next_line_utilise.c get_file/get_next_line.c

INC = so_long.h
OBJS = ${SRC:.c=.o}

CC = cc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -Lmlx -lmlx -lX11 -lXext

RM = rm -f

all: ${NAME}

%.o: %.c ${INC}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${OBJS} -o ${NAME} ${LDFLAGS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
