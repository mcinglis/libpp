
PYTHON ?= python

# The maximum number of arguments that the macros can take:
LIBPP_LIMIT ?= 128

templates = $(wildcard templates/*.h)
output    = $(notdir $(templates))


.PHONY: all
all: $(output)

$(output): %.h: templates/%.h
	$(PYTHON) templates/render.py $(LIBPP_LIMIT) "$<" -o "$@"


.PHONY: test
test: all
	tests/run.bash


.PHONY: clean
clean:
	rm -f $(output)

