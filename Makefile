# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 15:52:32 by rponsonn          #+#    #+#              #
#    Updated: 2021/09/24 14:26:07 by rponsonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

${NAME}:				${OBJS}
						@echo Compiling LIBFT
						@make bonus -C ${DIR_LIB}
						@echo LIBFT compiled
						@echo Copying ${LIBFT_A} to root
						cp ${DIR_LIB}${LIBFT_A} ${LIBFT_A}
						@echo Compiling Minilibx
						@make -C ${DIR_LIBX}
						@echo Minilibx compiled
						cp ${DIR_LIBX}${LIBX} ${LIBX}
						${CC} ${CFLAGS} ${LIBFLAGS} -I${DIR_HEAD} -I${DIR_LIBX} -o ${NAME} ${OBJS} ${LIBFT_A}

clean:
						${RM} ${OBJS}
						@make clean -C ${DIR_LIB}
						@make clean -C ${DIR_LIBX}

fclean:					clean
						${RM} ${NAME}
						${RM} ${LIBFT_A}
						${RM} ${LIBX}
						@make fclean -C ${DIR_LIB}

re:						fclean ${NAME}