NAME = libftprintf.a
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft

SRCS =	ft_printf.c ft_util.c ft_printer.c

OBJS =	$(SRCS:.c=.o)

all: $(NAME)

makelibft:
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)	

$(NAME): makelibft $(OBJS)
	@ar -r $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
	@cd $(LIBFT_DIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFT_DIR) && make fclean

re: fclean all

.PHONY: all clean fclean re
