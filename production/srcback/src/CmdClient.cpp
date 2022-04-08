#include "../inc/CmdClient.hh"

CmdClient::CmdClient(){

}

string CmdClient::SendRequest(string requestMsg){
    return execute(requestMsg);
}
void CmdClient::SendRequest_noResponse(string requestMsg){
    std::system( requestMsg.c_str() ); 
}












string CmdClient::execute( std::string cmd )
{
    std::string file_name = "result.txt" ;
    std::system( ( cmd + " > " + file_name ).c_str() ) ; // redirect output to file

    // open file for input, return string containing characters in the file
    std::ifstream file(file_name) ;
    return { 
        std::istreambuf_iterator<char>(file), 
        std::istreambuf_iterator<char>() 
    };
}