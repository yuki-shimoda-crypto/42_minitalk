SRC_SEVER		=	server.c
SRC_CLIENT		=	client.c

OBJ_SEVER		=	$(SRC_SEVER:.c=.o)
OBJ_CLIENT		=	$(SRC_CLIENT:.c=.o)

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror

NAME			=	minitalk
NAME_SERVER		=	server
NAME_CLIENT		=	client

all:			$(NAME)

$(NAME):		$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):	$(OBJ_SEVER)
				make -C printf
				$(CC) $(CFLAGS) $(OBJ_SEVER) printf/libftprintf.a -o $(NAME_SERVER)

$(NAME_CLIENT):	$(OBJ_CLIENT)
				make -C printf
				$(CC) $(CFLAGS) $(OBJ_CLIENT) printf/libftprintf.a -o $(NAME_CLIENT)

re:				fclean all

clean:
				make fclean -C printf
				rm -f $(OBJ_SEVER) $(OBJ_CLIENT)

fclean:			clean
				rm -f $(NAME_SERVER) $(NAME_CLIENT)

.PHONY:			all re clean fclean
