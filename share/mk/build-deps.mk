# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_DEPS_INCLUDED
MAKEFILE_BUILD_DEPS_INCLUDED := 1


include $(MAKEFILEDIR)/build.mk
include $(MAKEFILEDIR)/cmd.mk
include $(MAKEFILEDIR)/src.mk
include $(MAKEFILEDIR)/verbose.mk
include $(MAKEFILEDIR)/version.mk


PKGCONF_ENV          := PKG_CONFIG_PATH=$(PCDIR)
DEFAULT_PKGCONFFLAGS :=
EXTRA_PKGCONFFLAGS   :=
PKGCONFFLAGS         := $(DEFAULT_PKGCONFFLAGS) $(EXTRA_PKGCONFFLAGS)
PKGCONF              := pkgconf
PKGCONF_CMD          := $(PKGCONF_ENV) $(PKGCONF) $(PKGCONFFLAGS)


pc_lib    := $(libname)-uninstalled
LIB_pc_u  := $(PCDIR)/$(pc_lib).pc
_LIB_pc_u := $(builddir)/$(pc_lib).pc
pc_reqs   := $(shell $(PKGCONF_CMD) --print-requires-private $(pc_lib)) $(pc_lib)


DEFAULT_CPPFLAGS := $(shell $(PKGCONF_CMD) --cflags $(pc_lib))
DEFAULT_CPPFLAGS += -I$(builddir)
EXTRA_CPPFLAGS   :=
CPPFLAGS         := $(DEFAULT_CPPFLAGS) $(EXTRA_CPPFLAGS)

DEFAULT_CFLAGS := -O3
DEFAULT_CFLAGS += -std=gnu11
DEFAULT_CFLAGS += -flto
DEFAULT_CFLAGS += -Wall
DEFAULT_CFLAGS += -Wextra
DEFAULT_CFLAGS += -Wstrict-prototypes
DEFAULT_CFLAGS += -Wdeclaration-after-statement
DEFAULT_CFLAGS += -Wno-attributes
DEFAULT_CFLAGS += -Wno-nullability-completeness
DEFAULT_CFLAGS += -Wno-unknown-attributes
DEFAULT_CFLAGS += -Wno-unknown-pragmas
DEFAULT_CFLAGS += -Wno-unused-command-line-argument
EXTRA_CFLAGS   :=
export CFLAGS  := $(DEFAULT_CFLAGS) $(EXTRA_CFLAGS)


CC   := gcc


_TU_h := $(patsubst $(srcdir)/include/%,$(builddir)/%,$(TU_h))
_TU_c := $(patsubst $(srcdir)/src/%,$(builddir)/%,$(TU_c))

_TU_h_d   := $(addsuffix .d,$(_TU_h))
_TU_c_d   := $(addsuffix .d,$(_TU_c))


DEPTARGETS  = -MT $*.lint-c.checkpatch.touch \
              -MT $*.lint-c.clang-tidy.touch \
              -MT $*.lint-c.cppcheck.touch \
              -MT $*.lint-c.cpplint.touch \
              -MT $*.lint-c.iwyu.touch
DEPHTARGETS = $(DEPTARGETS) -MT $*.gch
DEPCTARGETS = $(DEPTARGETS) -MT $*.i


$(_TU_h): $(builddir)/%: $(srcdir)/include/% $(MK) | $$(@D)/
	$(CP) -T $< $@

$(_TU_c): $(builddir)/%: $(srcdir)/src/% $(MK) | $$(@D)/
	$(CP) -T $< $@

$(_TU_h_d): %.d: % $(_TU_h) $(MK) $(_LIB_pc_u) | $$(@D)/
	$(CC) $(CPPFLAGS) $(CFLAGS) -M -MP $(DEPHTARGETS) -MF$@ $<

$(_TU_c_d): %.d: % $(_TU_h) $(_TU_c) $(MK) $(_LIB_pc_u) | $$(@D)/
	$(CC) $(CPPFLAGS) $(CFLAGS) -M -MP $(DEPCTARGETS) -MF$@ $<


.PHONY: build-deps
build-deps: $(_TU_h_d) $(_TU_c_d)
	@:


endif  # include guard
