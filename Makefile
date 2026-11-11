NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

PRINTF_DIR  = ft_printf
PRINTF      = $(PRINTF_DIR)/libftprintf.a

HEADERS     = push_swap.h $(PRINTF_DIR)/ft_printf.h $(PRINTF_DIR)/libft/libft.h

SRCS        = push_swap.c
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re