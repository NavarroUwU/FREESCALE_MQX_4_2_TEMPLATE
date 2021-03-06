#-----------------------------------------------------------
# libraries
#-----------------------------------------------------------
ifeq ($(CONFIG),debug)
LIBRARIES += $(MQX_ROOTDIR)/lib/twrvf65gs10_a5.ds5/debug/bsp/bsp.a
LIBRARIES += $(MQX_ROOTDIR)/lib/twrvf65gs10_a5.ds5/debug/psp/psp.a
LIBRARIES += $(MQX_ROOTDIR)/lib/twrvf65gs10_a5.ds5/debug/mfs/mfs.a
LIBRARIES += $(MQX_ROOTDIR)/lib/twrvf65gs10_a5.ds5/debug/ffs/ffs.a
LIBRARIES += $(MQX_ROOTDIR)/lib/twrvf65gs10_a5.ds5/debug/shell/shell.a
LIBRARIES_NODEPS += $(MQX_ROOTDIR)/lib/twrvf65gs10_a5.ds5/debug/psp/psp.a(linker_symbols.o)
RT_PATHS += $(TOOLCHAIN_ROOTDIR)/sw/ARMCompiler5.05u1/lib/
endif
ifeq ($(CONFIG),release)
LIBRARIES += $(MQX_ROOTDIR)/lib/twrvf65gs10_a5.ds5/release/bsp/bsp.a
LIBRARIES += $(MQX_ROOTDIR)/lib/twrvf65gs10_a5.ds5/release/psp/psp.a
LIBRARIES += $(MQX_ROOTDIR)/lib/twrvf65gs10_a5.ds5/release/mfs/mfs.a
LIBRARIES += $(MQX_ROOTDIR)/lib/twrvf65gs10_a5.ds5/release/ffs/ffs.a
LIBRARIES += $(MQX_ROOTDIR)/lib/twrvf65gs10_a5.ds5/release/shell/shell.a
LIBRARIES_NODEPS += $(MQX_ROOTDIR)/lib/twrvf65gs10_a5.ds5/release/psp/psp.a(linker_symbols.o)
RT_PATHS += $(TOOLCHAIN_ROOTDIR)/sw/ARMCompiler5.05u1/lib/
endif


#-----------------------------------------------------------
# search paths
#-----------------------------------------------------------
ifeq ($(CONFIG),debug)
INCLUDE += $(MQX_ROOTDIR)/lib/twrvf65gs10_a5.ds5/debug
INCLUDE += $(MQX_ROOTDIR)/lib/twrvf65gs10_a5.ds5/debug/bsp
INCLUDE += $(MQX_ROOTDIR)/lib/twrvf65gs10_a5.ds5/debug/bsp/Generated_Code
INCLUDE += $(MQX_ROOTDIR)/lib/twrvf65gs10_a5.ds5/debug/psp
INCLUDE += $(MQX_ROOTDIR)/lib/twrvf65gs10_a5.ds5/debug/mfs
INCLUDE += $(MQX_ROOTDIR)/lib/twrvf65gs10_a5.ds5/debug/ffs
INCLUDE += $(MQX_ROOTDIR)/lib/twrvf65gs10_a5.ds5/debug/shell
INCLUDE += $(TOOLCHAIN_ROOTDIR)/include
endif
ifeq ($(CONFIG),release)
INCLUDE += $(MQX_ROOTDIR)/lib/twrvf65gs10_a5.ds5/release
INCLUDE += $(MQX_ROOTDIR)/lib/twrvf65gs10_a5.ds5/release/bsp
INCLUDE += $(MQX_ROOTDIR)/lib/twrvf65gs10_a5.ds5/release/bsp/Generated_Code
INCLUDE += $(MQX_ROOTDIR)/lib/twrvf65gs10_a5.ds5/release/psp
INCLUDE += $(MQX_ROOTDIR)/lib/twrvf65gs10_a5.ds5/release/mfs
INCLUDE += $(MQX_ROOTDIR)/lib/twrvf65gs10_a5.ds5/release/ffs
INCLUDE += $(MQX_ROOTDIR)/lib/twrvf65gs10_a5.ds5/release/shell
INCLUDE += $(TOOLCHAIN_ROOTDIR)/include
endif






