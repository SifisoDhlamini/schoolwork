.PHONY: clean All

All:
	@echo "----------Building project:[ question19 - Debug ]----------"
	@cd "question19" && "$(MAKE)" -f  "question19.mk"
clean:
	@echo "----------Cleaning project:[ question19 - Debug ]----------"
	@cd "question19" && "$(MAKE)" -f  "question19.mk" clean
