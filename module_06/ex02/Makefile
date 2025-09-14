
CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Identify

SRC = main.cpp Base.cpp Identify.cpp
OBJ = $(SRC:.cpp=.o)

BRANCH = main

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


p:
	@read -p "Commit message: " msg; \
	git add . && git commit -m "$$msg" && git push origin $(BRANCH)

