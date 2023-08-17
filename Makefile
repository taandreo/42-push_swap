.PHONY: all clean fclean re log bonus libft

CC = cc
NAME = push_swap
BONUS = checker
LIBFT = ./lib/libft.a
LIBFT_DIR = ./libft
CFLAGS = -Wall -Wextra -Werror
UNAME := $(shell uname)
LIBS := -lft

ifeq ($(UNAME), Darwin)
	CFLAGS = -Wall -Wextra -Werror -arch x86_64
endif

SRCS = index.c stack_0.c stack_1.c utils.c markup.c \
       parse.c moves_0.c moves_1.c solve_b_to_a_0.c \
	   solve_b_to_a_1.c solve_a_to_b.c solve.c prints.c

SRCS_MAIN  = push_swap.c $(SRCS)
SRCS_BONUS = checker.c $(SRCS)

OBJS_MAIN  = $(SRCS_MAIN:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I libft/include -I include -c $< -o $@ 

$(NAME): $(OBJS_MAIN) | libft
	$(CC) $(CFLAGS) $(OBJS_MAIN) -o $(NAME) $(LIBS) -L $(LIBFT_DIR)

bonus: $(OBJS_BONUS) | libft
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(BONUS) $(LIBS) -L $(LIBFT_DIR)

libft:
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS_MAIN) $(OBJS_BONUS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS) $(LIBFT) 
	make fclean -C $(LIBFT_DIR)

re: fclean all

git_libft:
	git clone https://github.com/taandreo/42-libft.git libft
