#include "../inc/StringFinder.hh"

StringFinder::StringFinder(){

}

//zwraca index wskazujacy na miejsce gdzie zaczyna sie wskazany ciag znakow
bool _isNext(string& body, int& startIndex, string& nextString){
    for (size_t i = startIndex; i < body.length(); i++){
        bool notOk = false;
        for (size_t j = 0; j < nextString.length(); j++){
            if (body[ (i + j) ] != nextString[j]){
                notOk = true;
                break;
            }
        }
        if (!notOk){
            startIndex = i;
            return true;
        }
    }
    return false;
}
string _getValue(string& body, int& startIndex, string& startString, string& endString)
{
    string ret = "";

    if (_isNext(body, startIndex, startString))
    {
        startIndex += startString.length();
        int copy_of_index =  startIndex;

        if (_isNext(body, startIndex, endString))
        {
            for (int i = copy_of_index; i < startIndex; i++)    //jezeli istnieja oba stringi, to wczytaj tekst pomiedzy nimi
            {
                ret += body[i];
            }
            startIndex += endString.length();
        }
    }
    return ret;
}    

bool StringFinder::StringExistInString(string& body, string& startString){
    int idx = 0;
    return _isNext(body, idx, startString);
}
string StringFinder::GetFirstValue(string& body, string& startString, string& endString){
    int idx = 0;
    return _getValue(body, idx, startString, endString);
}
string StringFinder::GetListOfValues(string& body, string& startString, string& endString){
    int idx = 0;
    return _getValue(body, idx, startString, endString);
}
string StringFinder::GetFirstValue(ifstream& stream, string startString){
    std::string tmp = "";
    std::string res = "";

    while (tmp != startString) {
        stream >> tmp;
    }
    stream >> res;
    return res;
}
