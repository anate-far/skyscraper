CC = gcc
SRCS = srcs/main.c srcs/grid.c srcs/tools.c srcs/analize_grid.c srcs/skyscraper.c
FLAGS = -Wall -Wextra #-Werror
HEADER = includes/
OBJ = ${SRCS:.c=.o}
NAME = bin/prog
RM = rm -f

.PHONY : all clean flcean

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(FLAGS)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I$(HEADER)

clean :
	$(RM) $(OBJ)

flcean : clean
	$(RM) $(NAME)