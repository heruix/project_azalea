#ifndef __OBJECT_MGR_H
#define __OBJECT_MGR_H

#include "system_tree/system_tree_leaf.h"

void om_gen_init();

GEN_HANDLE om_store_object(ISystemTreeLeaf *object_ptr);
void om_correlate_object(ISystemTreeLeaf *object_ptr, GEN_HANDLE handle);
void om_decorrelate_object(GEN_HANDLE handle);
ISystemTreeLeaf *om_retrieve_object(GEN_HANDLE handle);
void om_remove_object(GEN_HANDLE handle);

#ifdef AZALEA_TEST_CODE
void test_only_reset_om();
#endif

#endif
