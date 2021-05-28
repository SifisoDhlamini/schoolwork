.PHONY: clean All

All:
	@echo "----------Building project:[ question40 - Debug ]----------"
	@cd "question40" && "$(MAKE)" -f  "question40.mk"
clean:
	@echo "----------Cleaning project:[ question40 - Debug ]----------"
	@cd "question40" && "$(MAKE)" -f  "question40.mk" clean
