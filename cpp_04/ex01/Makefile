NAME = animal

SRCS = Animal.cpp Cat.cpp Dog.cpp main.cpp WrongCat.cpp WrongAnimal.cpp Brain.cpp

RM = rm -rf

FLAGS = --std=c++98 -Wall -Wextra -Werror

OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

all		: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) -g -fsanitize=address $(FLAGS) $(OBJS) -o $(NAME)


clean :
	$(RM) $(OBJS)

fclean	:
	$(RM) $(OBJS)
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re