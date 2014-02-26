.PHONY: docs doxygen sphinx clean

docs: clean doxygen sphinx

doxygen:
	cd doxygen; doxygen
	@$(MAKE) -C doxygen/build/latex all

sphinx:
	@$(MAKE) -C sphinx/ clean html dirhtml latexpdf

clean:
	@rm -rf doxygen/build
	@rm -rf sphinx/_build


