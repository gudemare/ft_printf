# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/18 01:13:53 by gudemare          #+#    #+#              #
#    Updated: 2017/06/24 04:49:11 by gudemare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

LIB			=	libft/libft.a
HEADERS_LIB	=	libft/includes

HEADERS_DIR	=	includes/

SRCS_DIR	=	srcs/
SRCS_LIST	=	\
				conv_c.c \
				conv_d.c \
				conv_o.c \
				conv_p.c \
				conv_s.c \
				conv_u.c \
				conv_x.c \
				fill_spec.c \
				ft_anytoa.c \
				ft_printf.c \
				ft_uanytoa.c \
				ft_uanytoa_base.c \
				ft_wcs.c \
				ft_wcs_2.c
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

.PHONY : all norme clean fclean re debug debug_re

all: $(NAME)

$(NAME) : $(LIB) $(OBJS)
	@mkdir -p $(OBJS_DIR)
	@ar rc tmp.a $(OBJS)
	@libtool -static -o $(NAME) - tmp.a $(LIB) ; rm tmp.a
	@ranlib $(NAME)
	@printf "$(GREEN)Library $(BOLD)$(NAME)$(END_GRAPHICS)$(GREEN) has successfully compiled.$(END_GRAPHICS)\n"

$(LIB) :
	@make -C libft

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@printf "\e[K$(CYAN)Compiling $(BOLD)$(notdir $<)$(END_GRAPHICS)$(CYAN) ...\n\e[A$(END_GRAPHICS)"
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

test : debug
	@$(CC) -Wall -Wextra -I $(HEADERS_DIR) -I $(HEADERS_LIB) -L. -lftprintf -g main.c -o test
	@printf "$(GREEN)Test binary created.$(END_GRAPHICS)\n"

re: fclean all

debug : CFLAGS=-Wall -Wextra -g
debug : all
#	@if [ 0 = $$(expr $$(dwarfdump $(NAME) | wc -l) \> 1000) ]; then \
		printf "$(RED)Library does not contain debug symbols. Recompiling.$(END_GRAPHICS)\n" ; \
		make debug_re ; \
	fi
	@printf "\e[K$(GREEN)Library $(BOLD)$(NAME)$(END_GRAPHICS)$(GREEN) has successfully compiled $(YELLOW)(with debug symbols).$(END_GRAPHICS)\n"

debug_re : fclean debug
