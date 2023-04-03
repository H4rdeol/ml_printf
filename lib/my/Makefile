##
## EPITECH PROJECT, 2023
## my_paint
## File description:
## Makefile
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	"libmy.a"

all: $(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@mv $(NAME) ../
	@cp mylib.h ../../include

clean:
	@rm -rf $(OBJ)

fclean:	clean
	@rm -rf ../$(NAME)
