# 해시테이블 예제
## 📢 개요
### ▶ 해싱(Hashing)
  
   해싱은 해시테이블(HashTable)이라는 기억공간을 할당하고, 해시함수(HashFunction)를 이용하여 레코드 키에 대한 해시테이블 내의 Home Address를 계산한 후 주어진 레코드를 해당 기억장소에 저장하거나 검색 작업을 수행하는 방식이다.
  
  1. 해싱은 DAM 파일을 구성할 때 사용되며, 접근 속도는 빠르나 기억공간이 많이 요구된다.
  2. 다른 방식에 비해 검색 속도가 가장 빠르다.
  3. 삽입 삭제 작업의 빈도가 많을 때 유리한 방식이다.
  4. 키-주소 변환 방법이라고도 한다.
  
### ▶ 해시테이블(HashTable)
   해시테이블은 레코드를 한개 이상 보관할 수 있는 Bucket들로 구성된 기억공간으로 보조기억장치에 구성할 수도 있고 주기억장치에 구성할 수도 있다.

``버킷(Bucket)`` : 하나의 주소를 갖는 파일의 한 구역을 의미하며, 버킷의 크기는 같은 주소에 포함될 수 있는 레코드 수를 의미한다.

``슬롯(Slot)`` : 한 개의 레코드를 저장할 수 있는 공간으로 n개의 슬롯이 모여 하나의 버킷을 형성한다.

``충돌(Collision)`` : 서로 다른 두개이상의 레코드가 같은 주소를 갖는 현상이다.

``동의(Synonym)`` : 충돌로 인해 같은 Home Address를 갖는 레코드들의 집합이다.

``Overflow`` : 계산된 Home Address의 Bucket 내에 저장할 기억공간이 없는 상태로, Bucket을 구성하는 Slot이 여러개일때 Collision은 발생해도 Overflow는 발생하지 않을 수 있따.


https://coding-factory.tistory.com/233

## 📌전역 변수
### 🔧 ``WCHAR g_Dic[df_WORD_CNT][2][20];``
  좌측값을 우측값으로 대체하는데 사용되는 배열. df_WORD_CNT는 변환 가능한 단어 개수이고 2는 좌측값과 우측값의 한 쌍이며 20은 최대 글자 수를 의미한다.

      WCHAR g_Dic[df_WORD_CNT][2][20] =
      {
        { L"i",L"나" },{ L"you",L"너" },{ L"like",L"좋아한다" },{ L"love",L"사랑한다" },{ L"hate", L"증오한다" },
        { L"am",L"은/는" },{ L"are", L"은/는" },{L"is", L"은/는"}, { L"she", L"그녀" },{ L"he", L"그" },
        { L"boy", L"소년" },{L"a",L""}, { L"an",L"" }
      };



### 🔧 ``WCHAR g_Buff[df_STRING_MAX_LENGTH / 2][df_STRING_MAX_LENGTH];``
  변환에 성공했거나 실패한 단어들을 저장하는 임시 버퍼


## 📌함수
### 🔧 ``void StringDivide(WCHAR* pInStr);``
  구분자로 단어를 추출하는 함수.
  
  1. 인자 (Parameters)
  >const WCHAR* pInStr

  단어를 추출할 원본 문자열 
 
  2. 주요 레퍼런스
 - 문자열 복사 **wcsncpy_s();**

 최대 지정한 길이만큼 NULL문자를 만날때까지 문자열을 복사하는 함수


### 🔧 ``void StringConverse(WCHAR* pInStr, WCHAR* pOutStr);``
  g_Dic[][][]에 저장된 단어들을 검색하여 치환시켜주는 함수
  
  1. 인자 (Parameters)
  >const wstring& pInStr

  단어를 변경할 문자열 
 
  >WCHAR* pOutStr
  
  변경된 문자열을 저장할 
      
      
