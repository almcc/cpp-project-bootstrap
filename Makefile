WD=$(shell pwd)

.PHONY: release clean

release: clean
	@$(MAKE) -C source/ dist
	@mkdir -p rpmbuild/SOURCES/
	@cp source/dist/* rpmbuild/SOURCES/
	@$(MAKE) -C rpmbuild/ rpms
	@mkdir -p release/
	@cp source/dist/* release/
	@cp source/dist/* release/
	@cp rpmbuild/RPMS/*/* release/
	@cp rpmbuild/SRPMS/* release/


clean:
	@$(MAKE) -C source/ clean
	@$(MAKE) -C rpmbuild/ clean
	@rm -rf release/

