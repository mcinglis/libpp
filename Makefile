
limit          = 128
templates_dir  = templates
render	       = $(templates_dir)/render.py

templates      = $(wildcard $(templates_dir)/*.h)
output         = $(notdir $(templates))

.PHONY: all
all: $(output)

$(output): %.h: $(templates_dir)/%.h
	$(render) "$(limit)" "$<" > "$@"

.PHONY: test
test:
	tests/run.bash

.PHONY: clean
clean:
	rm -f $(output)

