NAME		= libftprintf.a

CC			= cc

FLAGS		= -Wall -Wextra -Werror

SRC			= ft_printf.c \
			  myputchar.c \
			  myputhex.c \
			  myputnbr.c \
			  myputstr.c \

OBJ			= $(SRC:%.c=%.o)

HEADER		= ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@echo "👌 Done"

%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) -c $< 
	@echo "🛠️ Creating Objects!!"

clean:
	@rm -f $(OBJ)
	@echo  "🧨 Deleting OBJS."

fclean: clean
	@rm -f  $(NAME)
	@echo  "💣 Destroy all"

re: fclean all

.PHONY: clean 