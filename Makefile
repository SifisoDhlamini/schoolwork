.PHONY: clean All

All:
	@echo "----------Building project:[ question18 - Debug ]----------"
	@cd "question18" && "$(MAKE)" -f  "question18.mk"
clean:
	@echo "----------Cleaning project:[ question18 - Debug ]----------"
	@cd "question18" && "$(MAKE)" -f  "question18.mk" clean
