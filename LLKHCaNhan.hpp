#ifndef LLKHCANHAN_HPP__

#define LLKHCANHAN_HPP__

#include "LinkList_T.hpp"
#include "CTKH.hpp"
#include "BaiBao.hpp"
#include "Sach.hpp"
class LLKHCaNhan
{
    public:
        LLKHCaNhan();  // Constructor mac dinh
        LLKHCaNhan(const LLKHCaNhan& llkh); // Constructor sao chep
        LLKHCaNhan(const string& name); // Constructor chi nhan vao 1 tham so name
        LLKHCaNhan(string&& name); // Constructor nhan vao 1 tham so name
        LLKHCaNhan(const string& name, LinkList<CTKH*>* constructList); // nhan vao tham so name va list
        LLKHCaNhan(string&& name, LinkList<CTKH*> constructList); // nhan vao tham so name va list

        bool append(CTKH* newConstruct);
        bool remove(string ID);
        bool update(string ID);
        CTKH*& search(string ID);

        CTKH*& operator [ ] (string ID);
        CTKH*& operator [ ] (size_t index);
        
        LLKHCaNhan& operator = (const LLKHCaNhan& llkh);

        friend istream& operator >> (istream& in, LLKHCaNhan& llcn);
        friend ostream& operator << (ostream& in, const LLKHCaNhan& llcn);

    private:
        string m_name_;
        int m_nScientificContructsNumber_;

        LinkList<CTKH*>* m_pConstructList_; // Danh sach con tro CTKH
};


#endif
