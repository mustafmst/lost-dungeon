.PHONY: clean All

All:
	@echo "----------Building project:[ lost-dungeon - Debug ]----------"
	@"$(MAKE)" -f  "lost-dungeon.mk"
clean:
	@echo "----------Cleaning project:[ lost-dungeon - Debug ]----------"
	@"$(MAKE)" -f  "lost-dungeon.mk" clean
