.PHONY: clean All

All:
	@echo "----------Building project:[ question28 - Debug ]----------"
	@cd "question28" && "$(MAKE)" -f  "question28.mk"
clean:
	@echo "----------Cleaning project:[ question28 - Debug ]----------"
	@cd "question28" && "$(MAKE)" -f  "question28.mk" clean
