WD=$(shell pwd)

.PHONY: rpms clean

rpms:
	@rpmbuild --define '_topdir $(WD)' --clean -ba SPECS/app.spec

clean:
	@rm -rf BUILD
	@rm -rf BUILDROOT
	@rm -rf RPMS
	@rm -rf SOURCES
	@rm -rf SRPMS
