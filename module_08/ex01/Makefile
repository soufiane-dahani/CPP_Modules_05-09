
CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Span

SRC = main.cpp Span.cpp
OBJ = $(SRC:.cpp=.o)


all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

BRANCH = main
p:
	@read -p "Commit message: " msg; \
	git add . && git commit -m "$$msg" && git push origin $(BRANCH)