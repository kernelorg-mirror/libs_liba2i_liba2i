# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_LIB_STATIC_INCLUDED
MAKEFILE_BUILD_LIB_STATIC_INCLUDED := 1


include $(MAKEFILEDIR)/build/_.mk
include $(MAKEFILEDIR)/build/obj.mk
include $(MAKEFILEDIR)/cmd.mk
include $(MAKEFILEDIR)/configure/ar.mk
include $(MAKEFILEDIR)/version.mk


_LIB_a := $(builddir)/$(libname).a


$(_LIB_a): %.a: $(_TU_o) $(MK) | $$(@D)/
	$(info	AR		$@)
	$(CD) $(dir $@) && \
	for opt in g 0 1 2 s 3 fast; do \
		$(RM) $(notdir $*.O$$opt.a) 2>/dev/null ||:; \
		$(ECHO) $(patsubst $(builddir)/%,%,$(_TU_o)) \
		| $(SED) "s,.o\>,.O$$opt.o," \
		| $(XARGS) $(AR) $(ARFLAGS) $(notdir $*).O$$opt.a; \
	done
	$(RM) $@ 2>/dev/null ||:
	$(CD) $(dir $@)/ && \
	$(ECHO) $(patsubst $(builddir)/%,%,$(_TU_o)) \
	| $(XARGS) $(AR) $(ARFLAGS) $(notdir $@)


.PHONY: build-lib-static
build-lib-static: $(_LIB_a)
	@:


endif  # include guard
