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

# Functions
# ==============================

define releaseSphinxDocs
@cp documentation/sphinx/_build_$1/latex/$(NAME).pdf release/$(RELEASE)-$1.pdf
@mkdir -p release/$(RELEASE)-$1-html
@cp -r documentation/sphinx/_build_$1/dirhtml/* release/$(RELEASE)-$1-html/
@cd release/; tar cvzf $(RELEASE)-$1-html.tar.gz $(RELEASE)-$1-html/*
@rm -rf release/$(RELEASE)-$1-html
endef

# Targets
# ==============================
.PHONY: release clean

release: clean
	@mkdir -p release/

	@$(MAKE) -C source/ cppunit-txt dist NAME=$(NAME) MAJOR=$(MAJOR) MINOR=$(MINOR) FIX=$(FIX) LABEL=$(LABEL) BUILD=$(BUILD)
	cp source/cppunit-results.txt release/$(RELEASE)-cppunit-results.txt

	@$(MAKE) -C source/ cppcheck-html dist NAME=$(NAME) MAJOR=$(MAJOR) MINOR=$(MINOR) FIX=$(FIX) LABEL=$(LABEL) BUILD=$(BUILD)
	cp -r source/cppcheck-results-html release/$(RELEASE)-cppcheck-results-html
	@cd release/; tar cvzf $(RELEASE)-cppcheck-results-html.tar.gz $(RELEASE)-cppcheck-results-html/*
	@rm -rf release/$(RELEASE)-cppcheck-results-html

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

	$(call releaseSphinxDocs,api)
	$(call releaseSphinxDocs,manual)
	$(call releaseSphinxDocs,master)
	$(call releaseSphinxDocs,support)
	$(call releaseSphinxDocs,test-report)

	@cp documentation/doxygen/build/latex/refman.pdf release/$(RELEASE)-source-reference.pdf
	@mkdir -p release/$(RELEASE)-source-reference-html
	@cp -r documentation/doxygen/build/html/* release/$(RELEASE)-source-reference-html/
	@cd release/; tar cvzf $(RELEASE)-source-reference-html.tar.gz $(RELEASE)-source-reference-html/*
	@rm -rf release/$(RELEASE)-source-reference-html

	@ls -lh release/

clean:
	@$(MAKE) -C source/ clean
	@$(MAKE) -C rpmbuild/ clean
	@$(MAKE) -C documentation/ clean
	@$(MAKE) -C robot/ clean
	@rm -rf release/
