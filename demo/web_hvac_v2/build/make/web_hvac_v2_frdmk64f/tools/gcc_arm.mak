#-----------------------------------------------------------
# libraries
#-----------------------------------------------------------
ifeq ($(CONFIG),debug)
LIBRARIES += $(MQX_ROOTDIR)/lib/frdmk64f.gcc_arm/debug/bsp/bsp.a
LIBRARIES += $(MQX_ROOTDIR)/lib/frdmk64f.gcc_arm/debug/psp/psp.a
LIBRARIES += $(MQX_ROOTDIR)/lib/frdmk64f.gcc_arm/debug/mfs/mfs.a
LIBRARIES += $(MQX_ROOTDIR)/lib/frdmk64f.gcc_arm/debug/rtcs/rtcs.a
LIBRARIES += $(MQX_ROOTDIR)/lib/frdmk64f.gcc_arm/debug/shell/shell.a
LIBRARIES += $(MQX_ROOTDIR)/usb_v2/output/frdmk64f.gcc_arm/debug/usbh/mqx/libusbh_mqx.a
LIBRARIES += $(TOOLCHAIN_ROOTDIR)/lib/gcc/arm-none-eabi/$(GCC_VERSION)/armv7e-m/fpu/libgcc.a
LIBRARIES += $(TOOLCHAIN_ROOTDIR)/arm-none-eabi/lib/armv7e-m/fpu/libc.a
LIBRARIES += $(TOOLCHAIN_ROOTDIR)/arm-none-eabi/lib/armv7e-m/fpu/libsupc++.a
LIBRARIES += $(TOOLCHAIN_ROOTDIR)/arm-none-eabi/lib/armv7e-m/fpu/libm.a
LIBRARIES += $(TOOLCHAIN_ROOTDIR)/arm-none-eabi/lib/armv7e-m/fpu/libnosys.a
endif
ifeq ($(CONFIG),release)
LIBRARIES += $(MQX_ROOTDIR)/lib/frdmk64f.gcc_arm/release/bsp/bsp.a
LIBRARIES += $(MQX_ROOTDIR)/lib/frdmk64f.gcc_arm/release/psp/psp.a
LIBRARIES += $(MQX_ROOTDIR)/lib/frdmk64f.gcc_arm/release/mfs/mfs.a
LIBRARIES += $(MQX_ROOTDIR)/lib/frdmk64f.gcc_arm/release/rtcs/rtcs.a
LIBRARIES += $(MQX_ROOTDIR)/lib/frdmk64f.gcc_arm/release/shell/shell.a
LIBRARIES += $(MQX_ROOTDIR)/usb_v2/output/frdmk64f.gcc_arm/release/usbh/mqx/libusbh_mqx.a
LIBRARIES += $(TOOLCHAIN_ROOTDIR)/lib/gcc/arm-none-eabi/$(GCC_VERSION)/armv7e-m/fpu/libgcc.a
LIBRARIES += $(TOOLCHAIN_ROOTDIR)/arm-none-eabi/lib/armv7e-m/fpu/libc.a
LIBRARIES += $(TOOLCHAIN_ROOTDIR)/arm-none-eabi/lib/armv7e-m/fpu/libsupc++.a
LIBRARIES += $(TOOLCHAIN_ROOTDIR)/arm-none-eabi/lib/armv7e-m/fpu/libm.a
LIBRARIES += $(TOOLCHAIN_ROOTDIR)/arm-none-eabi/lib/armv7e-m/fpu/libnosys.a
endif


#-----------------------------------------------------------
# search paths
#-----------------------------------------------------------
ifeq ($(CONFIG),debug)
INCLUDE += $(MQX_ROOTDIR)/lib/frdmk64f.gcc_arm/debug/bsp/Generated_Code
INCLUDE += $(MQX_ROOTDIR)/lib/frdmk64f.gcc_arm/debug
INCLUDE += $(MQX_ROOTDIR)/lib/frdmk64f.gcc_arm/debug/bsp
INCLUDE += $(MQX_ROOTDIR)/lib/frdmk64f.gcc_arm/debug/psp
INCLUDE += $(MQX_ROOTDIR)/lib/frdmk64f.gcc_arm/debug/mfs
INCLUDE += $(MQX_ROOTDIR)/lib/frdmk64f.gcc_arm/debug/rtcs
INCLUDE += $(MQX_ROOTDIR)/lib/frdmk64f.gcc_arm/debug/shell
INCLUDE += $(MQX_ROOTDIR)/usb_v2/output/frdmk64f.gcc_arm/debug/usbh/mqx
endif
ifeq ($(CONFIG),release)
INCLUDE += $(MQX_ROOTDIR)/lib/frdmk64f.gcc_arm/release/bsp/Generated_Code
INCLUDE += $(MQX_ROOTDIR)/lib/frdmk64f.gcc_arm/release
INCLUDE += $(MQX_ROOTDIR)/lib/frdmk64f.gcc_arm/release/bsp
INCLUDE += $(MQX_ROOTDIR)/lib/frdmk64f.gcc_arm/release/psp
INCLUDE += $(MQX_ROOTDIR)/lib/frdmk64f.gcc_arm/release/mfs
INCLUDE += $(MQX_ROOTDIR)/lib/frdmk64f.gcc_arm/release/rtcs
INCLUDE += $(MQX_ROOTDIR)/lib/frdmk64f.gcc_arm/release/shell
INCLUDE += $(MQX_ROOTDIR)/usb_v2/output/frdmk64f.gcc_arm/release/usbh/mqx
endif





