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
.PHONY: rpms clean

rpms:
	@rpmbuild --define '_topdir $(WD)' --clean -ba SPECS/app.spec  --define 'version $(VERSION)' \
	                                                               --define 'name $(NAME)' \
	                                                               --define 'release_label $(LABEL)$(BUILD)'

clean:
	@rm -rf BUILD
	@rm -rf BUILDROOT
	@rm -rf RPMS
	@rm -rf SOURCES
	@rm -rf SRPMS
