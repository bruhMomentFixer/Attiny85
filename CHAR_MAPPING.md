# Spanish Keyboard Layout Character Mapping

This document describes the character substitutions used in this fork to adapt selected DigiSpark ATTiny85 USB HID payloads from an English/US keyboard layout to a Spanish keyboard layout.

Most DigiSpark ATTiny85 HID payloads are written assuming an English/US keyboard layout. When those keystrokes are executed on a target system configured with a Spanish keyboard layout, some characters are interpreted differently.

This can break command syntax, PowerShell payloads, file paths, URLs, redirections, pipes, script blocks, and encoded command strings.

For the technical background about USB HID usage codes, `DigiKeyboard.h`, and keyboard layout interpretation, see the main [README.md](README.md).

## Scope

This mapping applies to the Spanish keyboard layout adaptations included in this fork.

The purpose of these changes is to improve compatibility when testing DigiSpark ATTiny85 HID payloads in controlled environments using Spanish keyboard layouts.

This document is intended for:

* Authorized Red Team labs
* Penetration testing practice
* HID payload compatibility testing
* Keyboard layout research
* Educational environments

## Technical Context

DigiSpark ATTiny85 payloads commonly use:

```cpp
DigiKeyboard.print();
DigiKeyboard.sendKeyStroke();
```

These functions do not directly send final text characters to the operating system. Instead, they emulate USB keyboard input using HID usage codes and modifier keys.

The target operating system then interprets those keystrokes according to its active keyboard layout.

Because of this, the same HID input may produce different characters depending on whether the target system uses an English/US keyboard layout or a Spanish keyboard layout.

For example, a payload written for an English/US layout may expect to type:

```text
/ - : = " | [ ] { }
```

But those characters may require different key combinations on a Spanish keyboard layout.

## Character Mapping Table

| Intended output character in the original EN/US payload | DigiKeyboard representation for Spanish layout     | Notes                                                                                                      |
| ------------------------------------------------------- | -------------------------------------------------- | ---------------------------------------------------------------------------------------------------------- |
| `/`                                                     | `&`                                                | Produces `/` on the tested Spanish layout. Commonly used in command switches and paths.                    |
| `-`                                                     | `/`                                                | Produces `-` on the tested Spanish layout. Commonly used in command parameters.                            |
| `:`                                                     | `>`                                                | Produces `:` on the tested Spanish layout. Commonly used in URLs, drive paths, and command syntax.         |
| `=`                                                     | `)`                                                | Produces `=` on the tested Spanish layout. Commonly used in assignments and parameters.                    |
| `"`                                                     | `@`                                                | Produces `"` on the tested Spanish layout. Used for quoted strings.                                        |
| `'`                                                     | `@` or replaced with double quotes                 | Depends on the CMD or PowerShell context. In some cases, single quotes can be replaced with double quotes. |
| `*`                                                     | `}`                                                | Produces `*` on the tested Spanish layout. Used in wildcard patterns.                                      |
| `(`                                                     | `*`                                                | Produces `(` on the tested Spanish layout. Used in PowerShell expressions and method calls.                |
| `)`                                                     | `(`                                                | Produces `)` on the tested Spanish layout. Used in PowerShell expressions and method calls.                |
| `;`                                                     | `<`                                                | Produces `;` on the tested Spanish layout. Used as a command separator in PowerShell payload strings.      |
| `&`                                                     | `^`                                                | Produces `&` on the tested Spanish layout. Used where `&` is required in shell or PowerShell syntax.       |
| `>`                                                     | `DigiKeyboard.sendKeyStroke(100, MOD_SHIFT_RIGHT)` | Used for output redirection.                                                                               |
| `\|`                                                    | `DigiKeyboard.sendKeyStroke(30, MOD_ALT_RIGHT)`    | Used for PowerShell pipes.                                                                                 |
| `[`                                                     | `DigiKeyboard.sendKeyStroke(47, MOD_ALT_RIGHT)`    | Used for PowerShell type notation, such as `[byte[]]`.                                                     |
| `]`                                                     | `DigiKeyboard.sendKeyStroke(48, MOD_ALT_RIGHT)`    | Used for PowerShell type notation, such as `[byte[]]`.                                                     |
| `{`                                                     | `DigiKeyboard.sendKeyStroke(52, MOD_ALT_RIGHT)`    | Used for PowerShell script blocks.                                                                         |
| `}`                                                     | `DigiKeyboard.sendKeyStroke(50, MOD_ALT_RIGHT)`    | Used for PowerShell script blocks.                                                                         |

## Practical Examples

### CMD command switches

Original EN/US payload string:

```text
cmd /k mode con: cols=15 lines=1
```

Spanish layout adaptation:

```text
cmd &k mode con> cols)15 lines)1
```

Explanation:

| Original character | Adapted character |
| ------------------ | ----------------- |
| `/`                | `&`               |
| `:`                | `>`               |
| `=`                | `)`               |

## PowerShell Parameters

Original EN/US payload string:

```text
powershell Select-String -Path *Wi*.xml -Pattern "keyMaterial"
```

Spanish layout adaptation:

```text
powershell Select/String /Path }Wi}.xml /Pattern @keyMaterial@
```

Explanation:

| Original character | Adapted character |
| ------------------ | ----------------- |
| `-`                | `/`               |
| `*`                | `}`               |
| `"`                | `@`               |

## Output Redirection

For the `>` character, explicit HID keystroke generation is used instead of direct printing:

```cpp
DigiKeyboard.sendKeyStroke(100, MOD_SHIFT_RIGHT);
```

This is useful when a command needs output redirection.

Example intended output:

```text
> output.txt
```

## PowerShell Pipe

For the `|` character, explicit HID keystroke generation is used:

```cpp
DigiKeyboard.sendKeyStroke(30, MOD_ALT_RIGHT);
```

This is useful for PowerShell pipelines.

Example intended output:

```text
command1 | command2
```

## PowerShell Square Brackets

Square brackets are commonly used in PowerShell type notation.

For `[`:

```cpp
DigiKeyboard.sendKeyStroke(47, MOD_ALT_RIGHT);
```

For `]`:

```cpp
DigiKeyboard.sendKeyStroke(48, MOD_ALT_RIGHT);
```

Example intended output:

```text
[byte[]]
```

## PowerShell Curly Braces

Curly braces are commonly used in PowerShell script blocks.

For `{`:

```cpp
DigiKeyboard.sendKeyStroke(52, MOD_ALT_RIGHT);
```

For `}`:

```cpp
DigiKeyboard.sendKeyStroke(50, MOD_ALT_RIGHT);
```

Example intended output:

```text
{ command }
```

## Why This Mapping Is Needed

DigiSpark ATTiny85 payloads use USB HID keyboard emulation.

The device sends key usage codes, not final text characters. The final character depends on the keyboard layout configured on the target operating system.

This means that payloads written for English/US layouts may fail on Spanish layouts because the following characters may be produced incorrectly:

```text
/ \ | @ # ~ " ' : ; { } [ ] ( ) = + - _
```

Incorrect character output can break:

* CMD commands
* PowerShell commands
* File paths
* URLs
* Webhook URLs
* Redirections
* Pipes
* Encoded commands
* Script blocks
* Download commands
* Payload execution syntax

## Direct Character Replacement vs Explicit Keystrokes

There are two main adaptation methods used in this fork.

### 1. Direct string replacement

Some characters can be adapted directly inside `DigiKeyboard.print()` strings.

Example:

```cpp
DigiKeyboard.print("cmd &k mode con> cols)15 lines)1");
```

This is used when replacing characters inside a printable string is enough to produce the intended output on the Spanish layout.

### 2. Explicit HID keystrokes

Some characters are more reliable when generated with explicit `DigiKeyboard.sendKeyStroke()` calls.

Example:

```cpp
DigiKeyboard.sendKeyStroke(30, MOD_ALT_RIGHT); // |
```

This is used for characters such as pipes, brackets, braces, and redirection symbols.

## Reference: DigiKeyboard Modifiers

The `DigiKeyboard.h` library defines modifier keys as bit flags.

Examples:

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

These modifiers can be combined with HID keyboard usage IDs to generate specific key combinations.

## Reference: HID Usage IDs

Keyboard keys are represented using HID usage IDs.

Examples from `DigiKeyboard.h`:

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

These usage IDs are based on the USB HID Usage Tables specification, specifically the Keyboard/Keypad Page.

Official reference:

```text
https://usb.org/document-library/hid-usage-tables-17
```

DigiKeyboard reference implementation:

```text
https://github.com/digistump/DigistumpArduino/blob/master/digistump-avr/libraries/DigisparkKeyboard/DigiKeyboard.h
```

## Limitations

This mapping is based on the tested Spanish keyboard layout environment used during the adaptation process.

Different systems may require additional adjustments depending on:

* Operating system
* Keyboard layout variant
* Language settings
* DigiKeyboard version
* Target shell
* PowerShell version
* CMD behavior
* Locale configuration

Always test payload behavior in an isolated and authorized lab environment before using it in any Red Team or penetration testing engagement.

## Notes

This mapping was created by comparing the original payloads with the Spanish-adapted versions included in this fork.

Some substitutions are handled by replacing printable characters directly inside strings.

Other characters are generated with explicit `DigiKeyboard.sendKeyStroke()` calls because they are more reliable than direct printing on a Spanish keyboard layout.

## Legal and Ethical Notice

This document is provided for educational and authorized security testing purposes only.

The mapping is intended to help understand and adapt USB HID payload behavior across keyboard layouts.

Do not use these payloads or adaptations against systems you do not own or do not have explicit permission to test.
