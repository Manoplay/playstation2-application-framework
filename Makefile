all:
	@$(MAKE) -r -C src

clean:
	$(MAKE) -C src clean

install:
	$(MAKE) -C src install