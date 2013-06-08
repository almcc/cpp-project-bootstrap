WD=$(shell pwd)

.PHONY: release

release:
	$(MAKE) -C cpp/ clean
	tar cvf rpmbuild/SOURCES/cpp.tar cpp
	rpmbuild --define '_topdir $(WD)/rpmbuild' --clean -ba rpmbuild/SPECS/package.spec
	rm rpmbuild/SOURCES/cpp.tar

