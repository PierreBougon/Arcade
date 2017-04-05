## Generic rules for Makefiles

$(NAME):	$(OBJ)
		@$(ECHO) "$(BLUE) Flags used \t: $(BOLD_WHITE)$(CXXFLAGS)$(CLEAR)"
		@$(ECHO) "$(BLUE) Dependencies:$(BOLD_WHITE)$(LDFLAGS)$(CLEAR)"
		@$(ECHO) "$(BLUE) == $(BOLD_WHITE) $(PROJECT_NAME)  Compiled $(BLUE) == $(CLEAR)\n"
		@$(CXX) $(OBJ) -o $(NAME) $(INC) $(LDFLAGS)

all:		$(NAME)

clean:
		@$(ECHO) "$(BOLD_WHITE) [$(RED)RM$(BOLD_WHITE)] $(OBJ)$(CLEAR)"
		@$(RM) $(OBJ)

fclean:     	clean
		@$(ECHO) "$(BOLD_WHITE) [$(RED)RM$(BOLD_WHITE)] $(NAME)$(CLEAR)"
		@$(RM) $(NAME)

re:		fclean all

.cpp.o:
		$(CXX) $(INC) $(LDFLAGS) -c $< -o $@
		@$(ECHO) "$(BOLD_WHITE) [$(GREEN)OK$(BOLD_WHITE)] Compiled "$<"\n$(CLEAR)"

.PHONY:		all clean fclean re
