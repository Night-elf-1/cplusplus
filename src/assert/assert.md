# assert

**`assert` 是 C 和 C++ 中的一个宏，用于在程序中进行调试和验证。它的主要作用是检查程序中的条件是否为真，如果条件为假，程序会输出错误信息并终止执行。`assert` 通常用于捕捉程序中的逻辑错误和不一致性，帮助开发者在开发和测试阶段发现问题。**

## 基本语法

```
#include <cassert>

assert(condition);
```

`condition` 是一个表达式，如果这个表达式的值为假（即 `false`），则 `assert` 会触发错误。

## 工作原理

1. **条件检查**：当程序运行到 `assert` 语句时，它会检查给定的条件。
2. **触发错误**：如果条件为假，`assert` 会输出一条错误消息，通常包括失败的条件、文件名和行号，然后调用 `abort()` 函数终止程序。
3. **无效条件**：如果条件为真，程序将继续执行，`assert` 不会产生任何影响。