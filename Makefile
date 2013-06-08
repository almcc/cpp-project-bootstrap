WD=$(shell pwd)

.PHONY: release clean

release: 
	@mkdir -p rpmbuild/SOURCES/
	@tar cvf rpmbuild/SOURCES/cpp.tar cpp
	@rpmbuild --define '_topdir $(WD)/rpmbuild' --clean -ba rpmbuild/SPECS/package.spec
	@rm rpmbuild/SOURCES/cpp.tar
	@mkdir -p archive/RPMS/
	@mkdir -p archive/SRPMS/
	@cp -r rpmbuild/RPMS/* archive/RPMS/
	@cp rpmbuild/SRPMS/* archive/SRPMS/

clean:
	@$(MAKE) -C cpp/ clean
	@rm -rf rpmbuild/RPMS/*
	@rm -rf rpmbuild/SRPMS/*
