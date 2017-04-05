## Generic rules for Makefiles

$(NAME):	$(OBJ)
		@$(ECHO) "$(GREEN) == $(WHITE) Compiling Core  $(GREEN) == $(CLEAR)"
		@$(CXX) $(OBJ) -o $(NAME) $(INC)

all:		$(NAME)

clean:
		@$(ECHO) "$(WHITE) [$(RED)RM$(WHITE)] $(OBJ)$(CLEAR)"
		@$(RM) $(OBJ)

fclean:     	clean
		@$(ECHO) "$(WHITE) [$(RED)RM$(WHITE)] $(NAME)$(CLEAR)"
		@$(RM) $(NAME)

re:		fclean all

.cpp.o:
		@$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@
		@$(ECHO) "$(WHITE) [$(GREEN)OK$(WHITE)] Compiled "$<"\n$(CLEAR)"

.PHONY:		all clean fclean re
