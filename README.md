# arm64

## HWCAP

User application can query CPU features available to it through the HWCAP mechanism.

See documentation at kernel.org (available [since v4.15-rc1][1]) for usage example as well as a complete list supported flags: [Documentation/arm64/elf_hwcaps.txt][1]

This interface has been available in arm64 port of Linux since [v3.7][3]:
```
commit f668cd1673aa2e645ae98b65c4ffb9dae2c9ac17
Author: Catalin Marinas <catalin.marinas@arm.com>
Date:   Mon Mar 5 11:49:30 2012 +0000

    arm64: ELF definitions

    This patch adds definitions for the ELF format, including personality
    personality setting and EXEC_PAGESIZE. The are only two hwcap
    definitions for 64-bit applications - HWCAP_FP and HWCAP_ASIMD.
```

[1]: https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/tree/Documentation/arm64/elf_hwcaps.txt
[2]: https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id=611a7bc74ed2dcbab6693c20bb534cfcf15f9d1d
[3]: https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id=f668cd1673aa2e645ae98b65c4ffb9dae2c9ac17
