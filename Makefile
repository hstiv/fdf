NAME = fdf

FLAGS = -Wall -Wextra -Werror

S = srcs/

SRCS = $(S)main.c $(S)fdf.c

SRCO = main.o fdf.o

LFT = libfdf/libft/

LFDF = libfdf/

LMLX = $(LFDF)libmlx/

SRC_LMLX = $(FRAME) -L $(LMLX) -lmlx

FRAME = -framework OpenGL -framework AppKit

FDF_H = includes/ 

all: $(NAME)

$(NAME):
	@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compiling... Wait a sec."
	@make -C $(LFDF) fclean && make -C $(LFDF)
	@gcc $(FLAGS) -c $(SRCS) -I $(LFDF) -I $(LFT) -I $(FDF_H)
	@gcc -o $(NAME) $(SRCO) -L $(LFDF) -lfdf -L $(LFT) -lft $(SRC_LMLX)
	@mkdir obj && mv $(SRCO) obj/
	@echo "(•̀ᴗ•́)و $(NAME) generated!".
	 
clean:
	@rm -rf obj
	@make -C $(LFDF) fclean

fclean: clean
	@rm -f $(NAME)

re: fclean all
