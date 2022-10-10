SRC_SEVER	=	server.c

SRC_CLIENT	=	client.c	

OBJ_SEVER	=	{SRC_SEVER:.c=.o}

OBJ_CLIENT	=	{SRC_CLIENT:.c=.o}

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

SERVER		=	server

CLIENT		=	client

all:		$(NAME)

$(NAME):	$(SERVER) $(CLIENT)
			$(CC) $(CFLAGS) $(SRC_SEVER) -o $(SERVER)
			$(CC) $(CFLAGS) $(SRC_CLIENT) -o $(CLIENT)

client:		
			$CC
re:			fclean all

clean:
			rm -f $(OBJ_SEVER) $(OBJ_CLIENT)

fclean:		clean
			rm -f $(NAME)

.PHONY:		all re clean fclean