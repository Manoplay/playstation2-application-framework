SUBDIRS = framework samples

all: $(patsubst %, _dir_%, $(SUBDIRS)) 

$(patsubst %, _dir_%, $(SUBDIRS)):
	@$(MAKE) -r -C $(patsubst _dir_%, %, $@)

clean: $(patsubst %, _cleandir_%, $(SUBDIRS))

$(patsubst %, _cleandir_%, $(SUBDIRS)):
	$(MAKE) -C $(patsubst _cleandir_%, %, $@) clean

install: framework
	$(MAKE) -C framework install