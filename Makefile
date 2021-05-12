.PHONY: clean All

All:
	@echo "----------Building project:[ question36 - Debug ]----------"
	@cd "question36" && "$(MAKE)" -f  "question36.mk"
clean:
	@echo "----------Cleaning project:[ question36 - Debug ]----------"
	@cd "question36" && "$(MAKE)" -f  "question36.mk" clean
