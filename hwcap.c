/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2017 Zi Shen Lim <zlim.lnx@gmail.com>
 *
 * arm64 HWCAP example
 *
 * gcc -o hwcap hwcap.c
 */
#include <stdio.h>
#include <sys/auxv.h>
#include "hwcap.h"

#define has(CAP, hwcap) !!((hwcap) & HWCAP_##CAP)
#define pr(CAP, hwcap) printf("%10s = %d\n", #CAP, has(CAP, hwcap))

int main(void)
{
	unsigned long hwcaps = getauxval(AT_HWCAP);
	printf("HWCAP = 0x%lx\n", hwcaps);

	pr(FP, hwcaps);
	pr(ASIMD, hwcaps);
	pr(EVTSTRM, hwcaps);
	pr(AES, hwcaps);
	pr(PMULL, hwcaps);
	pr(SHA1, hwcaps);
	pr(SHA2, hwcaps);
	pr(CRC32, hwcaps);
	pr(ATOMICS, hwcaps);
	pr(FPHP, hwcaps);
	pr(ASIMDHP, hwcaps);
	pr(CPUID, hwcaps);
	pr(ASIMDRDM, hwcaps);
	pr(JSCVT, hwcaps);
	pr(FCMA, hwcaps);
	pr(LRCPC, hwcaps);
	pr(DCPOP, hwcaps);
	pr(SHA3, hwcaps);
	pr(SM3, hwcaps);
	pr(SM4, hwcaps);
	pr(ASIMDDP, hwcaps);
	pr(SHA512, hwcaps);
	pr(SVE, hwcaps);

	return 0;
}
