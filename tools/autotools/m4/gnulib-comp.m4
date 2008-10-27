# DO NOT EDIT! GENERATED AUTOMATICALLY!
# Copyright (C) 2002-2008 Free Software Foundation, Inc.
#
# This file is free software, distributed under the terms of the GNU
# General Public License.  As a special exception to the GNU General
# Public License, this file may be distributed as part of a program
# that contains a configuration script generated by Autoconf, under
# the same distribution terms as the rest of that program.
#
# Generated by gnulib-tool.
#
# This file represents the compiled summary of the specification in
# gnulib-cache.m4. It lists the computed macro invocations that need
# to be invoked from configure.ac.
# In projects using CVS, this file can be treated like other built files.


# This macro should be invoked from ./configure.ac, in the section
# "Checks for programs", right after AC_PROG_CC, and certainly before
# any checks for libraries, header files, types and library functions.
AC_DEFUN([GNULIB_EARLY],
[
  m4_pattern_forbid([^gl_[A-Z]])dnl the gnulib macro namespace
  m4_pattern_allow([^gl_ES$])dnl a valid locale name
  m4_pattern_allow([^gl_LIBOBJS$])dnl a variable
  m4_pattern_allow([^gl_LTLIBOBJS$])dnl a variable
  AC_REQUIRE([AC_PROG_RANLIB])
  AC_REQUIRE([gl_USE_SYSTEM_EXTENSIONS])
])

# This macro should be invoked from ./configure.ac, in the section
# "Check for header files, types and library functions".
AC_DEFUN([GNULIB_INIT],
[
  AM_CONDITIONAL([GL_COND_LIBTOOL], [false])
  gl_cond_libtool=false
  gl_libdeps=
  gl_ltlibdeps=
  m4_pushdef([AC_LIBOBJ], m4_defn([GNULIB_LIBOBJ]))
  m4_pushdef([AC_REPLACE_FUNCS], m4_defn([GNULIB_REPLACE_FUNCS]))
  m4_pushdef([AC_LIBSOURCES], m4_defn([GNULIB_LIBSOURCES]))
  m4_pushdef([GNULIB_LIBSOURCES_LIST], [])
  m4_pushdef([GNULIB_LIBSOURCES_DIR], [])
  gl_COMMON
  gl_source_base='./src/gnulib'
  gl_FUNC_ALLOCA
  gl_GETOPT
  AC_SUBST([LIBINTL])
  AC_SUBST([LTLIBINTL])
  gl_LOCALCHARSET
  LOCALCHARSET_TESTS_ENVIRONMENT="CHARSETALIASDIR=\"\$(top_builddir)/$gl_source_base\""
  AC_SUBST([LOCALCHARSET_TESTS_ENVIRONMENT])
  AC_FUNC_MALLOC
  AC_DEFINE([GNULIB_MALLOC_GNU], 1, [Define to indicate the 'malloc' module.])
  gl_FUNC_MALLOC_POSIX
  gl_STDLIB_MODULE_INDICATOR([malloc-posix])
  gl_REGEX
  gt_TYPE_SSIZE_T
  AM_STDBOOL_H
  gl_STDINT_H
  gl_STDLIB_H
  gl_HEADER_SYS_STAT_H
  AC_PROG_MKDIR_P
  gl_UNISTD_H
  gl_WCHAR_H
  gl_WCTYPE_H
  m4_ifval(GNULIB_LIBSOURCES_LIST, [
    m4_syscmd([test ! -d ]m4_defn([GNULIB_LIBSOURCES_DIR])[ ||
      for gl_file in ]GNULIB_LIBSOURCES_LIST[ ; do
        if test ! -r ]m4_defn([GNULIB_LIBSOURCES_DIR])[/$gl_file ; then
          echo "missing file ]m4_defn([GNULIB_LIBSOURCES_DIR])[/$gl_file" >&2
          exit 1
        fi
      done])dnl
      m4_if(m4_sysval, [0], [],
        [AC_FATAL([expected source file, required through AC_LIBSOURCES, not found])])
  ])
  m4_popdef([GNULIB_LIBSOURCES_DIR])
  m4_popdef([GNULIB_LIBSOURCES_LIST])
  m4_popdef([AC_LIBSOURCES])
  m4_popdef([AC_REPLACE_FUNCS])
  m4_popdef([AC_LIBOBJ])
  AC_CONFIG_COMMANDS_PRE([
    GNULIB_libobjs=
    GNULIB_ltlibobjs=
    if test -n "$GNULIB_LIBOBJS"; then
      # Remove the extension.
      sed_drop_objext='s/\.o$//;s/\.obj$//'
      for i in `for i in $GNULIB_LIBOBJS; do echo "$i"; done | sed "$sed_drop_objext" | sort | uniq`; do
        GNULIB_libobjs="$GNULIB_libobjs $i.$ac_objext"
        GNULIB_ltlibobjs="$GNULIB_ltlibobjs $i.lo"
      done
    fi
    AC_SUBST([GNULIB_LIBOBJS], [$GNULIB_libobjs])
    AC_SUBST([GNULIB_LTLIBOBJS], [$GNULIB_ltlibobjs])
  ])
  gltests_libdeps=
  gltests_ltlibdeps=
  m4_pushdef([AC_LIBOBJ], m4_defn([GNULIBtests_LIBOBJ]))
  m4_pushdef([AC_REPLACE_FUNCS], m4_defn([GNULIBtests_REPLACE_FUNCS]))
  m4_pushdef([AC_LIBSOURCES], m4_defn([GNULIBtests_LIBSOURCES]))
  m4_pushdef([GNULIBtests_LIBSOURCES_LIST], [])
  m4_pushdef([GNULIBtests_LIBSOURCES_DIR], [])
  gl_COMMON
  gl_source_base='tests'
  m4_ifval(GNULIBtests_LIBSOURCES_LIST, [
    m4_syscmd([test ! -d ]m4_defn([GNULIBtests_LIBSOURCES_DIR])[ ||
      for gl_file in ]GNULIBtests_LIBSOURCES_LIST[ ; do
        if test ! -r ]m4_defn([GNULIBtests_LIBSOURCES_DIR])[/$gl_file ; then
          echo "missing file ]m4_defn([GNULIBtests_LIBSOURCES_DIR])[/$gl_file" >&2
          exit 1
        fi
      done])dnl
      m4_if(m4_sysval, [0], [],
        [AC_FATAL([expected source file, required through AC_LIBSOURCES, not found])])
  ])
  m4_popdef([GNULIBtests_LIBSOURCES_DIR])
  m4_popdef([GNULIBtests_LIBSOURCES_LIST])
  m4_popdef([AC_LIBSOURCES])
  m4_popdef([AC_REPLACE_FUNCS])
  m4_popdef([AC_LIBOBJ])
  AC_CONFIG_COMMANDS_PRE([
    GNULIBtests_libobjs=
    GNULIBtests_ltlibobjs=
    if test -n "$GNULIBtests_LIBOBJS"; then
      # Remove the extension.
      sed_drop_objext='s/\.o$//;s/\.obj$//'
      for i in `for i in $GNULIBtests_LIBOBJS; do echo "$i"; done | sed "$sed_drop_objext" | sort | uniq`; do
        GNULIBtests_libobjs="$GNULIBtests_libobjs $i.$ac_objext"
        GNULIBtests_ltlibobjs="$GNULIBtests_ltlibobjs $i.lo"
      done
    fi
    AC_SUBST([GNULIBtests_LIBOBJS], [$GNULIBtests_libobjs])
    AC_SUBST([GNULIBtests_LTLIBOBJS], [$GNULIBtests_ltlibobjs])
  ])
  LIBGNU_LIBDEPS="$gl_libdeps"
  AC_SUBST([LIBGNU_LIBDEPS])
  LIBGNU_LTLIBDEPS="$gl_ltlibdeps"
  AC_SUBST([LIBGNU_LTLIBDEPS])
])

# Like AC_LIBOBJ, except that the module name goes
# into GNULIB_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([GNULIB_LIBOBJ], [
  AS_LITERAL_IF([$1], [GNULIB_LIBSOURCES([$1.c])])dnl
  GNULIB_LIBOBJS="$GNULIB_LIBOBJS $1.$ac_objext"
])

# Like AC_REPLACE_FUNCS, except that the module name goes
# into GNULIB_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([GNULIB_REPLACE_FUNCS], [
  m4_foreach_w([gl_NAME], [$1], [AC_LIBSOURCES(gl_NAME[.c])])dnl
  AC_CHECK_FUNCS([$1], , [GNULIB_LIBOBJ($ac_func)])
])

# Like AC_LIBSOURCES, except the directory where the source file is
# expected is derived from the gnulib-tool parameterization,
# and alloca is special cased (for the alloca-opt module).
# We could also entirely rely on EXTRA_lib..._SOURCES.
AC_DEFUN([GNULIB_LIBSOURCES], [
  m4_foreach([_gl_NAME], [$1], [
    m4_if(_gl_NAME, [alloca.c], [], [
      m4_define([GNULIB_LIBSOURCES_DIR], [./src/gnulib])
      m4_append([GNULIB_LIBSOURCES_LIST], _gl_NAME, [ ])
    ])
  ])
])

# Like AC_LIBOBJ, except that the module name goes
# into GNULIBtests_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([GNULIBtests_LIBOBJ], [
  AS_LITERAL_IF([$1], [GNULIBtests_LIBSOURCES([$1.c])])dnl
  GNULIBtests_LIBOBJS="$GNULIBtests_LIBOBJS $1.$ac_objext"
])

# Like AC_REPLACE_FUNCS, except that the module name goes
# into GNULIBtests_LIBOBJS instead of into LIBOBJS.
AC_DEFUN([GNULIBtests_REPLACE_FUNCS], [
  m4_foreach_w([gl_NAME], [$1], [AC_LIBSOURCES(gl_NAME[.c])])dnl
  AC_CHECK_FUNCS([$1], , [GNULIBtests_LIBOBJ($ac_func)])
])

# Like AC_LIBSOURCES, except the directory where the source file is
# expected is derived from the gnulib-tool parameterization,
# and alloca is special cased (for the alloca-opt module).
# We could also entirely rely on EXTRA_lib..._SOURCES.
AC_DEFUN([GNULIBtests_LIBSOURCES], [
  m4_foreach([_gl_NAME], [$1], [
    m4_if(_gl_NAME, [alloca.c], [], [
      m4_define([GNULIBtests_LIBSOURCES_DIR], [tests])
      m4_append([GNULIBtests_LIBSOURCES_LIST], _gl_NAME, [ ])
    ])
  ])
])

# This macro records the list of files which have been installed by
# gnulib-tool and may be removed by future gnulib-tool invocations.
AC_DEFUN([GNULIB_FILE_LIST], [
  build-aux/link-warning.h
  lib/alloca.c
  lib/alloca.in.h
  lib/config.charset
  lib/getopt.c
  lib/getopt.in.h
  lib/getopt1.c
  lib/getopt_int.h
  lib/gettext.h
  lib/localcharset.c
  lib/localcharset.h
  lib/malloc.c
  lib/ref-add.sin
  lib/ref-del.sin
  lib/regcomp.c
  lib/regex.c
  lib/regex.h
  lib/regex_internal.c
  lib/regex_internal.h
  lib/regexec.c
  lib/stdbool.in.h
  lib/stdint.in.h
  lib/stdlib.in.h
  lib/sys_stat.in.h
  lib/unistd.in.h
  lib/wchar.in.h
  lib/wctype.in.h
  m4/alloca.m4
  m4/codeset.m4
  m4/extensions.m4
  m4/getopt.m4
  m4/glibc21.m4
  m4/gnulib-common.m4
  m4/include_next.m4
  m4/localcharset.m4
  m4/longlong.m4
  m4/malloc.m4
  m4/mbstate_t.m4
  m4/regex.m4
  m4/ssize_t.m4
  m4/stdbool.m4
  m4/stdint.m4
  m4/stdlib_h.m4
  m4/sys_stat_h.m4
  m4/unistd_h.m4
  m4/wchar.m4
  m4/wctype.m4
  m4/wint_t.m4
])