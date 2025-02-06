NAME = so_long

SRC = draw_map_bonus.c ft_parse_bonus.c ft_putnbr_bonus.c game_bonus.c read_map_bonus.c so_long_bonus.c valide_map_bonus.c \
		get_file/get_next_line_utilise_bonus.c get_file/get_next_line_bonus.c

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
