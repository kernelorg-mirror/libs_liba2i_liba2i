# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_DEV_INCLUDED
MAKEFILE_BUILD_DEV_INCLUDED := 1


include $(MAKEFILEDIR)/build.mk
include $(MAKEFILEDIR)/build-dev.mk
include $(MAKEFILEDIR)/build-obj.mk
include $(MAKEFILEDIR)/cmd.mk
include $(MAKEFILEDIR)/src.mk
include $(MAKEFILEDIR)/version.mk


DEFAULT_ARFLAGS := qcsDP
EXTRA_ARFLAGS   :=
ARFLAGS         := $(DEFAULT_ARFLAGS) $(EXTRA_ARFLAGS)


AR := gcc-ar


_LIB_a    := $(builddir)/$(libname).a
_LIB_pc   := $(builddir)/$(libname).pc


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

$(_LIB_pc_u): $(LIB_pc_u) $(MK) | $$(@D)/
	$(CP) -T $< $@

$(_LIB_pc): $(_LIB_pc_u) $(MK) | $$(@D)/
	$(info	SED		$@)
	$(SED) 's/Version:.*/Version: $(DISTVERSION)/' <$< >$@
	$(SED) -i 's,prefix=.*,prefix=$(prefix),' $@
ifneq ($(filter includedir=%,$(MAKEOVERRIDES)),)
	$(SED) -i 's,includedir=.*,includedir=$(includedir),' $@
endif
ifneq ($(filter libdir=%,$(MAKEOVERRIDES)),)
	$(SED) -i 's,libdir=.*,libdir=$(libdir),' $@
endif


.PHONY: build-dev-ar
build-dev-ar: $(_LIB_a)
	@:

.PHONY: build-dev-pc
build-dev-pc: $(_LIB_pc)
	@:


.PHONY: build-dev
build-dev: build-dev-ar build-dev-pc
	@:


endif  # include guard
