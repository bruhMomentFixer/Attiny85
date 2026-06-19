# DigiSpark ATTiny85 HID Payloads — Spanish Keyboard Layout Adaptation

> Fork of `MTK911/Attiny85` focused on analyzing, testing, and adapting DigiSpark ATTiny85 USB HID payloads for Spanish keyboard layouts.

## Overview

This repository is a fork of the original `MTK911/Attiny85` project, which contains DigiSpark ATTiny85 USB HID payloads inspired by Rubber Ducky-style attacks.

The purpose of this fork is to document, test, and adapt selected payloads so they work correctly on systems configured with a Spanish keyboard layout.

DigiSpark ATTiny85 boards can emulate a USB keyboard through the `DigiKeyboard.h` library. This allows the device to send automated keystrokes to a computer when plugged in as a USB HID device.

This type of project is useful for:

* Red Team training
* Penetration testing labs
* HID attack simulation
* Payload testing in controlled environments
* Keyboard layout compatibility research
* Understanding USB HID-based attack techniques

## My Contributions

This fork focuses on Spanish keyboard layout compatibility.

Main contributions include:

* Adaptation of selected DigiSpark ATTiny85 HID payloads for Spanish keyboard layouts.
* Testing of `DigiKeyboard.print()` and `DigiKeyboard.sendKeyStroke()` behavior on Spanish keyboard configurations.
* Replacement or modification of characters that behave differently between English/US and Spanish layouts.
* Documentation of keyboard layout issues affecting command-line payloads.
* Creation of a character mapping reference for Spanish layout adaptation.
* Preservation of the original upstream README as `README_ORIGINAL.md`.
* Addition of a `NOTICE.md` file documenting the fork relationship and attribution to the upstream project.

Modified payload categories include:

* Wi-Fi credential extraction payload adaptation
* Instant shell payload adaptation

The original payload logic belongs to the upstream project. This fork mainly documents and adapts selected payloads for Spanish keyboard layout compatibility.

## Technical Research Notes

This project also documents the technical background behind the keyboard layout adaptation process.

The main issue is that DigiSpark ATTiny85 payloads do not directly send final text characters to the operating system. Instead, they emulate keyboard input using USB HID usage codes.

The final character produced on the target system depends on the active keyboard layout configured in the operating system.

For example, a HID key combination that produces `/` on an English/US keyboard layout may produce a different character on a Spanish keyboard layout.

This is especially relevant for command-line payloads, where characters such as the following are frequently required:

```text
/ \ | @ # ~ " ' : ; { } [ ] ( ) = + - _
```

Incorrect character output can break:

* CMD commands
* PowerShell commands
* File paths
* URLs
* Webhook URLs
* Redirection operators
* Pipes
* Script blocks
* Encoded commands
* Download commands
* Payload execution syntax

## HID Usage IDs and DigiKeyboard

DigiSpark ATTiny85 payloads commonly use the `DigiKeyboard.h` library.

Reference implementation:

```text
https://github.com/digistump/DigistumpArduino/blob/master/digistump-avr/libraries/DigisparkKeyboard/DigiKeyboard.h
```

Inside `DigiKeyboard.h`, keyboard input is represented through USB HID keyboard usage values and modifier bits.

Examples of modifier definitions include:

```cpp
#define MOD_CONTROL_LEFT    (1 << 0)
#define MOD_SHIFT_LEFT      (1 << 1)
#define MOD_ALT_LEFT        (1 << 2)
#define MOD_GUI_LEFT        (1 << 3)
#define MOD_CONTROL_RIGHT   (1 << 4)
#define MOD_SHIFT_RIGHT     (1 << 5)
#define MOD_ALT_RIGHT       (1 << 6)
#define MOD_GUI_RIGHT       (1 << 7)
```

Examples of keyboard usage IDs include:

```cpp
#define KEY_A       4
#define KEY_B       5
#define KEY_C       6
#define KEY_D       7
#define KEY_E       8
#define KEY_F       9
#define KEY_G       10
#define KEY_H       11
#define KEY_I       12
#define KEY_J       13
```

These values are based on the USB HID Usage Tables specification, specifically the Keyboard/Keypad Page.

Official USB HID Usage Tables reference:

```text
https://usb.org/document-library/hid-usage-tables-17
```

## Keyboard Layout Problem

Many HID payloads are written assuming an English/US keyboard layout.

However, when the target system uses a Spanish keyboard layout, the same HID usage codes may produce different output characters.

This means that a payload that works correctly on an English/US layout may fail on a Spanish layout because characters such as `/`, `-`, `:`, `=`, `"`, `|`, `[`, `]`, `{`, and `}` may not be generated correctly.

To solve this, this fork documents and applies character substitutions and explicit `DigiKeyboard.sendKeyStroke()` calls for selected payloads.

The character mapping used during the adaptation process is documented in:

```text
CHAR_MAPPING.md
```

## Local Reference Documentation

During the research process, the USB HID Usage Tables specification was used as a reference.

A local copy may exist in the repository working directory as:

```text
hut1_7.pdf
```

However, for public repositories, it is recommended to link to the official USB.org document instead of redistributing the PDF directly.

Official source:

```text
https://usb.org/document-library/hid-usage-tables-17
```

## Repository Structure

```text
payloads/
├── Backdoor/
├── Instant Shell/
├── Keylogger/
├── Payload Dropper/
├── SAM Dumper/
├── UAC Bypass/
├── WiFi Password Stealer/
├── Windows Crasher/
└── Windows Phisher/
```

Additional documentation:

```text
README.md             Main fork documentation
README_ORIGINAL.md    Original upstream README
NOTICE.md             Fork attribution and modification notice
CHAR_MAPPING.md       Spanish keyboard layout character mapping
LICENSE               Original upstream license
```

## Hardware Requirements

* DigiSpark ATTiny85 development board
* USB port
* Computer for testing
* Arduino IDE

## Software Requirements

* Arduino IDE
* DigiSpark ATTiny85 board support
* `DigiKeyboard.h` library
* Windows test environment
* Spanish keyboard layout for compatibility testing

## Development Environment

The payload adaptations were tested using:

* DigiSpark ATTiny85
* Arduino IDE
* Windows environment
* Spanish keyboard layout

## Usage

This repository is intended for controlled lab environments only.

Do not run these payloads on systems you do not own or do not have explicit permission to test.

Recommended testing setup:

```text
- Isolated virtual machine
- Disposable Windows test environment
- No personal accounts
- No sensitive data
- No production systems
- Explicit authorization
```

## Important Security Notice

This repository contains offensive security payloads.

Some payloads may simulate or perform actions commonly associated with Red Team operations, such as:

* Automated command execution
* Credential access simulation
* Privilege-related testing
* HID-based execution chains
* Remote shell behavior
* Payload delivery testing

They must only be used in:

* Personal labs
* Authorized penetration tests
* Red Team exercises
* Educational environments
* Systems where you have explicit permission

## Legal and Ethical Disclaimer

This project is provided for educational and authorized security testing purposes only.

The author of this fork does not condone unauthorized access, credential theft, persistence, phishing, malware deployment, or any activity performed against systems without explicit permission.

You are responsible for complying with all applicable laws, regulations, platform rules, and engagement scopes.

Use this repository only in environments where you are legally authorized to perform security testing.

## Upstream Project

Original project:

```text
https://github.com/MTK911/Attiny85
```

This repository is a fork with modifications focused on Spanish keyboard layout compatibility.

## References

DigiKeyboard implementation:

```text
https://github.com/digistump/DigistumpArduino/blob/master/digistump-avr/libraries/DigisparkKeyboard/DigiKeyboard.h
```

USB HID Usage Tables:

```text
https://usb.org/document-library/hid-usage-tables-17
```

Spanish keyboard layout mapping documentation:

```text
CHAR_MAPPING.md
```

## License

This project keeps the original upstream license.

Original license: GNU Lesser General Public License v3.0.

See the `LICENSE` file for details.

## Notice

This fork includes modifications by `bruhMomentFixer` focused on Spanish keyboard layout adaptation, testing, and documentation.

Original payloads and project structure come from the upstream `MTK911/Attiny85` repository.
