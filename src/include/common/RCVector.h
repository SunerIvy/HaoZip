/********************************************************************************
 *  ��Ȩ����(C)2008,2009,2010����ѹ��������ң���������Ȩ����                   *
 ********************************************************************************
 *  ����    : HaoZip                                                            *
 *  �汾    : 1.7                                                               *
 *  ��ϵ��ʽ: haozip@gmail.com                                                  *
 *  �ٷ���վ: www.haozip.com                                                    *
 ********************************************************************************/

#ifndef __RCVector_h_
#define __RCVector_h_ 1

#include "base/RCDefs.h"
#include <vector>

#define RCVector std::vector
    
BEGIN_NAMESPACE_RCZIP

typedef RCVector<int32_t>   RCIntVector ;
typedef RCVector<uint32_t>  RCUIntVector ;
typedef RCVector<bool>      RCBoolVector ; //ע�⣺�����Ͳ�����C�������ʹ��
typedef RCVector<byte_t>    RCByteVector ;
typedef RCVector<void*>     RCPointerVector ;

namespace RCVectorUtils
{
    /** ��Vector�в���Ԫ�أ����Բ���
    @param [in] array ��Ҫ���ҵ�Vector����
    @param [in] item ��Ҫ���ҵ�Ԫ��
    @return ���ظ�Ԫ�ص��±꣬��0��ʼ���������ʧ�ܷ���-1
    */
    template <typename T>
    int32_t Find(const RCVector<T>& array, const T& item)  
    {
        int32_t count = (int32_t)array.size() ;
        for (int32_t i = 0; i < count ; ++i)
        {
            if (item == array[i])
            {
                return i ;
            }
        }
        return -1 ;
    }
    
    /** ��Vector��ɾ��ָ��Ԫ��
    @param [in] array ��Ҫ������Vector����
    @param [in] index ��Ҫɾ������ʼ�±�ֵ
    @param [in] num ��Ҫɾ����Ԫ�ظ���
    */
    template <typename T>
    void Delete(RCVector<T>& array, int32_t index, int32_t num = 1)
    {
        if( (index < 0) || ( num < 1) )
        {
            return ;
        }
        int32_t count = (int32_t)array.size() ;
        if( (num + index) > count )
        {
            num = count - index ;
        }
        array.erase(array.begin() + index, array.begin() + index + num) ;
    }
    
    /** ��Vector������Ԫ��
    @param [in] array ��Ҫ������Vector����
    @param [in] index ��Ҫ������±�ֵλ��
    @param [in] item ��Ҫ�����Ԫ��ֵ
    */
    template <typename T>
    void Insert(RCVector<T>& array, int32_t index, const T& item)
    {
        if(index <= 0)
        {
            array.insert(array.begin(),item) ;
            return ;
        }
        else if(index >= (int32_t)array.size())
        {
            array.push_back(item) ;
            return ;
        }
        array.insert(array.begin() + index,item) ;
    }
    
    /** ��Vector�в���Ԫ�أ����ַ����ң�ǰ����Vector�ڵ����ݱ����������
    @param [in] array ��Ҫ���ҵ�Vector����
    @param [in] item ��Ҫ���ҵ�Ԫ��
    @return ���ظ�Ԫ�ص��±꣬��0��ʼ���������ʧ�ܷ���-1
    */
    template <typename T>
    int32_t FindInSorted(const RCVector<T>& array, const T& item)
    {
        int32_t left = 0 ;
        int32_t right = (int32_t)array.size() ;
        while (left != right)
        {
            int32_t mid = (left + right) / 2;
            const T& midValue = array[mid];
            if (item == midValue)
            {
                return mid;
            }
            if (item < midValue)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return -1 ;
    }
    
    /** ��Vector�����Ԫ�أ�ȷ��Vector�е������������
    @param [in] array ��Ҫ������Vector����
    @param [in] item ��Ҫ�����Ԫ��ֵ
    @return ���ز���Ԫ�ص��±�λ��
    */
    template <typename T>
    int32_t AddToSorted(RCVector<T>& array, const T& item)
    {
        int32_t left = 0 ;
        int32_t right = (int32_t)array.size() ;
        while (left != right)
        {
            int32_t mid = (left + right) / 2;
            const T& midValue = array[mid];
            if (item == midValue)
            {
                right = mid + 1 ;
                break ;
            }
            if (item < midValue)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        array.insert(array.begin() + right, item) ;
        return right ;
    }
    
    /** ��Vector�����Ԫ�أ�ȷ��Vector�е��������������Ψһ��
    @param [in] array ��Ҫ������Vector����
    @param [in] item ��Ҫ�����Ԫ��ֵ
    @return ���ز���Ԫ�ص��±�λ��
    */
    template <typename T>
    int32_t AddToUniqueSorted(RCVector<T>& array, const T& item)
    {
        int32_t left = 0 ;
        int32_t right = (int32_t)array.size() ;
        while (left != right)
        {
            int32_t mid = (left + right) / 2;
            const T& midValue = array[mid];
            if (item == midValue)
            {
                return mid;
            }
            if (item < midValue)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        array.insert(array.begin() + right, item) ;
        return right ;
    }
    
    /** �ͷŶ����ڴ�
    @param [in] array ��Ҫ������Vector����
    */
    template <typename T>
    void ReserveDown(RCVector<T>& array)
    {
        //ʲôҲ����
    }
    
    /** �����㷨
    @param [in] p ������ʼ��ַ
    @param [in] k ����Ԫ����ʼλ��
    @param [in] size ���鳤��
    @param [in] functor �ȽϺ���
    */
    template<class T,
             class TCompareFunctors>
    void SortRefDown(T* p, int32_t k, int32_t size, TCompareFunctors functor)
    {
        T temp = p[k] ;
        for (;;)
        {
            int32_t s = (k << 1);
            if (s > size)
            {
                break;
            }
            if (s < size && functor(*(p + s + 1), *(p + s)) > 0)
            {
                s++;
            }
            if (functor(temp, *(p + s)) >= 0)
            {
                break;
            }
            p[k] = p[s] ;
            k = s ;
        }
        p[k] = temp ;
    }
    
    /** �����㷨
    @param [in] array ��Ҫ���������
    @param [in] functor �ȽϺ���
    */
    template<class T,
             class TCompareFunctors>
    void Sort(RCVector<T>& array, TCompareFunctors functor)
    {
        int32_t size = (int32_t)array.size() ;
        if (size <= 1)
        {
            return ;
        }
        T* p = (&array.front()) - 1 ;
        {
            int32_t i = size / 2;
            do
            {
                SortRefDown<T>(p, i, size,functor);
            } while (--i != 0) ;
        }
        do
        {
            T temp = p[size] ;
            p[size--] = p[1] ;
            p[1] = temp ;
            SortRefDown<T>(p, 1, size,functor) ;
        } while (size > 1) ;
    }
    
}// end of namespace RCVectorUtils

END_NAMESPACE_RCZIP

#endif //__RCVector_h_
