NAME = so_long
NAME_BNS = so_long_bonus

SRC = mandatory/draw_map.c mandatory/ft_parse.c mandatory/ft_putnbr.c mandatory/game.c mandatory/read_map.c mandatory/so_long.c mandatory/valide_map.c \
		mandatory/helper.c mandatory/get_file/get_next_line_utilise.c mandatory/get_file/get_next_line.c

SRC_BNS = bonus/draw_map_bonus.c bonus/ft_parse_bonus.c bonus/ft_putnbr_bonus.c bonus/game_bonus.c bonus/read_map_bonus.c bonus/so_long_bonus.c bonus/valide_map_bonus.c \
		bonus/helper_bonus.c bonus/store_enemy.c bonus/move_enemy.c bonus/animation.c bonus/read_file/get_next_line_utilise.c bonus/read_file/get_next_line.c

INC = mandatory/so_long.h
INC_BNS = bonus/so_long_bonus.h

OBJS = ${SRC:.c=.o}
OBJS_BNS = ${SRC_BNS:.c=.o}

CC = cc -Wall -Werror -Wextra
LDFLAGS = -Lmlx -lmlx -lX11 -lXext

RM = rm -f

all: ${NAME}

bonus: ${NAME_BNS}

mandatory/%.o: mandatory/%.c ${INC}
	${CC} -c $< -o $@

bonus/%.o: bonus/%.c ${INC_BNS}
	${CC} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${OBJS} -o ${NAME} ${LDFLAGS}

${NAME_BNS}: ${OBJS_BNS}
	${CC} ${OBJS_BNS} -o ${NAME_BNS} ${LDFLAGS}

clean:
	${RM} ${OBJS} ${OBJS_BNS}

fclean: clean
	${RM} ${NAME} ${NAME_BNS}

re: fclean all
