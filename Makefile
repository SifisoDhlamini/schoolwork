.PHONY: clean All

All:
	@echo "----------Building project:[ question33 - Debug ]----------"
	@cd "question33" && "$(MAKE)" -f  "question33.mk"
clean:
	@echo "----------Cleaning project:[ question33 - Debug ]----------"
	@cd "question33" && "$(MAKE)" -f  "question33.mk" clean
