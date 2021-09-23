# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 15:52:32 by rponsonn          #+#    #+#              #
#    Updated: 2021/09/23 16:50:04 by rponsonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_SRC			=		srcs/

DIR_HEAD		=		includes/

DIR_LIB			=		libft/

DIR_MAC			=		minilibx_macos/

DIR_LINUX		=		minilibx-linux/

SRCS			=		${DIR_SRC}ft_fdf.c

OBJS			=		${SRCS:.c=.o}

NAME			=		fdf
LIBFT_A			=		libft.a
CC				=		gcc
RM				=		rm -f
CFLAGS			=		-Wall -Wextra -Werror

OS := $(shell uname -s)
ifeq ($(uname),Darwin)

.c.o:
						@${CC} ${CFLAGS} -I${DIR_HEAD} -c $< -o ${<:.c=.o}

${NAME}:				${OBJS}
						@echo Compiling LIBFT
						@make -C bonus ${DIR_LIB}
						@echo LIBFT compiled
						@echo Copying ${LIBFT_A} to root
						cp ${DIR_LIB}${LIBFT_A} ${LIBFT_A}
						${CC} ${CFLAGS} -I${DIR_HEAD} -o ${NAME} ${OBJS} ${LIBFT_A}