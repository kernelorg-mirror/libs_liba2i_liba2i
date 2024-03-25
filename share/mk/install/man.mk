# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_INSTALL_MAN_INCLUDED
MAKEFILE_INSTALL_MAN_INCLUDED := 1


include $(MAKEFILEDIR)/configure/build-depends/bzip2/bzip2.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils/install.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils/ln.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils/test.mk
include $(MAKEFILEDIR)/configure/build-depends/findutils/xargs.mk
include $(MAKEFILEDIR)/configure/build-depends/grep/grep.mk
include $(MAKEFILEDIR)/configure/build-depends/gzip/gzip.mk
include $(MAKEFILEDIR)/configure/build-depends/lzip/lzip.mk
include $(MAKEFILEDIR)/configure/build-depends/moreutils/sponge.mk
include $(MAKEFILEDIR)/configure/build-depends/sed/sed.mk
include $(MAKEFILEDIR)/configure/build-depends/xz-utils/xz.mk
include $(MAKEFILEDIR)/configure/directory_variables/install.mk
include $(MAKEFILEDIR)/configure/directory_variables/src.mk
include $(MAKEFILEDIR)/configure/man/link_pages.mk
include $(MAKEFILEDIR)/configure/man/z.mk
include $(MAKEFILEDIR)/install/_.mk
include $(MAKEFILEDIR)/src/man.mk


_mandir := $(DESTDIR)$(mandir)
$(foreach s, $(MANSECTIONS),                                                  \
	$(eval _man$(s)dir := $(DESTDIR)$(man$(s)dir)))

$(foreach s, $(MANSECTIONS),                                                  \
	$(eval _man$(s)pages :=                                               \
		$(patsubst $(MAN$(s)DIR)/%.$(s), $(_man$(s)dir)/%$(man$(s)ext)$(Z), \
			$(MAN$(s)PAGES))))
_manpages := $(foreach s, $(MANSECTIONS), $(_man$(s)pages))

$(foreach s, $(MANSECTIONS),                                                  \
	$(eval _man$(s)pages_rm :=                                            \
		$(addsuffix -rm,                                              \
			$(wildcard $(_man$(s)pages)))))


$(foreach s, $(MANSECTIONS),                                                  \
	$(eval $(_man$(s)pages):                                              \
		$(_man$(s)dir)/%$(man$(s)ext)$(Z):                            \
			$(_MANDIR)/man$(s)/%.$(s) $(MK) | $$$$(@D)/))


$(_manpages):
	$(info	$(INFO_)INSTALL		$@)
	<$< \
	$(SED) $(foreach s, $(MANSECTIONS), \
		-e '/^\.so /s, man$(s)/\(.*\)\.$(s)$$, $(notdir $(man$(s)dir))/\1$(man$(s)ext)$(Z),') \
	| $(INSTALL_DATA) -T /dev/stdin $@
ifeq ($(LINK_PAGES),symlink)
	if $(GREP) '^\.so ' <$@ >/dev/null; then \
		$(GREP) '^\.so ' <$@ \
		| $(SED) 's,^\.so \(.*\),../\1,' \
		| $(XARGS) -I tgt $(LN) -fsT tgt $@; \
	fi
endif
ifeq ($(Z),.bz2)
	if ! $(TEST) -L $@; then \
		$(BZIP2) $(BZIP2FLAGS) <$@ \
		| $(SPONGE) $@; \
	fi
else ifeq ($(Z),.gz)
	if ! $(TEST) -L $@; then \
		$(GZIP) $(GZIPFLAGS) <$@ \
		| $(SPONGE) $@; \
	fi
else ifeq ($(Z),.lz)
	if ! $(TEST) -L $@; then \
		$(LZIP) $(LZIPFLAGS) <$@ \
		| $(SPONGE) $@; \
	fi
else ifeq ($(Z),.xz)
	if ! $(TEST) -L $@; then \
		$(XZ) $(XZFLAGS) <$@ \
		| $(SPONGE) $@; \
	fi
endif


$(foreach s, $(MANSECTIONS),                                                  \
	$(eval .PHONY: install-man$(s)))
$(foreach s, $(MANSECTIONS),                                                  \
	$(eval install-man$(s): $(_man$(s)pages);))
.PHONY: install-man
install-man: $(foreach s, $(MANSECTIONS), install-man$(s));

$(foreach s, $(MANSECTIONS),                                                  \
	$(eval .PHONY: uninstall-man$(s)))
$(foreach s, $(MANSECTIONS),                                                  \
	$(eval uninstall-man$(s): $(_man$(s)pages_rm);))
.PHONY: uninstall-man
uninstall-man: $(foreach s, $(MANSECTIONS), uninstall-man$(s));


endif  # include guard
