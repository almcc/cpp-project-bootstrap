# Release Settings
# ==============================
NAME = app
MAJOR = 0
MINOR = 1
FIX = 0
LABEL = dev
BUILD = 1
VERSION = $(MAJOR).$(MINOR).$(FIX)
RELEASE = $(NAME)-$(VERSION)-$(LABEL)$(BUILD)

# Helpers
# ==============================
WD=$(shell pwd)

# Targets
# ==============================
.PHONY: release clean

release: clean
	@mkdir -p release/

	@$(MAKE) -C source/ ci-txt dist NAME=$(NAME) MAJOR=$(MAJOR) MINOR=$(MINOR) FIX=$(FIX) LABEL=$(LABEL) BUILD=$(BUILD)
	cp source/cppunit-results.txt release/$(RELEASE)-cppunit-results.txt
	cp source/cppcheck-results.txt release/$(RELEASE)-check-results.txt

	@$(MAKE) -C robot/ robot NAME=$(NAME) MAJOR=$(MAJOR) MINOR=$(MINOR) FIX=$(FIX) LABEL=$(LABEL) BUILD=$(BUILD)
	@cp robot/$(RELEASE)-robot-report.html release/$(RELEASE)-robot-report.html
	@cp robot/$(RELEASE)-robot-log.html release/$(RELEASE)-robot-log.html

	@$(MAKE) -C source/ dist NAME=$(NAME) MAJOR=$(MAJOR) MINOR=$(MINOR) FIX=$(FIX) LABEL=$(LABEL) BUILD=$(BUILD)
	@mkdir -p rpmbuild/SOURCES/
	@cp source/dist/* release/

	@cp source/dist/* rpmbuild/SOURCES/
	@$(MAKE) -C rpmbuild/ rpms NAME=$(NAME) MAJOR=$(MAJOR) MINOR=$(MINOR) FIX=$(FIX) LABEL=$(LABEL) BUILD=$(BUILD)
	@cp rpmbuild/RPMS/*/* release/
	@cp rpmbuild/SRPMS/* release/

	@$(MAKE) -C documentation/ docs NAME=$(NAME) MAJOR=$(MAJOR) MINOR=$(MINOR) FIX=$(FIX) LABEL=$(LABEL) BUILD=$(BUILD)

	@cp documentation/sphinx/_build/latex/$(NAME).pdf release/$(RELEASE)-manual.pdf
	@mkdir -p release/$(RELEASE)-manual
	@cp -r documentation/sphinx/_build/dirhtml/* release/$(RELEASE)-manual/
	@cd release/; tar cvzf $(RELEASE)-manual.tar.gz $(RELEASE)-manual/*
	@rm -rf release/$(RELEASE)-manual

	@cp documentation/doxygen/build/latex/refman.pdf release/$(RELEASE)-source-reference.pdf
	@mkdir -p release/$(RELEASE)-source-reference
	@cp -r documentation/doxygen/build/html/* release/$(RELEASE)-source-reference/
	@cd release/; tar cvzf $(RELEASE)-source-reference.tar.gz $(RELEASE)-source-reference/*
	@rm -rf release/$(RELEASE)-source-reference

	@ls -lh release/

clean:
	@$(MAKE) -C source/ clean
	@$(MAKE) -C rpmbuild/ clean
	@$(MAKE) -C documentation/ clean
	@$(MAKE) -C robot/ clean
	@rm -rf release/
