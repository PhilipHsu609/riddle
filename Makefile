# Dispatcher. Each site owns its Makefile/CMakeLists; see <site>/Makefile.
#   make aoc-run DAY=5            make euler-run N=12
#   make ec-add YEAR=2025 QUEST=3 make aoc-add DAY=5 LANGUAGE=rust
SITES := advent-of-code project-euler everybody-codes

.PHONY: all clean rust-project help
help:
	@echo "make {aoc|euler|ec}-{add|run|build|clean} [site variables]"
	@echo "make all | clean | rust-project"

aoc-%:   ; $(MAKE) -C advent-of-code $*
euler-%: ; $(MAKE) -C project-euler $*
ec-%:    ; $(MAKE) -C everybody-codes $*

all clean:
	@for s in $(SITES); do $(MAKE) -C $$s $@ || exit 1; done

bin/generate_rust_project: tools/generate_rust_project.rs
	@mkdir -p bin && rustc $< -o $@

rust-project: bin/generate_rust_project
	@./bin/generate_rust_project
