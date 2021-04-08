.PHONY: clean All

All:
	@echo "----------Building project:[ question21 - Debug ]----------"
	@cd "question21" && "$(MAKE)" -f  "question21.mk"
clean:
	@echo "----------Cleaning project:[ question21 - Debug ]----------"
	@cd "question21" && "$(MAKE)" -f  "question21.mk" clean
