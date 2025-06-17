CC = cc 
CFILES = $(wildcard *.c)
NAME = cub3d 
FLAGS = #-fsanitize=address
OFILES = $(CFILES:.c=.o)

all : $(NAME)

%.o : %.c 
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OFILES)
	$(CC) $(FLAGS) $(OFILES) -o $(NAME) 

clean :
	rm -rf $(OFILES)

fclean :
	rm -rf $(OFILES) $(NAME)

re : fclean all