#ifndef KJSON_KJLOOKUP_H_
#define KJSON_KJLOOKUP_H_

// kjLookup.h — Orion-LD fork local compatibility copy
// Source: kjson library (https://gitlab.com/kzangeli/kjson.git, release/0.14.2)
// Fix: added extern "C" wrapper — the kjson library exports kjLookup as
// a C symbol, but Orion C++ code was generating C++ mangled symbol references
// without the extern "C" guard in the header. This local copy applies the
// fix so the build works with the standard kjson installation.
// Classification: BUILD_ABI_COMPATIBILITY — no behavioral change.
#include "kjson/KjNode.h"               // KjNode
extern "C" {
    KjNode* kjLookup(KjNode* container, const char* name);
    KjNode* kjLookupWithStrcmp(KjNode* container, char* name);
#ifdef USE_CHAR_SUM
    KjNode* kjLookupWithCharSum(KjNode* container, char* name);
#endif
}

#endif  // KJSON_KJLOOKUP_H_
