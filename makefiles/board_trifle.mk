#
# Board-specific definitions for the Condor flight controller
#

#
# Configure the toolchain
#
CONFIG_ARCH			 = CORTEXM4
CONFIG_BOARD			 = TRIFLE


include $(PX4_MK_DIR)/toolchain_gnu-arm-eabi.mk
