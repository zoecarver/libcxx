//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <memory>

#include <memory>
#include <cassert>

struct A {
	int a;
	float b;

	A(int a, float b): a(a), b(b) { }
};

int main(int, char**)
{
	std::allocator<A> alloc;
	auto a = std::make_obj_using_allocator<A>(alloc, 10, 5.0);

	assert(a.a == 10);
	assert(a.b == 5.0);

	return 0;
}
