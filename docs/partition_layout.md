# Partition Layout

The sample partition table provides NVS, OTA selection metadata, PHY data, a factory/recovery application and two OTA slots.

The exact offsets are examples. They must be checked against the selected ESP32 flash size and actual application binary size before hardware deployment.

For field products, keep a recoverable image and reserve enough OTA space for the largest expected application plus future growth.