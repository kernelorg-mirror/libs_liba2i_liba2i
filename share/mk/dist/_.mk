# Copyright 2021-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_DIST_INCLUDED
MAKEFILE_DIST_INCLUDED := 1


include $(MAKEFILEDIR)/install/_.mk


_DISTDIR := $(builddir)/dist


$(builddir)/dist/:
	+$(info INSTALL	$@)
	+$(INSTALL_DIR) $@

$(builddir)/dist/%/: | $(builddir)/dist/
	+$(info INSTALL	$@)
	+$(INSTALL_DIR) $@


.PHONY: dist
dist: dist-tar dist-z


endif  # include guard
