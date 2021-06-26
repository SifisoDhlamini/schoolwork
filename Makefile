.PHONY: clean All

All:
	@echo "----------Building project:[ question47 - Debug ]----------"
	@cd "question47" && "$(MAKE)" -f  "question47.mk"
clean:
	@echo "----------Cleaning project:[ question47 - Debug ]----------"
	@cd "question47" && "$(MAKE)" -f  "question47.mk" clean
