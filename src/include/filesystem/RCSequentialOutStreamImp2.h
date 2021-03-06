/********************************************************************************
 *  版权所有(C)2008,2009,2010，好压软件工作室，保留所有权利。                   *
 ********************************************************************************
 *  作者    : HaoZip                                                            *
 *  版本    : 1.7                                                               *
 *  联系方式: haozip@gmail.com                                                  *
 *  官方网站: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCSequentialOutStreamImp2_h_
#define __RCSequentialOutStreamImp2_h_ 1

#include "interface/IStream.h"
#include "interface/IUnknownImpl.h"

BEGIN_NAMESPACE_RCZIP

class RCSequentialOutStreamImp2:
    public IUnknownImpl<ISequentialOutStream>
{
public:

    /** 默认构造函数
    */
    RCSequentialOutStreamImp2() ;
    
    /** 默认析构函数
    */
    ~RCSequentialOutStreamImp2() ;
    
public:
    
    /** 初始化
    @param [in] buffer 缓冲区地址
    @param [in] size 缓冲区大小
    */
    void Init(byte_t* buffer, size_t size) ;
    
    /** 获取当前数据指针
    @return 返回当前数据指针位置
    */
    size_t GetPos() const ;
    
    /** 写数据  
    @param [in] data 存放数据的缓冲区
    @param [in] size 缓冲区大小
    @param [out] processedSize 实际读取的大小
    @return 成功返回 RC_S_OK, 失败返回错误码
    */
    virtual HResult Write(const void* data, uint32_t size, uint32_t* processedSize) ;
    
private:
    
    /** 缓冲区地址
    */
    byte_t* m_buffer ;
    
    /** 缓冲区长度
    */
    size_t m_size;
    
    /** 当前数据位置
    */
    size_t m_pos;
};

END_NAMESPACE_RCZIP

#endif //__RCSequentialOutStreamImp2_h_
