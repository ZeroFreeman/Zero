#include <iostream>
#include <fstream>

using namespace std;

//将.txt格式文件转换为.html格式文件
class THtmlDoc
{
public:
    void html();
};

//基类常规文本不转化
class TTranslator
{
    friend class TH1Translator;
    friend class TH2Translator;
    friend class THtmlDoc;

public:
    void getFile(TTranslator & t, TTranslator & t1, TTranslator & t2);
    void frame(TTranslator & a, string str, ofstream & fout);
    virtual void change(string str, ofstream & fout);
};

//派生类转化一级标题
class TH2Translator : public TTranslator
{
public:
    virtual void change(string str, ofstream & fout);
};

//派生类转化二级标题
class TH1Translator : public TTranslator
{
public:
    virtual void change(string str, ofstream & fout);
};

//不转化实现
void TTranslator::change(string str, ofstream & fout)
{
    fout << str << endl;
}

//一级标题转化实现
void TH1Translator::change(string str, ofstream & fout)
{
    str.erase(0, 2);
    str.insert(0, "<h2>");
    str.insert(str.length(), "</h2>");
    cout << str << endl;
    fout << str << endl;
}

//二级标题转化实现
void TH2Translator::change(string str, ofstream & fout)
{
    str.erase(0, 1);
    str.insert(0, "<h1>");
    str.insert(str.length(), "</h1>");
    cout << str << endl;
    fout << str << endl;
}

//框架
void TTranslator::frame(TTranslator & a, string str, ofstream & fout)
{
    a.change(str, fout);
}

//文件读写转化选择
void TTranslator::getFile(TTranslator & t, TTranslator & t1, TTranslator & t2)
{
    ofstream fout;
    ifstream fin;
    rename("change.html", "change.txt");
    fout.open("change.txt", ios_base::out);
    fin.open("source.txt", ios_base::in);
    string str;

    fout << "<html>\n<body>" << endl;//附上标签

    while (getline(fin, str))
    {
        cout << str << endl;
        if (!str.find("##", 0))
        {
            this->frame(t1, str, fout);
        }
        else
            if (!str.find("#", 0))
                this->frame(t2, str, fout);
            else
                this->frame(t, str, fout);
    }

    fout.close();
    fin.close();
}

//.html格式文件转化实现
void THtmlDoc::html()
{
    ofstream fout;
    fout.open("change.txt", ios_base::app);
    fout << "</body>\n</html>" << endl;//回补标签
    fout.close();
    rename("change.txt", "change.html");

}

int main()
{
    TTranslator t;
    THtmlDoc h;
    TH1Translator t1;
    TH2Translator t2;
    t.getFile(t, t1, t2);

    h.html();

    return 0;
}
