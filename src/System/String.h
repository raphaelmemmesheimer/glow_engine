#include <string>
#include <wx/string.h>
class String {
public:
  String ();
  virtual ~String ();
  wxString toWxString();
  std::string toStdString();
private:
  std::string data;

};

