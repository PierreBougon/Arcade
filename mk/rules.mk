## Generic rules for Makefiles

$(NAME):	$(OBJ)
		@$(ECHO) "\n$(BLUE) Compiled with : $(BOLD_WHITE)$(CXX)$(CLEAR)"
		@$(ECHO) "$(BLUE) Flags used \t  : $(BOLD_WHITE)$(CXXFLAGS)$(CLEAR)"
		@$(ECHO) "$(BLUE) Dependencies  :$(BOLD_WHITE)$(LDFLAGS)$(CLEAR)"
		@$(ECHO) "$(BLUE) == $(BOLD_WHITE) $(PROJECT_NAME)  Compiled $(BLUE) == $(CLEAR)\n\n"
		@$(CXX) $(OBJ) -o $(NAME) $(INC) $(LDFLAGS)
		@$(eval PROJECT_NAME=)
		@$(eval LDFLAGS=)
		@$(eval DLL=NO)
		@$(eval CXXFLAGS= -std=c++14 -W -Wall -Wextra)

all:		$(NAME)

clean:
		@$(ECHO) "$(BOLD_WHITE) [$(RED)RM$(BOLD_WHITE)] $(NAME) Obejcts files$(CLEAR)"
		@$(RM) $(OBJ)

fclean:     	clean
		@$(ECHO) "$(BOLD_WHITE) [$(RED)RM$(BOLD_WHITE)] $(NAME) Binary file$(CLEAR)\n"
		@$(RM) $(NAME)

re:		fclean all

.cpp.o:
#ifeq ($(STATIC), YES)
		@$(CXX) $(CXXFLAGS) $(INC) $(LDFLAGS) -c $< -o $@
		@$(ECHO) "$(BOLD_WHITE) [$(GREEN)OK$(BOLD_WHITE)] Compiled "$<"$(CLEAR)"
#endif
.PHONY:		all clean fclean re
