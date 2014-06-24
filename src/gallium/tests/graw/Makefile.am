include $(top_srcdir)/src/gallium/Automake.inc

AM_CFLAGS = \
	$(GALLIUM_CFLAGS)

AM_CPPFLAGS = \
	-I$(top_srcdir)/src/gallium/drivers \
	-I$(top_srcdir)/src/gallium/winsys \
	-DGALLIUM_LLVMPIPE

LDADD = \
	$(top_builddir)/src/gallium/targets/graw-xlib/libgraw.la \
	$(top_builddir)/src/gallium/winsys/sw/xlib/libws_xlib.la \
	$(top_builddir)/src/gallium/drivers/softpipe/libsoftpipe.la \
	$(top_builddir)/src/gallium/drivers/trace/libtrace.la \
	$(top_builddir)/src/gallium/drivers/rbug/librbug.la \
	$(GALLIUM_DRI_LIB_DEPS) \
	$(top_builddir)/src/gallium/drivers/llvmpipe/libllvmpipe.la \
	-lX11 -lXext

noinst_PROGRAMS = clear disasm fs-fragcoord fs-frontface fs-test \
                  fs-write-z gs-test occlusion-query quad-sample \
                  quad-tex shader-leak tex-srgb tex-swizzle tri \
                  tri-gs tri-instanced tri-large vs-test

clear_SOURCES = clear.c

disasm_SOURCES = disasm.c

fs_fragcoord_SOURCES = fs-fragcoord.c

fs_frontface_SOURCES = fs-frontface.c

fs_test_SOURCES = fs-test.c

fs_write_z_SOURCES = fs-write-z.c

gs_test_SOURCES = gs-test.c

occlusion_query_SOURCES = occlusion-query.c

quad_sample_SOURCES = quad-sample.c

quad_tex_SOURCES = quad-tex.c

shader_leak_SOURCES = shader-leak.c

tex_srgb_SOURCES = tex-srgb.c

tex_swizzle_SOURCES = tex-swizzle.c

tri_SOURCES = tri.c

tri_gs_SOURCES = tri-gs.c

tri_instanced_SOURCES = tri-instanced.c

tri_large_SOURCES = tri-large.c

vs_test_SOURCES = vs-test.c
