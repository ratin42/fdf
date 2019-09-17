# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ratin <ratin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 18:46:26 by ratin             #+#    #+#              #
#    Updated: 2019/02/24 01:17:15 by ratin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_PATH := src
OBJ_PATH := obj
INC_PATH := includes
LIB_PATH := libft

SRC_NAME := main.c \
			handle_key.c \
			line.c \
			line2.c \
			get_map.c \
			put_map.c \
			iso_map.c \
			free_tab.c \

OBJECT_NAME := $(SRC_NAME:.c=.o)
INC_NAME := fdf.h

LIB := $(LIB_PATH)/libft.a
LIB_LINK := -L $(LIB_PATH) -lft

SRC := $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ := $(addprefix $(OBJ_PATH)/,$(SRC_NAME:.c=.o))

INCS := -I $(LIB_PATH)/$(INC_DIR) -I $(INC_DIR)
INC := -I /usr/local/include
X := -I /System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/

CC := gcc
CFLAGS := -Wall -Wextra -Werror
MLX := -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

all: obj $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(FLAGS) -o $@ $^ $(MLX) $(LIB_LINK) -lm

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC_PATH)/$(INC_NAME)
	$(CC) $(CFLAGS) $(INC) $(X) -o $@ -c $<

$(LIB):
	make -C $(LIB_PATH)

obj:
	mkdir -p obj

clean:
	rm -rf $(OBJ) $(LIB_PATH)/*.o

fclean: clean
	rm -f $(NAME)
	make -C $(LIB_PATH) fclean

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)/$(NAME).h
	norminette libft/includes/libft.h

.PHONY: all fclean clean re norme
