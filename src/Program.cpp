/*
 * Program.cpp
 *
 *  Reused from Trencher and developed by tuan-phong.ngo@it.uu.se for PERSIST tool
 *
 */

/*
 * ----------------------------------------------------------------------------
 * "THE JUICE-WARE LICENSE" (Revision 42):
 * <derevenetc@cs.uni-kl.de> wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a glass of juice in return.
 * ----------------------------------------------------------------------------
 */

#include "Program.h"

#include "Foreach.h"
#include "Thread.h"

namespace wmm {

Thread *Program::getThread(const std::string &name) {
	auto i = name2thread_.find(name);
	if (i == name2thread_.end()) {
		return NULL;
	} else {
		return i->second.get();
	}
}

Thread *Program::makeThread(const std::string &name) {
	auto &result = name2thread_[name];
	if (!result) {
		result.reset(new Thread(name));
		threads_.push_back(result.get());
	}
	return result.get();
}

void Program::addThread(Thread *thread) {
	threads_.push_back(thread);
}

const std::shared_ptr<Register> &Program::makeRegister(
		const std::string &name) {
	auto &result = name2register_[name];
	if (!result) {
		result.reset(new Register(name));
	}
	return result;
}

const std::shared_ptr<Constant> &Program::makeConstant(Domain value) {
	auto &result = value2constant_[value];
	if (!result) {
		result.reset(new Constant(value));
	}
	return result;
}

}
