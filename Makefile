.PHONY: clean All

All:
	@echo "----------Building project:[ question45 - Debug ]----------"
	@cd "question45" && "$(MAKE)" -f  "question45.mk"
clean:
	@echo "----------Cleaning project:[ question45 - Debug ]----------"
	@cd "question45" && "$(MAKE)" -f  "question45.mk" clean
