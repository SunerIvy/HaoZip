/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCFile_h_
#define __RCFile_h_ 1

#include "base/RCNonCopyable.h"
#include "base/RCString.h"
#include "filesystem/RCFileDefs.h"

BEGIN_NAMESPACE_RCZIP

/** �ļ�����Ȩ��
*/
typedef enum eRCDesiredAccess
{
    RC_GENERIC_READ,
    RC_GENERIC_WRITE,
    RC_GENERIC_EXECUTE
}RC_DESIRED_ACCESS;

/** �ļ�����ģʽ
*/
typedef enum eRCShareMode
{
    RC_SHARE_READ,
    RC_SHARE_WRITE,
    RC_SHARE_DELETE,
}RC_SHARE_MODE;

/** �ļ�����������
*/
typedef enum eRCCreationDisposition
{
    RC_CREATE_ALWAYS,
    RC_CREATE_NEW,
    RC_OPEN_ALWAYS,
    RC_OPEN_EXISTING
}RC_CREATION_DISPOSITION;

/** �ļ���־������
*/
typedef enum eRCFlagsAndAttributes
{
    RC_ATTRIBUTE_ARCHIVE,
    RC_ATTRIBUTE_NORMAL,
    RC_ATTRIBUTE_READONLY,
    RC_FLAG_DELETE_ON_CLOSE,
    RC_FLAG_NO_BUFFERING,
    RC_FLAG_WRITE_THROUGH
}RC_FLAGS_AND_ATTRIBUTES ;

/** �ļ��ƶ�ģʽ
*/
typedef enum eRCMoveMethod
{
    RC_FILE_BEGIN,
    RC_FILE_CURRENT,
    RC_FILE_END
}RC_MOVE_METHOD ;

/** �ļ�������֧��32λ��64λ�ļ�ϵͳ 
*/
class RCFile:
    private RCNonCopyable
{
public:
    
    /** Ĭ�Ϲ��캯��
    */
    RCFile();
    
    /** Ĭ����������
    */
    ~RCFile();
    
public:
    
    /** ��������ļ�
    @param [in] rcsFileName �ļ���
    @param [in] rdaDesiredAccess ����Ȩ��
    @param [in] rsdShareMode ����ģʽ
    @param [in] rcdCreationDisposition ��������
    @param [in] rfaFlagsAndAttributes �ļ���־������
    @return �ɹ�����true, ���򷵻�false
    */
    bool Create(const RCString& rcsFileName,
                RC_DESIRED_ACCESS rdaDesiredAccess,
                RC_SHARE_MODE rsdShareMode,
                RC_CREATION_DISPOSITION rcdCreationDisposition,
                RC_FLAGS_AND_ATTRIBUTES rfaFlagsAndAttributes );
    
    /** ���ļ�
    @param [out] pData �ļ����ݻ���
    @param [in]  u32Size ��ȡ�Ĵ�С
    @param [out] u32ProcessedSize ʵ�ʶ����Ĵ�С
    @return �ɹ�����true, ���򷵻�false
    */
    bool Read(void* pData, uint32_t u32Size, uint32_t& u32ProcessedSize);
    
    /** д�ļ�
    @param [in]  pData ���ݴ���
    @param [in]  u32Size д��Ĵ�С
    @param [out] u32ProcessedSize ʵ��д��Ĵ�С
    @return �ɹ�����true, ���򷵻�false
    */
    bool Write(const void* pData, uint32_t u32Size, uint32_t& u32ProcessedSize);
    
    /** �ر��ļ�
    @return �ɹ�����true, ���򷵻�false
    */
    bool Close();
    
public:
    
    /** ����ļ�ָ��λ��
    @param [out] u64Position �ļ�ָ��λ��
    @return �ɹ�����true, ���򷵻�false
    */
    bool GetPosition(uint64_t& u64Position) const;
    
    /** ����ļ���С
    @param [out] u64Size �ļ���С
    @return �ɹ�����true, ���򷵻�false
    */
    bool GetSize(uint64_t& u64Size) const;
    
    /** �ƶ��ļ�ָ��
    @param [in] n64DistanceToMove �ƶ����ֽ���
    @param [in] rcmdMoveMethod �ƶ�ģʽ
    @param [out] u64NewPosition �ƶ�������λ��
    @return �ɹ�����true, ���򷵻�false
    */
    bool Seek(int64_t n64DistanceToMove, RC_MOVE_METHOD rcmdMoveMethod, uint64_t& u64NewPosition) const;
    
    /** �ƶ��ļ�ָ�뵽�ļ�ͷ
    @return �ɹ�����true, ���򷵻�false
    */
    bool SeekBeginOfFile();
    
    /** �ƶ��ļ�ָ�뵽�ļ�β
    @param [in] u64NewPosition �ƶ�������λ��
    @return �ɹ�����true, ���򷵻�false
    */
    bool SeekEndOfFile(uint64_t& u64NewPosition);
    
    /** �����ļ�ʱ������
    @param [in] rcftCreationTime ����ʱ��
    @param [in] rcftLastAccessTime ���һ�η���ʱ��
    @param [in] rcftLastModifyTime ���һ���޸�ʱ��
    @return �ɹ�����true, ���򷵻�false
    */
    bool SetTime(const RC_FILE_TIME rcftCreationTime, const RC_FILE_TIME rcftLastAccessTime, const RC_FILE_TIME rcftLastModifyTime);
    
    /** ��ȡ�ļ�ʱ������
    @param [in] rcftCreationTime ����ʱ��
    @param [in] rcftLastAccessTime ���һ�η���ʱ��
    @param [in] rcftLastModifyTime ���һ���޸�ʱ��
    @return �ɹ�����true, ���򷵻�false
    */
    bool GetTime(RC_FILE_TIME& rcftCreationTime, RC_FILE_TIME& rcftLastAccessTime, RC_FILE_TIME& rcftLastModifyTime);

    /** �����ļ�����
    @param [in] u64Length �ļ�����
    @return �ɹ�����true, ���򷵻�false
    */
    bool SetLength(uint64_t u64Length);
    
    /** �ƶ��ļ�ָ�뵽�ļ�β
    @return �ɹ�����true, ���򷵻�false
    */
    bool SetEndOfFile();
    
    /** �ļ��Ƿ��Ѵ�
    @return ����Ѿ��򿪷���true, ���򷵻�false
    */
    bool IsOpen() const ;
    
private:
    
    /** �ļ������
    */
    class RCFileHandle;
    
    /** �ļ����
    */
    RCFileHandle* m_prcfhFile;
};

END_NAMESPACE_RCZIP

#endif //__RCFile_h_