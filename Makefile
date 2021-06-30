
NAME			= 	so_long

SRCS			=	get_next_line/get_next_line.c\
					srcs/main.c\
					srcs/check_err.c\
					srcs/map.c\
					srcs/process.c\
					utils/ft_split.c\
					utils/printer.c\
					utils/ft_strdup.c\
					utils/ft_strjoin_char.c\
					utils/ft_strlen.c\
					utils/ft_strtrim.c\
					utils/ft_strchr.c\
					utils/ft_calloc.c\
					utils/ft_is.c\
					utils/ft_atoi.c\
					utils/utilities.c\
					utils/utilities2.c\

#############################

ifeq ($(OS),Windows_NT)
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

ifeq ($(detected_OS),Darwin)
    MLXFLAGS = -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
endif
ifeq ($(detected_OS),Linux)
    MLXFLAGS = -lm -lbsd -lmlx -lXext -lX11
endif

#############################

FLAGS			= -g -Wall -Werror -Wextra

GCC 			= gcc

INCLUDE			= -I header

RED 			= \033[0;31m
PURPLE			= \033[0;35m
GREEN			= \033[1;32m
RESET			= \033[0m


all: $(NAME)

$(NAME):
			@echo "${PURPLE}[Compilando Minilibx...]${RESET}"
			@$(GCC) $(SRCS) $(FLAGS) $(MLXFLAGS) -o $(NAME)
			@echo "${GREEN}[.oOo.oOo.oOo.oOo.]"
			@echo "[ C O M P I L A O ]"
			@echo "[.oOo.oOo.oOo.oOo.]${RESET}"

run: re
	clear && ./so_long maps/mapa.ber

norminette:
	norminette srcs/* header/* utils/*

fclean:	clean
	@echo "${RED}[Eliminando Ejecutable...]${RESET}"
	rm -f $(NAME)

clean :
	@echo "\033[0;31m[Borrando Objetos...]${RESET}"
	$(RM) $(OBJS)

re:				fclean all

.PHONY:	clean all
