# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/18 01:13:53 by gudemare          #+#    #+#              #
#    Updated: 2017/04/20 09:29:09 by gudemare         ###   ########.fr        #
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
				handle_format.c \
				handle_convertion.c \
				handle_int.c \
				handle_str.c \
				handle_char.c
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS_DIR	=	./objs/
OBJS_LIST	=	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))

END_GRAPHICS=	\e[0m
BOLD		=	\e[1m
DARK		=	\e[2m
ITALIC		=	\e[3m
UNDERSCORE	=	\e[4m
REVERSE_VID	=	\e[7m
BLACK		=	\e[30m
RED			=	\e[31m
GREEN		=	\e[32m
YELLOW		=	\e[33m
BLUE		=	\e[34m
MAGENTA		=	\e[35m
CYAN		=	\e[36m
WHITE		=	\e[37m
BLACK_BG	=	\e[40m
RED_BG		=	\e[41m
GREEN_BG	=	\e[42m
YELLOW_BG	=	\e[43m
BLUE_BG		=	\e[44m
MAGENTA_BG	=	\e[45m
CYAN_BG		=	\e[46m
WHITE_BG	=	\e[47m

.PHONY : all progress norme clean fclean re debug debug_re

all: $(NAME)

$(NAME) : $(LIB) progress $(OBJS)
	@mkdir -p $(OBJS_DIR)
	@ar rc tmp.a $(OBJS)
	@libtool -static -o $(NAME) - tmp.a $(LIB) ; rm tmp.a
	@ranlib $(NAME)
	@tput cnorm
	@printf "\e[u$(END_GRAPHICS)\n$(GREEN)Library $(BOLD)$(NAME)$(END_GRAPHICS)$(GREEN) has successfully compiled.$(END_GRAPHICS)\n"

$(LIB) :
	@stty -echo 
	@tput civis
	@make -C libft -j -s

progress :
	@printf "$(ITALIC)$(CYAN)Compiling $(BOLD)$(notdir $(NAME)) ...$(END_GRAPHICS)$(WHITE)\n\e[s"
	@printf "\xE2\x96\xae%.0s" {1..7}
	@printf "\e[u$(END_GRAPHICS)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@printf "$(GREEN)\xE2\x9D\x9a"
	@$(CC) $(CFLAGS) -I $(HEADERS_DIR) -I $(HEADERS_LIB) -c $< -o $@

norme :
	@if type "norminette" &> /dev/null ; then\
		printf "$(BLUE)$(BOLD)Checking Norm ...$(END_GRAPHICS)\n\e[A" && \
		norminette $(SRCS) $(HEADERS_DIR)*.h | grep -v -B 1 "^Norme: " || printf "\e[$$(tput cols)C\e[11D$(GREEN)$(REVERSE_VID)[ NORME OK ]$(END_GRAPHICS)\n" ; \
	else\
		printf "$(RED)Norminette not installed, not checking norm.\n$(END_GRAPHICS)";\
	fi

clean :
	@make -C libft clean 1>/dev/null
	@rm -rf $(OBJS_DIR)
	@printf "$(YELLOW)Library $(BOLD)$(NAME)$(END_GRAPHICS)$(YELLOW)'s objects files have been removed.$(END_GRAPHICS)\n"
fclean :
	@make -C libft fclean 1>/dev/null
	@rm -rf $(NAME) $(OBJS_DIR)
	@printf "$(YELLOW)Library $(BOLD)$(NAME)$(END_GRAPHICS)$(YELLOW) and its objects files have been removed.$(END_GRAPHICS)\n"

test : all
	@$(CC) $(CFLAGS) -I $(HEADERS_DIR) -I $(HEADERS_LIB) -L. -lftprintf -g main.c
	@printf "Test binary created\n"

re: fclean all

debug : CFLAGS=-Wall -Wextra -g
debug : all

debug_re : fclean debug
