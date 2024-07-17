# This file intentionally left blank

COMMON_VPATH += $(DRIVER_PATH)/tinyexpr
SRC += $(DRIVER_PATH)/tinyexpr/tinyexpr.c

COMMON_VPATH += $(DRIVER_PATH)/ryu
SRC += $(DRIVER_PATH)/ryu/ryu/d2fixed.c

SEND_STRING_ENABLE = yes
RGB_MATRIX_CUSTOM_KB = yes
