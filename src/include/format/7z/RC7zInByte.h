/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RC7zInByte_h_
#define __RC7zInByte_h_ 1

#include "base/RCNonCopyable.h"
#include "base/RCString.h"
#include "format/7z/RC7zDefs.h"
#include "base/RCSmartPtr.h"

BEGIN_NAMESPACE_RCZIP

class RC7zInByte:
    private RCNonCopyable
{
public:

    /** Ĭ�Ϲ��캯��
    */
    RC7zInByte() ;
    
    /** Ĭ����������
    */
    ~RC7zInByte() ;
    
public:

    /** ��ʼ��
    @param [in] buffer �ڴ滺��
    @param [in] size �ڴ��С
    */
    void Init(const byte_t* buffer, size_t size) ;

    /** ��һ���ֽ�
    @return ����һ���ֽ�
    */
    byte_t ReadByte() ;

    /** ���ֽ�
    @param [out] data ���ض�ȡ������
    @param [in] size ��ȡ�Ĵ�С
    */
    void ReadBytes(byte_t* data, size_t size) ;

    /** ����
    @param [in] size �����Ĵ�С
    */
    void SkipData(uint64_t size) ;

    /** ����
    */
    void SkipData() ;

    /** ����
    @return ����64λ�޷�������
    */
    uint64_t ReadNumber() ;

    /** ����
    @return ����RC7zNum
    */
    RC7zNum ReadNum() ;

    /** ���ĸ��ֽ�ת��32λ�޷�������
    @return ����32λ�޷�������
    */
    uint32_t ReadUInt32() ;

    /** ���˸��ֽ�ת��64λ�޷�������
    @return ����64λ�޷�������
    */
    uint64_t ReadUInt64() ;

    /** ���ַ���
    @param [in] s �����ַ���
    */
    void ReadString(RCString& s) ;
    
public:

    /** ��ȡ��ǰλ��ƫ��
    @return ���ص�ǰλ��ƫ��
    */
    size_t GetPos() const ;
    
private:

    /** ��ǰλ��
    */
    size_t m_pos ;

    /** �ڴ�
    */
    const byte_t* m_buffer;

    /** �ڴ��С
    */
    size_t m_size ;
};

/** RC7zInByte����ָ��
*/
typedef RCSharedPtr<RC7zInByte> RC7zInBytePtr ;

END_NAMESPACE_RCZIP

#endif //__RC7zInByte_h_
