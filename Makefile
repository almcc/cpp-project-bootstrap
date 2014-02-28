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
	@$(MAKE) -C documentation/ docs

	@cp documentation/sphinx/_build/latex/app.pdf release/app-0.1.0-manual.pdf
	@mkdir -p release/app-0.1.0-manual
	@cp -r documentation/sphinx/_build/dirhtml/* release/app-0.1.0-manual/
	@cd release/; tar cvzf app-0.1.0-manual.tar.gz app-0.1.0-manual/*
	@rm -rf release/app-0.1.0-manual

	@cp documentation/doxygen/build/latex/refman.pdf release/app-0.1.0-source-reference.pdf
	@mkdir -p release/app-0.1.0-source-reference
	@cp -r documentation/doxygen/build/html/* release/app-0.1.0-source-reference/
	@cd release/; tar cvzf app-0.1.0-source-reference.tar.gz app-0.1.0-source-reference/*
	@rm -rf release/app-0.1.0-source-reference

clean:
	@$(MAKE) -C source/ clean
	@$(MAKE) -C rpmbuild/ clean
	@$(MAKE) -C documentation/ clean
	@rm -rf release/

