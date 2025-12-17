PROBLEMS := apple_division \
	creating_strings \
	gen_all_subsets \
	eight_queens \
	milk_pails \
	cow_gymnastics \
	bovine_genomics

all: all_problems

.PHONY: all_problems
all_problems: $(PROBLEMS)

.PHONY: $(PROBLEMS)
$(PROBLEMS):
	$(MAKE) -C $@ sol

.PHONY: clean
clean:
	for dir in $(PROBLEMS); do \
		$(MAKE) -C $$dir clean; \
	done
