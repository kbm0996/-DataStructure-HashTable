# 해시테이블 예제
## 📢 개요
### ▶ 해싱(Hashing)
  
   해싱은 해시테이블(HashTable)이라는 기억공간을 할당하고, 해시함수(HashFunction)를 이용하여 레코드 키에 대한 해시테이블 내의 Home Address를 계산한 후 주어진 레코드를 해당 기억장소에 저장하거나 검색 작업을 수행하는 방식이다.
  
  1. 해싱은 DAM 파일을 구성할 때 사용되며, 접근 속도는 빠르나 기억공간이 많이 요구된다.
  2. 다른 방식에 비해 검색 속도가 가장 빠르다.
  3. 삽입 삭제 작업의 빈도가 많을 때 유리한 방식이다.
  4. 키-주소 변환 방법이라고도 한다.
  
### ▶ 해시테이블(HashTable)
   해시테이블은 레코드를 한개 이상 보관할 수 있는 버켓(Bucket)들로 구성된 기억공간으로 보조기억장치에 구성할 수도 있고 주기억장치에 구성할 수도 있다.

**버킷(Bucket)** : 하나의 주소를 갖는 파일의 한 구역을 의미하며, 버킷의 크기는 같은 주소에 포함될 수 있는 레코드 수를 의미한다.

**슬롯(Slot)** : 한 개의 레코드를 저장할 수 있는 공간으로 n개의 슬롯이 모여 하나의 버킷을 형성한다.

**충돌(Collision)** : 서로 다른 두개이상의 레코드가 같은 주소를 갖는 현상이다.

**동의(Synonym)** : 충돌로 인해 같은 Home Address를 갖는 레코드들의 집합이다.

**Overflow** : 계산된 Home Address의 Bucket 내에 저장할 기억공간이 없는 상태로, Bucket을 구성하는 Slot이 여러개일때 Collision은 발생해도 Overflow는 발생하지 않을 수 있따.


## 📑 파일
### 📋 Hashtable.h - Hashtable.cpp
  해시테이블(Hashtable) 클래스의 선언부와 정의부
  
  
### 📋 SinglyLinkedlist.h
  해시테이블 클래스의 내부 클래스인 버킷(Bucket) 클래스 구현에 필요한 링크드 리스트 선언 및 정의


### 📋 Config.h
  해시테이블 내 버킷 개수와 입력할 수 있는 문자열의 최대 길이를 하드코딩으로 지정
  
  

## 📌 주요 소스 코드
### 📋 Hashtable.h/cpp
    class Hashtable
    {
    protected:
      struct stSLOT
      {
        char chKey[df_LEN_MAX];	// ID
        char chValue[df_LEN_MAX];	// NAME
      };

      class Bucket : protected Linkedlist<stSLOT*>
      {
      public:
        Bucket() {}
        virtual ~Bucket() {}

        bool Insert(char* chKey, char* chValue);
        bool Delete(char* chKey);

        void Print();
        bool SearchKey(char* chKey, stSLOT * chOutAccount = nullptr);  // Key로 Value 검색
        bool SearchValue(char* chValue, stSLOT * chOutAccount = nullptr); // Value로 Key 검색

      private:
        friend class Hashtable;
        // TODO: ID의 ASCII의 총합을 시드값으로 사용. 출력값을 리스트의 인덱스로 사용
        static void Hashing(char* szString, int *OutHashCode);
      };

    public:
      Hashtable(int iHashTable_Cnt = df_BUCKET_CNT);
      virtual ~Hashtable();

      bool Insert(char* szInID, char* szInName);
      bool Delete(char* szInID);
      // Hashtable 내 모든 Bucket에 있는 Slot의 Data를 콘솔창에 출력
      void Print();
      bool Search(char* szInID);

    private:
      int _iHashTable_Cnt;
      Bucket* _pBucket[df_BUCKET_CNT];

    };



### 📋 SinglyLinkedlist.h
  편의상 싱글 링크드리스트를 사용함. 이미 검증된 STL의 list를 사용해도 됨.


 ## 📌 출처 
 
 개요 - https://coding-factory.tistory.com
