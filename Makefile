.PHONY: clean All

All:
	@echo "----------Building project:[ week1_question6 - Debug ]----------"
	@cd "week1_question6" && "$(MAKE)" -f  "week1_question6.mk"
clean:
	@echo "----------Cleaning project:[ week1_question6 - Debug ]----------"
	@cd "week1_question6" && "$(MAKE)" -f  "week1_question6.mk" clean
