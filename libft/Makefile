# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 15:09:42 by rponsonn          #+#    #+#              #
#    Updated: 2021/09/30 17:17:13 by rponsonn         ###   ########.fr        #
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

PATH_SRC		=	./srcs/
PATH_HEAD		=	./includes/

SRCS			=	${PATH_SRC}ft_memset.c ${PATH_SRC}ft_bzero.c ${PATH_SRC}ft_memcpy.c ${PATH_SRC}ft_memccpy.c ${PATH_SRC}ft_memmove.c \
					${PATH_SRC}ft_memchr.c ${PATH_SRC}ft_memcmp.c ${PATH_SRC}ft_strlen.c ${PATH_SRC}ft_strlcpy.c ${PATH_SRC}ft_strlcat.c \
					${PATH_SRC}ft_strchr.c ${PATH_SRC}ft_strrchr.c ${PATH_SRC}ft_strnstr.c ${PATH_SRC}ft_strncmp.c ${PATH_SRC}ft_atoi.c \
					${PATH_SRC}ft_isalpha.c ${PATH_SRC}ft_isdigit.c ${PATH_SRC}ft_isalnum.c ${PATH_SRC}ft_isascii.c ${PATH_SRC}ft_isprint.c \
					${PATH_SRC}ft_toupper.c ${PATH_SRC}ft_tolower.c ${PATH_SRC}ft_calloc.c ${PATH_SRC}ft_strdup.c ${PATH_SRC}ft_substr.c \
					${PATH_SRC}ft_strjoin.c ${PATH_SRC}ft_strtrim.c ${PATH_SRC}ft_split.c ${PATH_SRC}ft_itoa.c ${PATH_SRC}ft_strmapi.c \
					${PATH_SRC}ft_putchar_fd.c ${PATH_SRC}ft_putstr_fd.c ${PATH_SRC}ft_putendl_fd.c ${PATH_SRC}ft_putnbr_fd.c \
					${PATH_SRC}ft_utoa.c ${PATH_SRC}ft_strupper.c ${PATH_SRC}ft_atol.c ${PATH_SRC}ft_itoa_hex.c \
					${PATH_SRC}ft_lstnew.c ${PATH_SRC}ft_lstadd_front.c ${PATH_SRC}ft_lstsize.c ${PATH_SRC}ft_lstlast.c \
					${PATH_SRC}ft_lstadd_back.c ${PATH_SRC}ft_lstdelone.c ${PATH_SRC}ft_lstclear.c ${PATH_SRC}ft_lstiter.c \
					${PATH_SRC}ft_lstmap.c ${PATH_SRC}get_next_line_utils.c ${PATH_SRC}get_next_line.c ${PATH_SRC}ft_hex_str_to_int.c
OBJS			=	$(SRCS:.c=.o)

NAME			=	libft.a
CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror

.c.o:
				@${CC} ${CFLAGS} -I${PATH_HEAD} -c $< -o ${<:.c=.o}
				@echo "${GREEN}[ OK ] ${CYAN}${BOLD}${<:.s=.o}${NC}${NC}"

${NAME}:		${OBJS}
				@ar -rcs ${NAME} ${OBJS}
all:			${NAME}

clean:			
				@${RM} ${OBJS}
				@echo "\n${GREEN}[ OK ]${RED}    *.o files deleted${NC}"
fclean:			clean
				@${RM} ${NAME}
				@echo "${GREEN}[ OK ]${RED}    libft.a    deleted${NC}"
re:				fclean ${NAME}
bonus:			${NAME}
.PHONY:			all clean fclean re bonus