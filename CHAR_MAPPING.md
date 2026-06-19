\# Spanish Keyboard Layout Character Mapping



This table documents the character substitutions used when adapting DigiSpark ATTiny85 HID payloads from an English/US keyboard layout to a Spanish keyboard layout.



When `DigiKeyboard.print()` sends characters, the target operating system interprets the keystrokes according to its configured keyboard layout. Because many HID payloads are written assuming an English/US layout, some symbols are typed incorrectly on Spanish keyboards.



The following table shows the substitutions observed in the Spanish-adapted payloads.



| Intended character in EN/US payload | Character or method used for ES layout             | Example / Notes                                                                           |

| ----------------------------------- | -------------------------------------------------- | ----------------------------------------------------------------------------------------- |

| `/`                                 | `\&`                                                | Used in paths, command switches and URLs. Example: `/k` → `\&k`                            |

| `-`                                 | `/`                                                | Used in command parameters. Example: `-Path` → `/Path`                                    |

| `:`                                 | `>`                                                | Used in commands and URLs. Example: `https:` → `https>`                                   |

| `=`                                 | `)`                                                | Used in assignments and parameters. Example: `key=clear` → `key)clear`                    |

| `"`                                 | `@`                                                | Used to produce double quotes in quoted command strings.                                  |

| `'`                                 | `@` or replaced with double quotes                 | In PowerShell, single quotes can often be replaced by double quotes depending on context. |

| `\*`                                 | `}`                                                | Used in wildcard patterns. Example: `\*Wi\*.xml` → `}Wi}.xml`                               |

| `(`                                 | `\*`                                                | Used in PowerShell expressions and method calls.                                          |

| `)`                                 | `(`                                                | Used in PowerShell expressions and method calls.                                          |

| `;`                                 | `<`                                                | Used as a command separator in PowerShell payload strings.                                |

| `\&`                                 | `^`                                                | Used where `\&` is required in shell/PowerShell syntax.                                    |

| `>`                                 | `DigiKeyboard.sendKeyStroke(100, MOD\_SHIFT\_RIGHT)` | Used for output redirection, for example before `Wi-Fi-PASS`.                             |

| `\\|`                                | `DigiKeyboard.sendKeyStroke(30, MOD\_ALT\_RIGHT)`    | Used for PowerShell pipes.                                                                |

| `\[`                                 | `DigiKeyboard.sendKeyStroke(47, MOD\_ALT\_RIGHT)`    | Used for PowerShell type notation, e.g. `\[byte\[]]`.                                       |

| `]`                                 | `DigiKeyboard.sendKeyStroke(48, MOD\_ALT\_RIGHT)`    | Used for PowerShell type notation, e.g. `\[byte\[]]`.                                       |

| `{`                                 | `DigiKeyboard.sendKeyStroke(52, MOD\_ALT\_RIGHT)`    | Used for PowerShell script blocks.                                                        |

| `}`                                 | `DigiKeyboard.sendKeyStroke(50, MOD\_ALT\_RIGHT)`    | Used for PowerShell script blocks.                                                        |



\## Examples



| EN/US original                                                                | ES-adapted version                                                                                                                   |

| ----------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------ |

| `cmd /k mode con: cols=15 lines=1`                                            | `cmd \&k mode con> cols)15 lines)1`                                                                                                   |

| `netsh wlan export profile key=clear`                                         | `netsh wlan export profile key)clear`                                                                                                |

| `powershell Select-String -Path \*Wi\*.xml -Pattern "keyMaterial" > Wi-Fi-PASS` | `powershell Select/String /Path }Wi}.xml /Pattern @keyMaterial@` + `DigiKeyboard.sendKeyStroke(100, MOD\_SHIFT\_RIGHT)` + `Wi/Fi/PASS` |

| `del Wi-\* /s /f /q`                                                           | `del Wi/} \&s \&f \&q`                                                                                                                  |



\## Notes



Some characters are easier to generate with explicit key strokes instead of `DigiKeyboard.print()`.



For example, on a Spanish keyboard layout:



```cpp

DigiKeyboard.sendKeyStroke(100, MOD\_SHIFT\_RIGHT);

```



is used to generate:



```text

>

```



And:



```cpp

DigiKeyboard.sendKeyStroke(30, MOD\_ALT\_RIGHT);

```



is used to generate:



```text

|

```



This is especially useful for PowerShell syntax, command redirection, and script blocks.



\## Scope



This mapping was created from the Spanish keyboard layout adaptations included in this fork. It is intended for authorized Red Team labs, penetration testing practice, and HID payload compatibility testing.



