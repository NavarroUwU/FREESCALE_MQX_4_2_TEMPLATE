#-----------------------------------------------------------
# libraries
#-----------------------------------------------------------
ifeq ($(CONFIG),debug)
LIBRARIES += $(MQX_ROOTDIR)/lib/twrk60n512.iar/debug/bsp/bsp.a
LIBRARIES += $(MQX_ROOTDIR)/lib/twrk60n512.iar/debug/psp/psp.a
LIBRARIES += $(MQX_ROOTDIR)/lib/twrk60n512.iar/debug/rtcs/rtcs.a
endif
ifeq ($(CONFIG),release)
LIBRARIES += $(MQX_ROOTDIR)/lib/twrk60n512.iar/release/bsp/bsp.a
LIBRARIES += $(MQX_ROOTDIR)/lib/twrk60n512.iar/release/psp/psp.a
LIBRARIES += $(MQX_ROOTDIR)/lib/twrk60n512.iar/release/rtcs/rtcs.a
endif


#-----------------------------------------------------------
# search paths
#-----------------------------------------------------------
ifeq ($(CONFIG),debug)
INCLUDE += $(MQX_ROOTDIR)/lib/twrk60n512.iar/debug/bsp/Generated_Code
INCLUDE += $(MQX_ROOTDIR)/lib/twrk60n512.iar/debug
INCLUDE += $(MQX_ROOTDIR)/lib/twrk60n512.iar/debug/bsp
INCLUDE += $(MQX_ROOTDIR)/lib/twrk60n512.iar/debug/psp
INCLUDE += $(MQX_ROOTDIR)/lib/twrk60n512.iar/debug/rtcs
endif
ifeq ($(CONFIG),release)
INCLUDE += $(MQX_ROOTDIR)/lib/twrk60n512.iar/release/bsp/Generated_Code
INCLUDE += $(MQX_ROOTDIR)/lib/twrk60n512.iar/release
INCLUDE += $(MQX_ROOTDIR)/lib/twrk60n512.iar/release/bsp
INCLUDE += $(MQX_ROOTDIR)/lib/twrk60n512.iar/release/psp
INCLUDE += $(MQX_ROOTDIR)/lib/twrk60n512.iar/release/rtcs
endif






