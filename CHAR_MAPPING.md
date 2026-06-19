# Spanish Keyboard Layout Character Mapping

This document describes the character substitutions used in this fork to adapt selected DigiSpark ATTiny85 USB HID payloads from an English/US keyboard layout to a Spanish keyboard layout.

Most USB HID payloads are written assuming an English/US keyboard layout. When those keystrokes are executed on a target system configured with a Spanish keyboard layout, some characters are interpreted differently. This can break command syntax, PowerShell payloads, file paths, URLs, redirections, pipes, and script blocks.

The goal of this document is to keep track of the character mapping used during the adaptation process.

## Scope

This mapping applies to the Spanish keyboard layout adaptations included in this fork.

The purpose of these changes is to improve compatibility when testing DigiSpark ATTiny85 HID payloads in controlled environments using Spanish keyboard layouts.

This document is intended for:

* Authorized Red Team labs
* Penetration testing practice
* HID payload compatibility testing
* Keyboard layout research
* Educational environments

## Character Mapping Table

| Intended character in EN/US payload | ES layout adaptation                               | Notes                                                                                                   |
| ----------------------------------- | -------------------------------------------------- | ------------------------------------------------------------------------------------------------------- |
| `/`                                 | `&`                                                | Commonly used in command switches and paths. Example: `/k` becomes `&k`.                                |
| `-`                                 | `/`                                                | Commonly used in command parameters. Example: `-Path` becomes `/Path`.                                  |
| `:`                                 | `>`                                                | Commonly used in URLs, drive paths, and command syntax. Example: `https:` becomes `https>`.             |
| `=`                                 | `)`                                                | Commonly used in assignments and parameters. Example: `key=clear` becomes `key)clear`.                  |
| `"`                                 | `@`                                                | Used to generate double quotes in quoted command strings.                                               |
| `'`                                 | `@` or replaced with double quotes                 | In some PowerShell contexts, single quotes can be replaced with double quotes depending on the command. |
| `*`                                 | `}`                                                | Used in wildcard expressions. Example: `*Wi*.xml` becomes `}Wi}.xml`.                                   |
| `(`                                 | `*`                                                | Used in PowerShell expressions and method calls.                                                        |
| `)`                                 | `(`                                                | Used in PowerShell expressions and method calls.                                                        |
| `;`                                 | `<`                                                | Used as a command separator in PowerShell strings.                                                      |
| `&`                                 | `^`                                                | Used where `&` is required by shell or PowerShell syntax.                                               |
| `>`                                 | `DigiKeyboard.sendKeyStroke(100, MOD_SHIFT_RIGHT)` | Used for output redirection.                                                                            |
| `\|`                                | `DigiKeyboard.sendKeyStroke(30, MOD_ALT_RIGHT)`    | Used for PowerShell pipes.                                                                              |
| `[`                                 | `DigiKeyboard.sendKeyStroke(47, MOD_ALT_RIGHT)`    | Used for PowerShell type notation, such as `[byte[]]`.                                                  |
| `]`                                 | `DigiKeyboard.sendKeyStroke(48, MOD_ALT_RIGHT)`    | Used for PowerShell type notation, such as `[byte[]]`.                                                  |
| `{`                                 | `DigiKeyboard.sendKeyStroke(52, MOD_ALT_RIGHT)`    | Used for PowerShell script blocks.                                                                      |
| `}`                                 | `DigiKeyboard.sendKeyStroke(50, MOD_ALT_RIGHT)`    | Used for PowerShell script blocks.                                                                      |

## Examples

### Command Switches

English/US layout payload:

```text
cmd /k mode con: cols=15 lines=1
```

Spanish layout adaptation:

```text
cmd &k mode con> cols)15 lines)1
```

### PowerShell Parameters

English/US layout payload:

```text
powershell Select-String -Path *Wi*.xml -Pattern "keyMaterial"
```

Spanish layout adaptation:

```text
powershell Select/String /Path }Wi}.xml /Pattern @keyMaterial@
```

### Output Redirection

For the `>` character, explicit key stroke generation is used instead of `DigiKeyboard.print()`:

```cpp
DigiKeyboard.sendKeyStroke(100, MOD_SHIFT_RIGHT);
```

This is used when a command needs output redirection.

### PowerShell Pipe

For the `|` character, explicit key stroke generation is used:

```cpp
DigiKeyboard.sendKeyStroke(30, MOD_ALT_RIGHT);
```

This is useful for PowerShell pipelines.

### PowerShell Brackets

For square brackets used in PowerShell type notation:

```cpp
DigiKeyboard.sendKeyStroke(47, MOD_ALT_RIGHT); // [
DigiKeyboard.sendKeyStroke(48, MOD_ALT_RIGHT); // ]
```

Example use case:

```text
[byte[]]
```

### PowerShell Script Blocks

For curly braces used in PowerShell script blocks:

```cpp
DigiKeyboard.sendKeyStroke(52, MOD_ALT_RIGHT); // {
DigiKeyboard.sendKeyStroke(50, MOD_ALT_RIGHT); // }
```

## Why This Mapping Is Needed

DigiSpark ATTiny85 payloads use `DigiKeyboard.print()` and `DigiKeyboard.sendKeyStroke()` to emulate keyboard input.

However, the target operating system interprets those keystrokes according to its active keyboard layout. A payload written for an English/US keyboard may therefore type incorrect characters on a Spanish keyboard layout.

This is especially relevant for characters such as:

```text
/ \ | @ # ~ " ' : ; { } [ ] ( ) = + - _
```

Incorrect character output can break:

* PowerShell commands
* CMD commands
* File paths
* URLs
* Webhook URLs
* Redirections
* Pipes
* Encoded commands
* Script blocks
* Download commands
* Payload execution syntax

## Notes

This mapping was created by comparing the original payloads with the Spanish-adapted versions included in this fork.

Some substitutions are handled by replacing printable characters directly inside strings.

Other characters are generated with explicit `DigiKeyboard.sendKeyStroke()` calls because they are more reliable than direct printing on a Spanish keyboard layout.

## Limitations

This mapping is based on the tested Spanish keyboard layout environment used during the adaptation process.

Different systems, keyboard configurations, language settings, or DigiKeyboard versions may require additional adjustments.

Always test payload behavior in an isolated and authorized lab environment before using it in any Red Team or penetration testing engagement.

## Legal and Ethical Notice

This document is provided for educational and authorized security testing purposes only.

The mapping is intended to help understand and adapt USB HID payload behavior across keyboard layouts.

Do not use these payloads or adaptations against systems you do not own or do not have explicit permission to test.
