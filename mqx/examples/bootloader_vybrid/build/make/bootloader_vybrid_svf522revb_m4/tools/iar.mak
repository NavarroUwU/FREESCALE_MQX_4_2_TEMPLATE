#-----------------------------------------------------------
# libraries
#-----------------------------------------------------------
ifeq ($(CONFIG),debug)
LIBRARIES += $(MQX_ROOTDIR)/lib/svf522revb_m4.iar/debug/bsp/bsp.a
LIBRARIES += $(MQX_ROOTDIR)/lib/svf522revb_m4.iar/debug/psp/psp.a
LIBRARIES += $(MQX_ROOTDIR)/lib/svf522revb_m4.iar/debug/mfs/mfs.a
endif
ifeq ($(CONFIG),release)
LIBRARIES += $(MQX_ROOTDIR)/lib/svf522revb_m4.iar/release/bsp/bsp.a
LIBRARIES += $(MQX_ROOTDIR)/lib/svf522revb_m4.iar/release/psp/psp.a
LIBRARIES += $(MQX_ROOTDIR)/lib/svf522revb_m4.iar/release/mfs/mfs.a
endif


#-----------------------------------------------------------
# search paths
#-----------------------------------------------------------
ifeq ($(CONFIG),debug)
INCLUDE += $(MQX_ROOTDIR)/lib/svf522revb_m4.iar/debug/bsp/Generated_Code
INCLUDE += $(MQX_ROOTDIR)/lib/svf522revb_m4.iar/debug
INCLUDE += $(MQX_ROOTDIR)/lib/svf522revb_m4.iar/debug/bsp
INCLUDE += $(MQX_ROOTDIR)/lib/svf522revb_m4.iar/debug/psp
INCLUDE += $(MQX_ROOTDIR)/lib/svf522revb_m4.iar/debug/mfs
endif
ifeq ($(CONFIG),release)
INCLUDE += $(MQX_ROOTDIR)/lib/svf522revb_m4.iar/release/bsp/Generated_Code
INCLUDE += $(MQX_ROOTDIR)/lib/svf522revb_m4.iar/release
INCLUDE += $(MQX_ROOTDIR)/lib/svf522revb_m4.iar/release/bsp
INCLUDE += $(MQX_ROOTDIR)/lib/svf522revb_m4.iar/release/psp
INCLUDE += $(MQX_ROOTDIR)/lib/svf522revb_m4.iar/release/mfs
endif






