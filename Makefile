CC= cc
NAME= fractol
CFLAGS= -Wall -Wextra -Werror
MLX_FLAGS= -Lminilibx-linux -lmlx_Linux -lX11 -lXext

SRC= main.c \
	mandelbrot.c \
	julia.c \
	handle_input.c \
	utils.c \
	error.c \
	color.c \
	math.c \
	
OBJ= $(SRC:%.c=%.o)

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${MLX_FLAGS} ${OBJ} -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJ}
	
fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re