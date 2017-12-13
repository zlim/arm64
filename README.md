# arm64

## HWCAP

User application can query CPU features available to it through the HWCAP mechanism.

See documentation at kernel.org (available [since v4.15-rc1][1]) for usage example as well as a complete list of supported flags: [Documentation/arm64/elf_hwcaps.txt][1]

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

An example application `hwcap` is provided in this [repository](https://github.com/zlim/arm64/commit/8701c3b93ad28172b8b32f742ce5cb04bb426c8b).

[1]: https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/tree/Documentation/arm64/elf_hwcaps.txt
[2]: https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id=611a7bc74ed2dcbab6693c20bb534cfcf15f9d1d
[3]: https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id=f668cd1673aa2e645ae98b65c4ffb9dae2c9ac17

## CPUID

[AArch64][4] defines CPU ID registers that can be queried by kernel (EL1).
Thanks to MRS emulation support in kernel, a subset of these registers can be accessed by user application (EL0) as well.

See documentation at kernel.org for detailed description of this feature as well as usage example: [Documentation/arm64/cpu-feature-registers.txt][5]

This feature is available in arm64 port of Linux since [v4.11][6]:
````
commit 77c97b4ee21290f5f083173d957843b615abbff2
Author: Suzuki K Poulose <suzuki.poulose@arm.com>
Date:   Mon Jan 9 17:28:31 2017 +0000

    arm64: cpufeature: Expose CPUID registers by emulation

    This patch adds the hook for emulating MRS instruction to
    export the 'user visible' value of supported system registers.
    We emulate only the following id space for system registers:

     Op0=3, Op1=0, CRn=0, CRm=[0, 4-7]

    The rest will fall back to SIGILL. This capability is also
    advertised via a new HWCAP_CPUID.
````

[4]: https://developer.arm.com/products/architecture/a-profile/docs/ddi0487/latest/arm-architecture-reference-manual-armv8-for-armv8-a-architecture-profile
[5]: https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/tree/Documentation/arm64/cpu-feature-registers.txt
[6]: https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id=77c97b4ee21290f5f083173d957843b615abbff2
