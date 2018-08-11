.PHONY: clean All

All:
	@echo "----------Building project:[ lost-dungeon - Release ]----------"
	@"$(MAKE)" -f  "lost-dungeon.mk" && "$(MAKE)" -f  "lost-dungeon.mk" PostBuild
clean:
	@echo "----------Cleaning project:[ lost-dungeon - Release ]----------"
	@"$(MAKE)" -f  "lost-dungeon.mk" clean
