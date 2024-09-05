NAME = philo
CC = gcc
ODIR = obj
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=leak
RM		= rm -f

SRC =	src/utils.c \
		src/actions.c \
		src/threads.c \
		src/main.c \

OBJS = $(patsubst src/%.c,$(ODIR)/%.o,$(SRC))

all: $(NAME)

$(ODIR):
		mkdir -p $(ODIR)

$(ODIR)/%.o: src/%.c | $(ODIR)
		$(CC) -I includes/. $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		$(RM) $(ODIR)/*.o

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: bonus all clean fclean re