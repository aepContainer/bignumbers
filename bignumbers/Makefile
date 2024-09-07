NAME = bn
AR_NAME = bn.a
CFLAGS = -Wall -Wextra -Werror# -g

LIBFT_PATH = ../libft/
LIBFT_FLAGS = -L $(LIBFT_PATH) -lft
LIBFT_OBJS = $(LIBFT_PATH)*.o $(LIBFT_PATH)*/*.o
LIBFT = $(LIBFT_PATH)libft.a

HLP = helpers/
HELPERS_SRCS = $(HLP)bn_calc.c $(HLP)bn_decide_sign.c $(HLP)bn_get_perfect_number.c \
$(HLP)bn_insert.c $(HLP)bn_isnum_arg.c $(HLP)bn_isnum.c $(HLP)bn_max.c $(HLP)bn_min.c \
$(HLP)bn_substract_helpers.c $(HLP)bn_power_helpers.c $(HLP)bn_set_length_same.c $(HLP)bn_to_neg.c \
$(HLP)bn_is_same.c $(HLP)bn_is_greater.c $(HLP)bn_is_smaller.c $(HLP)bn_multiply_helpers.c \
$(HLP)bn_divide_helpers_1.c $(HLP)bn_divide_helpers_2.c

SRCS = bn_abstract.c bn_add.c bn_factorialize.c bn_modulate.c \
bn_power.c bn_substract.c bn_multiply.c bn_divide.c $(HELPERS_SRCS)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(AR_NAME)
	cc $(CFLAGS) $(LIBFT_FLAGS) bn_test.c $(AR_NAME) -o test

$(AR_NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	ar rcs $(AR_NAME) *.o $(HLP)*.o $(LIBFT_OBJS)

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME) $(AR_NAME)

re: fclean all

.PHONY: all clean fclean re
