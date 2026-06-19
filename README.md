# DigiSpark ATTiny85 HID Payloads — Spanish Keyboard Layout Adaptation

> Fork of `MTK911/Attiny85` focused on testing and adapting DigiSpark ATTiny85 USB HID payloads for Spanish keyboard layouts.

## Overview

This repository is a fork of the original `MTK911/Attiny85` project, which contains DigiSpark ATTiny85 USB HID payloads inspired by Rubber Ducky-style attacks.

The purpose of this fork is to document, test, and adapt selected payloads so they work correctly on systems using a Spanish keyboard layout.

DigiSpark ATTiny85 boards can emulate a USB keyboard through the `DigiKeyboard.h` library. This allows them to send automated keystrokes to a target machine when plugged in as a USB device.

This type of project is useful for:

* Red Team training
* Penetration testing labs
* HID attack simulation
* Payload testing in controlled environments
* Keyboard layout compatibility research
* Understanding USB HID-based attack techniques

## My Contributions

This fork focuses on Spanish keyboard layout compatibility.

Main changes include:

* Adaptation of selected payloads for Spanish keyboard layouts.
* Testing of DigiKeyboard keystroke sequences on Spanish keyboard configurations.
* Replacement or modification of characters that behave differently between English and Spanish layouts.
* Documentation of payload behavior and compatibility issues.
* Cleanup and organization of modified payload versions.

Modified payload categories include:

* Wi-Fi credential extraction payload adaptation
* Instant shell payload adaptation

The original payload logic belongs to the upstream project. This fork mainly documents and adapts selected payloads for keyboard layout compatibility.

## Why Keyboard Layout Adaptation Matters

Many USB HID payloads are written assuming an English US keyboard layout.

When executed on a Spanish keyboard layout, some characters may be typed incorrectly, especially:

```text
/ \ | @ # ~ " ' : ; { } [ ] ( ) = + - _
```

This can break commands, PowerShell syntax, URLs, paths, payload strings, and shell commands.

This fork experiments with adapting those keystrokes so the payloads behave correctly on Spanish keyboard layouts.

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

Modified payloads are kept inside their corresponding payload folders.

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

The payloads were tested using:

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
```

## Important Notes

This repository contains offensive security payloads.

Some payloads may simulate or perform actions commonly associated with Red Team operations, such as command execution, credential access simulation, privilege-related testing, or remote shell behavior.

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

## License

This project keeps the original upstream license.

Original license: GNU Lesser General Public License v3.0.

See the `LICENSE` file for details.

## Notice

This fork includes modifications by `bruhMomentFixer` focused on Spanish keyboard layout adaptation and testing.

Original payloads and project structure come from the upstream `MTK911/Attiny85` repository.
