    ��ѹ(HaoZip) V1.7 ѹ���ļ���ʽ��ѹ����ѹ�㷨����Դ����
--------------------------------------------------------------------------------
    ��ѹ(HaoZip)��һ��Windowsƽ̨��ѹ����ѹ�����
********************************************************************************
*  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   * 
******************************************************************************** 
*  ����    : HaoZip                                                            * 
*  �汾    : 1.7                                                               * 
*  ��ϵ��ʽ: haozip@gmail.com                                                  * 
*  �ٷ���վ: www.haozip.com                                                    * 
********************************************************************************

1. ��α���Դ����
(1) ��ȡ������������
    ��ѹ��ʵ��ʱ����boost�⡢UnRar�⡢WavePack�⣬������Ҫ��ȡ����������������
    Դ���룬�������£�
    A. (����)��ȡboost��Ĵ��룬��ѹʹ�õ���boost 1.38�汾����⣬���Դ�
       http://sourceforge.net/projects/boost/files/boost/1.38.0/��ַ��ȡ��
       ��ȡ�󣬽������ѹ vendor\include\boost Ŀ¼�У�����Ҫ����boost�⡣
       
    B. (��ѡ)��ȡUnRar�⣬��ѹ�ڴ���Rar��ʽʱ��������UnRar��Ĳ��ִ��룬���Դ�
       http://www.rarlab.com/rar_add.htm��վ�������´��롣
       ���غ���Ҫ�������ΪLib�⣬����ѹ����ʹ�á�
       ����debug �汾�� ʹ�� /MDdѡ�����
       ����Release�汾����Ҫʹ�� /MD ѡ�����
       ������Lib���ƣ�Debug�汾������Ϊ��UnRar_MDd.lib
                        Release�汾������Ϊ��UnRar_MD.lib
       ����Win32��Debug�汾��UnRar_MDd.lib����vendor\lib\win32\debugĿ¼
                  Release�汾��UnRar_MD.lib����vendor\lib\win32\releaseĿ¼
       ����X64��Debug�汾��UnRar_MDd.lib����vendor\lib\x64\debugĿ¼
                Release�汾��UnRar_MD.lib����vendor\lib\x64\releaseĿ¼
                
       UnRar��ͷ�ļ���Ҫ����vendor\include\UnRarĿ¼��
       
    C. (��ѡ)��ȡWavePack��⣬���Դ�http://www.wavpack.com/downloads.html���ء�
       ���غ����غ���Ҫ�������ΪLib�⣬����ѹ����ʹ�á�
       ����debug �汾�� ʹ�� /MDdѡ�����
       ����Release�汾����Ҫʹ�� /MD ѡ�����
       ������Lib���ƣ�Debug�汾������Ϊ��WavPack_MDd.lib
                        Release�汾������Ϊ��WavPack_MD.lib
       ����Win32��Debug�汾��WavPack_MDd.lib����vendor\lib\win32\debugĿ¼
                  Release�汾��WavPack_MD.lib����vendor\lib\win32\releaseĿ¼
       ����X64��Debug�汾��WavPack_MDd.lib����vendor\lib\x64\debugĿ¼
                Release�汾��WavPack_MD.lib����vendor\lib\x64\releaseĿ¼
       
       ͷ�ļ�wavpack.h��Ҫ����vendor\include\wavpackĿ¼��

(2) �������������׼�����Ժ󣬽���build\MSVCĿ¼��ʹ��VC��build.sln�ļ����Խ��б��롣
    �����VC�汾Ϊ VC 2005.

2. �ļ��ṹ˵��
(1) build Ŀ¼
    ΪHaoZip��VC 2005�Ĺ����ļ�
(2) doc Ŀ¼
    ΪHaoZip��صĿ����ĵ�����
(3) include Ŀ¼
    ΪHaoZip�Ľӿ�Դ�ļ������չ��ܻ���Ϊ������Ŀ¼��
      algorithm Ŀ¼  -- ѹ�����ѹ�㷨Cʵ�ֵĽӿ��ļ�
      archive   Ŀ¼  -- ѹ����ѹ�ӿ�
      base Ŀ¼       -- ���̹��ýӿڶ���
      coder Ŀ¼      -- ѹ�����ѹ��صı���ӿڶ���
      common Ŀ¼     -- �����㷨�ӿڶ���
      compress Ŀ¼   -- ѹ�����ѹ�㷨�ӿ�
      crypto Ŀ¼     -- ����������㷨�ӿ�
      exception Ŀ¼  -- �쳣���ݴ�ӿ�
      filesystem Ŀ¼ -- IO���ʽӿ�
      format Ŀ¼     -- �����ļ���ʽ��װ�ӿ�
      interface       -- ѹ�����ѹ���̵Ľӿڶ���
      language        -- ���Թ���ӿ�
      locked          -- ѹ�����ѹ������صĶ��̷߳�װ�ӿ�
      thread          -- ���̷߳�װ�ӿ�
      version         -- �汾����ӿ�
(4) src Ŀ¼
      ΪHaoZip��ʵ���ļ�Ŀ¼�����չ��ܻ���Ϊ������Ŀ¼��
      algorithm Ŀ¼  -- ѹ�����ѹ�㷨Cʵ��
      coder Ŀ¼      -- ѹ�����ѹ��صı���ʵ��
      compress Ŀ¼   -- ѹ�����ѹ�㷨ʵ��
      crypto Ŀ¼     -- ����������㷨ʵ��
      format Ŀ¼     -- �����ļ���ʽ��װʵ��
(5) vendor Ŀ¼
      ��Ŀ¼ΪHaoZip�����ĵ�������⡣
      vendor\include\boost    -- boost �Ľӿ��ļ������Լ����غ���ڴ�Ŀ¼
      vendor\include\UnRar    -- UnRar���Ľӿ��ļ�
      vendor\include\wavpack  -- wavpack���Ľӿ��ļ�
      
      vendor\lib\win32\debug    -- Win32��Debug�汾Lib�ļ���Ӧ����UnRar_MDd.lib��WavPack_MDd.lib�����ļ�
      vendor\lib\win32\release  -- Win32��Release�汾Lib�ļ���Ӧ����UnRar_MD.lib��WavPack_MD.lib�����ļ�
      vendor\lib\x64\debug      -- x64��Debug�汾Lib�ļ���Ӧ����UnRar_MDd.lib��WavPack_MDd.lib�����ļ�
      vendor\lib\win32\debug    -- x64��Debug�汾Lib�ļ���Ӧ����UnRar_MD.lib��WavPack_MD.lib�����ļ�
      
      vendor\depends\UnRar      -- UnRar���Դ���룬ʹ��ʱ����ѭԭ���ߵ���ȨЭ�顣
      vendor\depends\wavPack    -- WavPack���Դ���룬ʹ��ʱ����ѭԭ���ߵ���ȨЭ�顣
      
(6) windows Ŀ¼
      ��Ŀ¼��������DLLʱʹ�õ�manifest�ļ���
      
      windows\manifest\HaoZip.dll.x64.manifest  --  x64������ʹ�õ�manifest�ļ�
      windows\manifest\HaoZip.dll.x86.manifest  --  Win32������ʹ�õ�manifest�ļ�
(7) lib Ŀ¼
      ��Ŀ¼����HaoZip�ײ��װ�Ĳ���Ԥ����Lib�ļ���
      
      lib\win32\debug\RCArchive_MDd.lib     -- Win32����, Debug�汾��/MDd����ѡ��
      lib\win32\debug\RCCommon_MDd.lib      -- Win32����, Debug�汾��/MDd����ѡ��
      
      lib\win32\release\RCArchive_MD.lib    -- Win32����, Release�汾��/MD����ѡ��
      lib\win32\release\RCCommon_MD.lib     -- Win32����, Release�汾��/MD����ѡ��
      
      lib\x64\debug\RCArchive_MDd.lib       -- x64����, Debug�汾��/MDd����ѡ��
      lib\x64\debug\RCCommon_MDd.lib        -- x64����, Debug�汾��/MDd����ѡ��
      
      lib\x64\release\RCArchive_MD.lib      -- x64����, Release�汾��/MD����ѡ��
      lib\x64\release\RCCommon_MD.lib       -- x64����, Release�汾��/MD����ѡ��
      
      ���У�RCArchive_MD.lib��RCArchive_MDd.lib ��HaoZipѹ�����ѹ���̷�װ��Ԥ����Lib��
            RCCommon_MD.lib��RCCommon_MDd.lib ��HaoZip�ײ�����㷨ʵ������Ԥ����Lib��
            ��������Lib����Ǻ�ѹ�ײ�����һ���֣�������Դ���롣
