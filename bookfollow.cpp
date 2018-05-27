#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
class TextQuery;
/*
void runQueries(ifstream *infile)
{
    TextQuery tq(infile);
    while(1) {
        cout << "enter word to look for, or q to quit :";
        string s;
        if (!(cin >> s) || s == "q") break;
        print(cout, tq.query(s)) << endl;
    }
}
 */
string make_plural ( size_t ctr , const string &word, const string &ending)
{
    return (ctr > 1 )? word + ending : word ;
}
class QueryResult;
class TextQuery{
    public :
    using line_no = std :: vector<std::string>::size_type;
    TextQuery (std:: ifstream&);
    QueryResult query(const std::string&) const;
    private :
    std :: shared_ptr <std::vector<string>> file;
    map<string, shared_ptr< set <line_no> > > wm;
};
TextQuery::TextQuery(std::ifstream &is):file(new vector<string>){
    string text;
    while(getline(is,text)){  //对文本中的每一行
        file->push_back(text);   // 保存此行的文本
        int n=file->size()-1;    //当前行号
        istringstream line(text); //将行文本分解成单词
        string word;
        while(line >> word){
            auto &lines =wm[word];   // lines 是一个 智能指针
            if(!lines)                     //在我第一次遇到这个单词时，此指针为空
                 lines.reset(new set<line_no>);   //分配一个新的set ;
            lines->insert(n); ///将行号插入set中
        }
    }
}
class QueryResult {
    friend  std :: ostream & print(ostream&, const QueryResult&);
    public :
    using line_no = std :: vector<std::string>::size_type;
    QueryResult(string s,
                shared_ptr<set<line_no>> p,
                shared_ptr<vector<string>>f ):sought(s),lines(p),file(f){}

    private:
    string sought;
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file;
};
QueryResult TextQuery::query(const string &sought)const
{
    //如果未找到sought 我们将返回一个set指针
   static shared_ptr<set<line_no>> nodata(new set<line_no>);
   // 使用 find 而不是下标运算 来查找单词 ，避免将单词添加到 wm中;
   auto loc = wm.find(sought);
   if( loc == wm.end())
        return QueryResult(sought,nodata,file);
   else
       return QueryResult(sought,loc->second,file);
}
ostream &print (ostream & os ,const QueryResult &qr)
{
    os<<qr.sought << " occurs " << qr.lines->size()<<" "<<make_plural(qr.lines->size(),"time","s")<<endl;
    for(auto num : *qr.lines)
         // 避免行号从 0 开始
         os<<" \t(line"<<num+1<<")"<<*(qr.file->begin()+num)<<endl;
    return os;
}
int main()
{}