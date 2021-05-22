.PHONY: clean All

All:
	@echo "----------Building project:[ question38 - Debug ]----------"
	@cd "question38" && "$(MAKE)" -f  "question38.mk"
clean:
	@echo "----------Cleaning project:[ question38 - Debug ]----------"
	@cd "question38" && "$(MAKE)" -f  "question38.mk" clean
