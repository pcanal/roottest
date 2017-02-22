#ifndef _ARRAYHOLDER_
#define _ARRAYHOLDER_

#include <array>
#include <vector>
#include <string>
#include <sstream>

class ArrayHolder {
  public:
   void Set(int a, int b, int c) {
      m_a[0]=a;m_a[1]=b;m_a[2]=c;
      for (auto& v : {a,b,c}) {
         auto vprime=v+.5;
         m_v.emplace_back(vprime);
      }
   };
    ArrayHolder(int a, int b, int c) {
       Set(a,b,c);
   };
   ArrayHolder() {};
   std::string ToString() {
      std::stringstream ss;
      for (auto&& el : m_a) ss << el << "-";
      for (auto&& el : m_v) ss << el << "-";
      ss << std::endl;
      return ss.str();
   }
    std::vector<double> m_v {10,11};
#ifdef ARRAYHOLDER_STDARRAY
    std::array<int, 3> m_a {{0,0,0}};
#else
    int m_a[3] {0,0,0};
#endif
};

class MetaArrayHolder {
  public:
   void Set(int a, int b, int c) {
      m_a[0]={a,b,c};
      m_a[1]={2*a,2*b,2*c};
      m_a[2]={3*a,3*b,3*c};
   };
   MetaArrayHolder(int a, int b, int c){Set(a,b,c);};
   MetaArrayHolder() {
      Set(0,0,0);
   };
   std::string ToString() {
      std::stringstream ss;
      for (auto& el : m_a)
         ss << el.ToString();
      return ss.str();
   }
#ifdef ARRAYHOLDER_STDARRAY
    std::array<ArrayHolder, 3> m_a;
#else
    ArrayHolder m_a[3];
#endif
};

#ifdef __ROOTCLING__
#pragma link C++ class ArrayHolder+;
#pragma link C++ class MetaArrayHolder+;
#endif

#endif