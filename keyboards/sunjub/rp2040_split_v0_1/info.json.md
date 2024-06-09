{
    "manufacturer": "sunjub",
    "keyboard_name": "split_test",
    "url": "",
    "maintainer": "sunjub",
    "processor": "RP2040",
    "bootloader": "rp2040",
    "usb": {
        "vid": "0x3DEB",
        "pid": "0x5332",
        "device_version": "0.0.1"
    },
    "features": {
        "audio": false,
        "bootmagic": true,
        "command": false,
        "console": true,
        "extrakey": true,
        "mousekey": true,
        "nkro": true,
        "rgb_matrix": false,
        "rgblight": true,
        "encoder": true
    },
    "debounce": 5,
    "matrix_pins": {
        "cols": ["GP17", "GP18", "GP19", "GP20", "GP21", "GP23", "GP0", "GP14", "GP8"],
        "rows": ["GP27", "GP26", "GP25", "GP24", "GP28", "GP16", "GP15"]
    },
    "diode_direction": "COL2ROW",
    "encoder": {
        "rotary": [
            {"pin_a": "GP1", "pin_b": "GP2"},
            {"pin_a": "GP10", "pin_b": "GP11"}
        ]
    },
    "split": {
        "enabled": true,
        "transport": {
            "sync": {
                "matrix_state": true,
                "layer_state": true,
                "modifiers": true
            }
        },
        "usb_detect": {
            "enabled": true,
            "timeout": 2500
        },
        "handedness": {
            "pin": "GP9"
        },
        "encoder": {
            "right": {
                "rotary": [
                    {"pin_a": "GP2", "pin_b": "GP1"},
                    {"pin_a": "GP11", "pin_b": "GP10"}
                ]
            }
        }
    },
    "tapping": {
        "term": 132
    },
    "ws2812": {
        "driver": "vendor",
        "pin": "GP3"
    },
    "rgblight": {
        "saturation_steps": 8,
        "brightness_steps": 8,
        "led_count": 6,
        "max_brightness": 80,
        "led_map": [0, 1, 2, 3, 4, 5],
        "sleep": true,
        "split": true,
        "split_count": [3, 3],
        "animations": {
            "rainbow_swirl": true,
            "rgb_test": true
        },
        "layers": {
            "enabled": true,
            "max": 8
        },
        "default": {
            "val": 0
        }
    },
    "layouts": {
        "LAYOUT": {
            "layout": [
                {"matrix": [0, 0], "x": 0, "y": 0},
                {"matrix": [0, 1], "x": 0, "y": 1},
                {"matrix": [0, 2], "x": 0, "y": 2},
                {"matrix": [0, 3], "x": 0, "y": 3},
                {"matrix": [0, 4], "x": 0, "y": 4},
                {"matrix": [0, 5], "x": 0, "y": 5},
                {"matrix": [0, 6], "x": 0, "y": 6},

                {"matrix": [7, 6], "x": 6, "y": 6},
                {"matrix": [7, 5], "x": 6, "y": 5},
                {"matrix": [7, 4], "x": 6, "y": 4},
                {"matrix": [7, 3], "x": 6, "y": 3},
                {"matrix": [7, 2], "x": 6, "y": 2},
                {"matrix": [7, 1], "x": 6, "y": 1},
                {"matrix": [7, 0], "x": 6, "y": 0},

                {"matrix": [1, 0], "x": 1, "y": 0},
                {"matrix": [1, 1], "x": 1, "y": 1},
                {"matrix": [1, 2], "x": 1, "y": 2},
                {"matrix": [1, 3], "x": 1, "y": 3},
                {"matrix": [1, 4], "x": 1, "y": 4},
                {"matrix": [1, 5], "x": 1, "y": 5},
                {"matrix": [1, 6], "x": 1, "y": 6},

                {"matrix": [8, 6], "x": 7, "y": 6},
                {"matrix": [8, 5], "x": 7, "y": 5},
                {"matrix": [8, 4], "x": 7, "y": 4},
                {"matrix": [8, 3], "x": 7, "y": 3},
                {"matrix": [8, 2], "x": 7, "y": 2},
                {"matrix": [8, 1], "x": 7, "y": 1},
                {"matrix": [8, 0], "x": 7, "y": 0},

                {"matrix": [2, 0], "x": 2, "y": 0},
                {"matrix": [2, 1], "x": 2, "y": 1},
                {"matrix": [2, 2], "x": 2, "y": 2},
                {"matrix": [2, 3], "x": 2, "y": 3},
                {"matrix": [2, 4], "x": 2, "y": 4},
                {"matrix": [2, 5], "x": 2, "y": 5},
                {"matrix": [2, 6], "x": 2, "y": 6},

                {"matrix": [9, 6], "x": 8, "y": 6},
                {"matrix": [9, 5], "x": 8, "y": 5},
                {"matrix": [9, 4], "x": 8, "y": 4},
                {"matrix": [9, 3], "x": 8, "y": 3},
                {"matrix": [9, 2], "x": 8, "y": 2},
                {"matrix": [9, 1], "x": 8, "y": 1},
                {"matrix": [9, 0], "x": 8, "y": 0},

                {"matrix": [3, 0], "x": 3, "y": 0},
                {"matrix": [3, 1], "x": 3, "y": 1},
                {"matrix": [3, 2], "x": 3, "y": 2},
                {"matrix": [3, 3], "x": 3, "y": 3},
                {"matrix": [3, 4], "x": 3, "y": 4},
                {"matrix": [3, 5], "x": 3, "y": 5},
                {"matrix": [3, 6], "x": 3, "y": 6},

                {"matrix": [10, 6], "x": 9, "y": 6},
                {"matrix": [10, 5], "x": 9, "y": 5},
                {"matrix": [10, 4], "x": 9, "y": 4},
                {"matrix": [10, 3], "x": 9, "y": 3},
                {"matrix": [10, 2], "x": 9, "y": 2},
                {"matrix": [10, 1], "x": 9, "y": 1},
                {"matrix": [10, 0], "x": 9, "y": 0},

                {"matrix": [4, 0], "x": 4, "y": 0},
                {"matrix": [4, 1], "x": 4, "y": 1},
                {"matrix": [4, 2], "x": 4, "y": 2},
                {"matrix": [4, 3], "x": 4, "y": 3},
                {"matrix": [4, 4], "x": 4, "y": 4},
                {"matrix": [4, 5], "x": 4, "y": 5},
                {"matrix": [6, 7], "x": 4, "y": 6},

                {"matrix": [13, 7], "x": 10, "y": 6},
                {"matrix": [11, 5], "x": 10, "y": 5},
                {"matrix": [11, 4], "x": 10, "y": 4},
                {"matrix": [11, 3], "x": 10, "y": 3},
                {"matrix": [11, 2], "x": 10, "y": 2},
                {"matrix": [11, 1], "x": 10, "y": 1},
                {"matrix": [11, 0], "x": 10, "y": 0},

                {"matrix": [5, 0], "x": 5, "y": 0},
                {"matrix": [5, 1], "x": 5, "y": 1},
                {"matrix": [5, 2], "x": 5, "y": 2},
                {"matrix": [5, 3], "x": 5, "y": 3},
                {"matrix": [5, 4], "x": 5, "y": 4},
                {"matrix": [5, 5], "x": 5, "y": 5},
                {"matrix": [5, 7], "x": 5, "y": 6},

                {"matrix": [12, 7], "x": 11, "y": 6},
                {"matrix": [12, 5], "x": 11, "y": 5},
                {"matrix": [12, 4], "x": 11, "y": 4},
                {"matrix": [12, 3], "x": 11, "y": 3},
                {"matrix": [12, 2], "x": 11, "y": 2},
                {"matrix": [12, 1], "x": 11, "y": 1},
                {"matrix": [12, 0], "x": 11, "y": 0},

                {"matrix": [3, 8], "x": 6, "y": 7},
                {"matrix": [10, 8], "x": 13, "y": 7}
            ]
        }
    }
}