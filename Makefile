BUILD_DIR = build

.DEFAULT:
	@TARGET=$$(echo "$@" | sed 's/\.cpp$$//'); \
	FILE=$$(find . -name "$$TARGET*.cpp" -not -path "./$(BUILD_DIR)/*" | head -1); \
	if [ -z "$$FILE" ]; then echo "Error: $$TARGET.cpp not found"; exit 1; fi; \
	g++ -o $(BUILD_DIR)/$$TARGET $$FILE && ./$(BUILD_DIR)/$$TARGET
