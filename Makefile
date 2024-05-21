# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 19:05:58 by marvin            #+#    #+#              #
#    Updated: 2024/05/17 13:43:00 by tomoron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK		=	[90m
RED			=	[91m
GREEN		=	[92m
YELLOW		=	[93m
BLUE		=	[94m
MAGENTA		=	[95m
CYAN		=	[96m
WHITE		=	[97m

RESET		=	[0m

LINE_CLR	=	\33[2K\r

NAME        :=	RT

SRCS_DIR	:=	srcs

OBJS_DIR	:=	.objs

SRC_PARSING := 	parsing/parsing.c				\
				parsing/utils.c

SRC_WINDOW	:=	window/hooks.c					\
				window/utils.c					\
				window/shader.c

SRC_SETUP	:=	setup/opengl.c					\
				setup/scene.c					\

ALL_SRCS	:=	$(SRC_PARSING) $(SRC_WINDOW)	\
				$(SRC_SETUP)					\
				RT.c gl.c
				
SRCS		:=	$(ALL_SRCS:%=$(SRCS_DIR)/%)


OBJS		:=	$(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))

CC          :=	gcc

IFLAGS	    :=	-g -I./include -L./lib -lglfw3 -lopengl32 -lgdi32 -lcglm

RM          :=	del /f /s /q

MAKEFLAGS   += --no-print-directory

DIR_DUP     =	if not exist "$(@D)" mkdir "$(@D)"

# RULES ********************************************************************** #

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	@$(CC) -o $(NAME) $(OBJS) $(IFLAGS)
	@echo $(WHITE) $(NAME): PROJECT COMPILED !$(RESET) & echo:

$(OBJS_DIR)/%.o: %.c
	@$(DIR_DUP)
	@echo $(WHITE) $(NAME): $(WHITE)$<$(RESET) $(GREEN)compiling...$(RESET)
	@$(CC) -c $^ $(IFLAGS) -o $@ 


fclean:
	@echo  $(WHITE)$(NAME):$(RED) cleaned.$(RESET)
	@del /f /s /q $(NAME).exe
	@rmdir /S /Q "$(OBJS_DIR)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

# **************************************************************************** #

.PHONY: all clean fclean dclean re bonus