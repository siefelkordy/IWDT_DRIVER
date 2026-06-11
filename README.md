# IWDT_DRIVER
# Independent Watchdog Timer (IWDT) Driver

Device: TI TMS320F28388D

## Features

- Watchdog initialization
- Reset mode support
- Interrupt mode support
- Configurable prescaler
- Windowed watchdog mode
- Service key sequence handling
- Reset cause detection

## Driver Architecture

IWDT_DRIVER
├── inc
│   ├── IWDT.h
│   ├── IWDT_Types.h
│   ├── IWDT_Cfg.h
│   └── IWDT_Reg.h
├── src
│   ├── IWDT.c
│   └── IWDT_Cfg.c
└── main.c
