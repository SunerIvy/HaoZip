/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCIIDDefs_h_
#define __RCIIDDefs_h_ 1

#include "base/RCDefs.h"

BEGIN_NAMESPACE_RCZIP

/** Unknown�Ľӿ�ID��ʼֵ
*/
#define IID_IUNKNOWN_BASE   (0)

/** ����صĽӿ�ID��ʼֵ
*/
#define IID_ISTREAM_BASE    (1024*1)

/** ����������صĽӿ�ID��ʼֵ
*/
#define IID_IPROGRESS_BASE  (1024*2)

/** ������صĽӿ�ID��ʼֵ
*/
#define IID_IPASSWORD_BASE  (1024*3)

/** ѹ���������صĽӿ�ID��ʼֵ
*/
#define IID_ICODER_BASE     (1024*4)

/** �ļ�������صĽӿ�ID��ʼֵ
*/
#define IID_IARCHIVE_BASE   (1024*5)

/** ����ģʽ��صĽӿ�ID��ʼֵ
*/
#define IID_IOVERWRITE_BASE (1024*6)

END_NAMESPACE_RCZIP

#endif //__RCIIDDefs_h_
