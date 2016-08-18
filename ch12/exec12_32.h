
#include <memory>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <set>

#include "StrBlob.h"

class BlobQueryResult;

class BlobTextQuery{
public:
    typedef std::vector<std::string>::size_type line_no;
    BlobTextQuery(std::ifstream &);
    BlobQueryResult query(const std::string &) const;
private:
    std::shared_ptr<StrBlob> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>>  wm;
};

class BlobQueryResult{
    friend std::ostream& print(std::ostream&, const BlobQueryResult&);
public:
    BlobQueryResult(std::string s,
                    std::shared_ptr<std::set<BlobTextQuery::line_no>> p,
                    std::shared_ptr<StrBlob> f):
                    sought(s), lines(p), file(f){}
    std::set<BlobTextQuery::line_no>::iterator begin();
    std::set<BlobTextQuery::line_no>::iterator end();
    std::shared_ptr<StrBlob> get_file();

private:
    std::string sought;
    std::shared_ptr<std::set<BlobTextQuery::line_no>> lines;
    std::shared_ptr<StrBlob> file;

};