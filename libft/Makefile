# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 15:09:42 by rponsonn          #+#    #+#              #
#    Updated: 2021/09/22 16:16:32 by rponsonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_SRC		=	./srcs/
PATH_HEAD		=	./includes/

SRCS			=	${PATH_SRC}ft_memset.c ${PATH_SRC}ft_bzero.c ${PATH_SRC}ft_memcpy.c ${PATH_SRC}ft_memccpy.c ${PATH_SRC}ft_memmove.c \
					${PATH_SRC}ft_memchr.c ${PATH_SRC}ft_memcmp.c ${PATH_SRC}ft_strlen.c ${PATH_SRC}ft_strlcpy.c ${PATH_SRC}ft_strlcat.c \
					${PATH_SRC}ft_strchr.c ${PATH_SRC}ft_strrchr.c ${PATH_SRC}ft_strnstr.c ${PATH_SRC}ft_strncmp.c ${PATH_SRC}ft_atoi.c \
					${PATH_SRC}ft_isalpha.c ${PATH_SRC}ft_isdigit.c ${PATH_SRC}ft_isalnum.c ${PATH_SRC}ft_isascii.c ${PATH_SRC}ft_isprint.c \
					${PATH_SRC}ft_toupper.c ${PATH_SRC}ft_tolower.c ${PATH_SRC}ft_calloc.c ${PATH_SRC}ft_strdup.c ${PATH_SRC}ft_substr.c \
					${PATH_SRC}ft_strjoin.c ${PATH_SRC}ft_strtrim.c ${PATH_SRC}ft_split.c ${PATH_SRC}ft_itoa.c ${PATH_SRC}ft_strmapi.c \
					${PATH_SRC}ft_putchar_fd.c ${PATH_SRC}ft_putstr_fd.c ${PATH_SRC}ft_putendl_fd.c ${PATH_SRC}ft_putnbr_fd.c \
					${PATH_SRC}ft_utoa.c ${PATH_SRC}ft_strupper.c ${PATH_SRC}ft_atol.c ${PATH_SRC}ft_itoa_hex.c
OBJS			=	$(SRCS:.c=.o)

BONUS			=	${PATH_SRC}ft_lstnew.c ${PATH_SRC}ft_lstadd_front.c ${PATH_SRC}ft_lstsize.c ${PATH_SRC}ft_lstlast.c \
					${PATH_SRC}ft_lstadd_back.c ${PATH_SRC}ft_lstdelone.c ${PATH_SRC}ft_lstclear.c ${PATH_SRC}ft_lstiter.c \
					${PATH_SRC}ft_lstmap.c ${PATH_SRC}get_next_line_utils.c ${PATH_SRC}get_next_line.c
BOBJS			=	$(BONUS:.c=.o)

NAME			=	libft.a
CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror

.c.o:
				@${CC} ${CFLAGS} -I${PATH_HEAD} -c $< -o ${<:.c=.o}

${NAME}:		${OBJS}
				@ar -rcs ${NAME} ${OBJS}
all:			${NAME}

clean:			
				${RM} ${OBJS} ${BOBJS}
fclean:			clean
				${RM} ${NAME}
re:				fclean ${NAME}
bonus:			${OBJS} ${BOBJS}
				ar -rcs ${NAME} ${OBJS} ${BOBJS}
.PHONY:			all clean fclean re bonus