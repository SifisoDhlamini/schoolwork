.PHONY: clean All

All:
	@echo "----------Building project:[ question39 - Debug ]----------"
	@cd "question39" && "$(MAKE)" -f  "question39.mk"
clean:
	@echo "----------Cleaning project:[ question39 - Debug ]----------"
	@cd "question39" && "$(MAKE)" -f  "question39.mk" clean
