.PHONY: clean All

All:
	@echo "----------Building project:[ question15 - Debug ]----------"
	@cd "question15" && "$(MAKE)" -f  "question15.mk"
clean:
	@echo "----------Cleaning project:[ question15 - Debug ]----------"
	@cd "question15" && "$(MAKE)" -f  "question15.mk" clean
