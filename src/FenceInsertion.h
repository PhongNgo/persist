/*
 * Fenceinsertion.h
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

#pragma once

#include <vector>

namespace wmm {

class Program;
class Thread;
class State;

typedef std::pair<Thread *, State *> Fence;
typedef std::vector<Fence> FenceSet;

FenceSet preComputeFences(const Program &program, bool searchForTdrOnly);

FenceSet preComputeFenceAbstraction(const Program &program, bool searchForTdrOnly, int loopNum, int fenceType);

}
