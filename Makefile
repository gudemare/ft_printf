# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/18 01:13:53 by gudemare          #+#    #+#              #
#    Updated: 2017/04/09 19:00:15 by gudemare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror

LIB			=	libft/libft.a
HEADERS_LIB	=	libft/includes

HEADERS_DIR	=	includes/

SRCS_DIR	=	srcs/
SRCS_LIST	=	\
				ft_printf.c \
				fill_spec.c \
				handle_int.c \
				handle_str.c \
				handle_char.c
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS_DIR	=	./objs/
OBJS_LIST	=	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))

.PHONY : all norme clean fclean re debug debug_re

all: $(NAME)

$(NAME) : $(OBJS) $(LIB)
	@mkdir -p $(OBJS_DIR)/libft
	@cd $(OBJS_DIR)/libft && ar x ../../$(LIB)
	@ar rc $(NAME) $(OBJS) $(OBJS_DIR)/libft/*.o $(LIB)
	@ranlib $(NAME)
	@printf "\e[32mLibrary \e[1m$(NAME)\e[0m\e[32m successfully compiled.\e[0m\n"

$(LIB) :
	@make -C libft -j8 1>/dev/null

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I $(HEADERS_DIR) -I $(HEADERS_LIB) -c $< -o $@

norme :
	@if type "norminette" &> /dev/null ; then\
		printf "\e[34m\e[1mChecking Norm ...\e[s\n\e[0m" && \
		norminette $(SRCS) $(HEADERS_DIR)*.h | grep -v -B 1 "^Norme: " || printf "\e[u\e[$$(tput cols)C\e[11D\e[32m\e[7m[ NORME OK ]\e[21m\e[0m\n" ; \
	else\
		printf "\e[31mNorminette not installed, not checking norm.\e[$$(tput cols)C\e[8D\e[7m[ Error ]\n\e[21m\e[0m";\
	fi

clean :
	@make -C libft clean 1>/dev/null
	@rm -rf $(OBJS_DIR)
	@printf "\e[33m$(NAME)'s objects files have been removed.\e[0m\n"
fclean :
	@make -C libft fclean 1>/dev/null
	@rm -rf $(NAME) $(OBJS_DIR)
	@printf "\e[33mLibrary \e[1m$(NAME)\e[0m\e[33m and its projects files have been removed.\e[0m\n"

test : all
	@$(CC) $(CFLAGS) -I $(HEADERS_DIR) -I $(HEADERS_LIB) -L. -lftprintf -g main.c
	@printf "Test binary created\n"

re: fclean all

debug : CFLAGS=-Wall -Wextra -fsanitize=address -g
debug : norme all

debug_re : fclean debug
