.PHONY: all clean fclean re log bonus libft

CC = cc
NAME = push_swap
LIBFT = ./lib/libft.a
LIBFT_DIR = ./libft
CFLAGS = -Wall -Wextra -Werror
UNAME := $(shell uname)
LIBS := -lft

ifeq ($(UNAME), Darwin)
	CFLAGS = -Wall -Wextra -Werror -arch x86_64
endif

SRCS = linked_list.c push_swap.c utils.c markup.c parse.c moves.c moves2.c solve_b_to_a.c solve_a_to_b.c solve.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I libft/include -I include -c $< -o $@ 

$(NAME): $(OBJS) | libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS) -L $(LIBFT_DIR)

libft:
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(LIBFT)
	make fclean -C $(LIBFT_DIR)

re: fclean all

git_libft:
	git clone https://github.com/taandreo/42-libft.git libft