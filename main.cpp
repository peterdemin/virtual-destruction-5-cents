#include <iostream>

// -- leak detection ----------------------------------------------------------
#ifdef _DEBUG   
// http://msdn.microsoft.com/en-us/library/e5ewb1h3(v=VS.80).aspx
#define _CRTDBG_MAP_ALLOC   
#include <stdlib.h>
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

#include "scenario1.h"
#include "scenario2.h"
#include "scenario3.h"
#include "scenario4.h"
#include "scenario5.h"

int main() {
    #ifdef _DEBUG
    _CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
    //_CrtSetBreakAlloc( 670 );
    #endif

    scenario1::run_all();
    scenario2::run_all();
    scenario3::run_all();
    scenario5::run_all();
    scenario4::run_all();
    return 0;
};
