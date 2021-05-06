.PHONY: clean All

All:
	@echo "----------Building project:[ question32 - Debug ]----------"
	@cd "question32" && "$(MAKE)" -f  "question32.mk"
clean:
	@echo "----------Cleaning project:[ question32 - Debug ]----------"
	@cd "question32" && "$(MAKE)" -f  "question32.mk" clean
