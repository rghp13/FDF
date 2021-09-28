# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 15:52:32 by rponsonn          #+#    #+#              #
#    Updated: 2021/09/28 14:47:15 by rponsonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NC = \033[0m
RED = \033[0;91m
ORANGE = \033[93m
GREEN = \x1b[32m
PURPLE = \033[0;95m
BLUE = \033[0;34m
BOLD = \033[1m
CYAN = \x1b[36m

DIR_SRC			=		srcs/

DIR_HEAD		=		includes/

DIR_LIB			=		libft/

SRCS			=		${DIR_SRC}ft_fdf.c

OBJS			=		${SRCS:.c=.o}

NAME			=		fdf
LIBFT_A			=		libft.a
LIBX			=		libmlx.a
CC				=		gcc
RM				=		rm -f
CFLAGS			=		-Wall -Wextra -Werror

OS := $(shell uname -s)
ifeq ($(OS),Darwin)
DIR_LIBX = minilibx_macos/
LIBFLAGS = -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit
else
DIR_LIBX = minilibx-linux/
LIBFLAGS = -Lminilibx-linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
endif

.c.o:
						@${CC} ${CFLAGS} -I${DIR_HEAD} -c $< -o ${<:.c=.o}
						@echo "${GREEN}[ OK ] ${CYAN}${BOLD}${<:.s=.o}${NC}${NC}"

${NAME}:				${OBJS}
						@echo "${ORANGE}Compiling LIBFT${NC}"
						@sleep 1
						@make bonus -C ${DIR_LIB}
						@echo "${PURPLE}LIBFT compiled${NC}"
						@echo Copying ${LIBFT_A} to root
						cp ${DIR_LIB}${LIBFT_A} ${LIBFT_A}
						@echo "${BLUE}Compiling Minilibx${NC}"
						@sleep 1
						@make -C ${DIR_LIBX} >> /dev/null
						@echo "${BLUE}Minilibx compiled${NC}"
						@sleep 1
						@cp ${DIR_LIBX}${LIBX} ${LIBX}
						@${CC} ${CFLAGS} ${LIBFLAGS} -I${DIR_HEAD} -I${DIR_LIBX} -o ${NAME} ${OBJS} ${LIBFT_A}

clean:
						${RM} ${OBJS}
						@make clean -C ${DIR_LIB}
						@make clean -C ${DIR_LIBX}
						@echo "\n${GREEN}[ OK ]${RED}    *.o files deleted${NC}"

fclean:					clean
						@${RM} ${NAME}
						@echo "${GREEN}[ OK ]${RED}    fdf deleted\n${NC}"
						@${RM} ${LIBFT_A}
						@${RM} ${LIBX}
						@make fclean -C ${DIR_LIB}

re:						fclean ${NAME}