/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCCodecsDefs_h_
#define __RCCodecsDefs_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

#define RC_CREATE_CODECS_FUN_NAME   "CreateCodecs"
#define RC_CREATE_CODECS_FUN_TNAME  _T("CreateCodecs")

extern "C"{
    /** �����������������, ���ض�������ΪICompressCodecsInfo�ӿ�ָ��
    @param [out] outObject ����ICompressCodecsInfo�ӿ�ָ�룬�������ü�����1
    @return ����ɹ��򷵻�RC_S_OK�����򷵻ش����
    */
    typedef HResult (*RCCreateCodecsFunction)(void** outObject) ;
}

END_NAMESPACE_RCZIP

#endif //__RCCodecsDefs_h_
