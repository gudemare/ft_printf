# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/18 01:13:53 by gudemare          #+#    #+#              #
#    Updated: 2017/04/20 09:28:01 by gudemare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror

HEADERS_DIR		=	includes/

SRCS_DIR	=	srcs/
SRCS_LIST	=	\
				btree/ft_btree_apply_infix.c \
				btree/ft_btree_apply_prefix.c \
				btree/ft_btree_apply_suffix.c \
				btree/ft_btree_insert_data.c \
				btree/ft_btree_lvlcount.c \
				btree/ft_btree_nodenew.c \
				btree/ft_btree_search_data.c \
				btree/ft_btree_treedel.c \
				display/ft_putchar.c \
				display/ft_putchar_fd.c \
				display/ft_putendl.c \
				display/ft_putnendl.c \
				display/ft_putendl_fd.c \
				display/ft_putnendl_fd.c \
				display/ft_putnbr.c \
				display/ft_putnbr_fd.c \
				display/ft_putstr.c \
				display/ft_putnstr.c \
				display/ft_putstr_fd.c \
				display/ft_putnstr_fd.c \
				list/ft_lstadd.c \
				list/ft_lstdel.c \
				list/ft_lstdelone.c \
				list/ft_lstiter.c \
				list/ft_lstmap.c \
				list/ft_lstnew.c \
				math/ft_abs.c \
				math/ft_isprime.c \
				math/ft_max.c \
				math/ft_min.c \
				math/ft_power.c \
				math/ft_sign.c \
				math/ft_sqrt.c \
				memory/ft_bzero.c \
				memory/ft_memalloc.c \
				memory/ft_memccpy.c \
				memory/ft_memchr.c \
				memory/ft_memcmp.c \
				memory/ft_memcpy.c \
				memory/ft_memdel.c \
				memory/ft_memmove.c \
				memory/ft_memrchr.c \
				memory/ft_memset.c \
				misc/ft_arg.c \
				misc/ft_atoi.c \
				misc/ft_basename.c \
				misc/ft_dirname.c \
				misc/ft_isalnum.c \
				misc/ft_isalpha.c \
				misc/ft_isascii.c \
				misc/ft_iscntrl.c \
				misc/ft_isdigit.c \
				misc/ft_isprint.c \
				misc/ft_ispunct.c \
				misc/ft_isspace.c \
				misc/ft_isxdigit.c \
				misc/ft_itoa.c \
				misc/ft_tolower.c \
				misc/ft_toupper.c \
				string/ft_strcasecmp.c \
				string/ft_strcasestr.c \
				string/ft_strcat.c \
				string/ft_strchr.c \
				string/ft_strchrnul.c \
				string/ft_strclr.c \
				string/ft_strcmp.c \
				string/ft_strcpy.c \
				string/ft_strdel.c \
				string/ft_strdup.c \
				string/ft_strequ.c \
				string/ft_strextend.c \
				string/ft_striter.c \
				string/ft_striteri.c \
				string/ft_strjoin.c \
				string/ft_strlcat.c \
				string/ft_strlen.c \
				string/ft_strmap.c \
				string/ft_strmapi.c \
				string/ft_strncat.c \
				string/ft_strncmp.c \
				string/ft_strncpy.c \
				string/ft_strndup.c \
				string/ft_strnequ.c \
				string/ft_strnew.c \
				string/ft_strnstr.c \
				string/ft_strrchr.c \
				string/ft_strsplit.c \
				string/ft_strstr.c \
				string/ft_strsub.c \
				string/ft_strtrim.c
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

$(NAME) :
	@make progress
	@make $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "\e[u\n$(END_GRAPHICS)"

progress :
	@printf "$(ITALIC)$(CYAN)Compiling $(BOLD)$(notdir $(NAME)) ...$(END_GRAPHICS)$(WHITE)\n\e[s"
	@printf "\xE2\x96\xae%.0s" {1..90}
	@printf "\e[u$(END_GRAPHICS)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR) $(OBJS_DIR){btree,display,list,math,memory,misc,string}
	@printf "$(GREEN)\xE2\x9D\x9a"
	@$(CC) $(CFLAGS) -I $(HEADERS_DIR) -c $< -o $@


clean :
	@rm -rf $(OBJS_DIR)
fclean :
	@rm -rf $(NAME) $(OBJS_DIR)

re: fclean all
