# Release Settings
# ==============================
NAME = app
MAJOR = X
MINOR = X
FIX = X
LABEL = dev
BUILD = X
VERSION = $(MAJOR).$(MINOR).$(FIX)
RELEASE = $(NAME)-$(VERSION)-$(LABEL)$(BUILD)

# Helpers
# ==============================
WD=$(shell pwd)

# Targets
# ==============================
.PHONY: robot clean

robot: clean
	pybot -M Release:$(RELEASE) -r $(RELEASE)-robot-report.html -l $(RELEASE)-robot-log.html tests/

clean:
	@rm -f output.xml
	@rm -f *log.html
	@rm -f *report.html