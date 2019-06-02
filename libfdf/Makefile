NAME = libfdf.a

SRC = ft_valid_map.c ft_rec.c ft_new_lst.c ft_run_window.c ft_drawstr.c \
		ft_free.c bresenham.c key_hooks.c mouse_press.c mouse_release.c \
		mouse_move.c rotations.c

OBJECT = ft_valid_map.o ft_rec.o ft_new_lst.o ft_run_window.o ft_drawstr.o \
		ft_free.o bresenham.o key_hooks.o mouse_press.o mouse_release.o \
		mouse_move.o rotations.o

INCLUDES =  libft/

FLAGS = -Wall -Wextra -Werror

LMLX = libmlx/


all: $(NAME)

$(NAME):
	@make -C $(INCLUDES) fclean && make -C $(INCLUDES)
	@gcc $(FLAGS) -c $(SRC) -I $(INCLUDES) -I $(LMLX)
	@ar -r -c -s $(NAME) $(OBJECT)
	@mkdir obj && mv $(OBJECT) obj/

norm:
	norminette ft_*.c
	norminette *.h

clean:
	@rm -rf obj
	@make -C $(INCLUDES) fclean

fclean: clean
	@rm -f $(NAME)

re: fclean all
