.PHONY: clean All

All:
	@echo "----------Building project:[ question26_shampo - Debug ]----------"
	@cd "question26_shampo" && "$(MAKE)" -f  "question26_shampo.mk"
clean:
	@echo "----------Cleaning project:[ question26_shampo - Debug ]----------"
	@cd "question26_shampo" && "$(MAKE)" -f  "question26_shampo.mk" clean
