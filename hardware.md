# ESP32 Robot hardware

## Hardware
- ESP32 DevKitC
- 2x DRV8833 motor drivers
- 4x DC motors
- 5V buck for ESP32
- 6V buck for motor drivers

## Pin Mapping

### Driver 1
- IN1 = GPIO16
- IN2 = GPIO17
- IN3 = GPIO19
- IN4 = GPIO21
- EEP = GPIO22

### Driver 2
- IN1 = GPIO32
- IN2 = GPIO33
- IN3 = GPIO25
- IN4 = GPIO26
- EEP = GPIO27

## Build and Upload
Open the `firmware` folder in PlatformIO and upload normally.
