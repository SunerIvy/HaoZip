/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCRar3TempFilter_h_
#define __RCRar3TempFilter_h_ 1

#include "RCRar3VmDefs.h"

BEGIN_NAMESPACE_RCZIP

class RCRar3TempFilter:
    public RCRar3ProgramInitState
{
public:

    uint32_t BlockStart;
    uint32_t BlockSize;
    uint32_t ExecCount;
    bool NextWindow;  
    uint32_t FilterIndex;
    
public:
    RCRar3TempFilter():
        BlockStart(0),
        BlockSize(0),
        ExecCount(0),
        NextWindow(false),
        FilterIndex(0)
    {
    }
};

END_NAMESPACE_RCZIP

#endif //__RCRar3TempFilter_h_
