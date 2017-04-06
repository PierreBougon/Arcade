## Generic rules for Makefiles

$(NAME):	$(OBJ)
		@$(ECHO) "$(BLUE) Flags used \t: $(BOLD_WHITE)$(CXXFLAGS)$(CLEAR)"
		@$(ECHO) "$(BLUE) Dependencies:$(BOLD_WHITE)$(LDFLAGS)$(CLEAR)"
		@$(ECHO) "$(BLUE) == $(BOLD_WHITE) $(PROJECT_NAME)  Compiled $(BLUE) == $(CLEAR)\n"
		@$(CXX) $(OBJ) -o $(NAME) $(INC) $(LDFLAGS)
		@$(eval PROJECT_NAME=)
		@$(eval LDFLAGS=)
		@$(eval DLL=NO)
		@$(eval CXXFLAGS= -std=c++14 -W -Wall -Wextra)

all:		$(NAME)

clean:
		@$(ECHO) "$(BOLD_WHITE) [$(RED)RM$(BOLD_WHITE)] $(OBJ)$(CLEAR)"
		@$(RM) $(OBJ)

fclean:     	clean
		@$(ECHO) "$(BOLD_WHITE) [$(RED)RM$(BOLD_WHITE)] $(NAME)$(CLEAR)\n"
		@$(RM) $(NAME)

re:		fclean all

.cpp.o:
		@$(CXX) $(CXXFLAGS) $(INC) $(LDFLAGS) -c $< -o $@
		@$(ECHO) "$(BOLD_WHITE) [$(GREEN)OK$(BOLD_WHITE)] Compiled "$<"$(CLEAR)"

.PHONY:		all clean fclean re
