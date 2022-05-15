#include "../inc/CmdClient.hh"

CmdClient::CmdClient(){

}

string CmdClient::SendRequest_normal(string requestMsg){
    return execute(requestMsg);
}
string CmdClient::SendRequest_tee(string requestMsg){
    return execute_tee(requestMsg);
}
void CmdClient::SendRequest_noResponse(string requestMsg){
    std::system( requestMsg.c_str() ); 
}
void CmdClient::ClearConsole(){
    std::system( "clear" ); 
}












string CmdClient::execute( std::string cmd )
{
    std::string file_name = "result.txt" ;
    std::system( ( cmd + " 2> " + file_name ).c_str() ) ;                       // redirect output to file (2> -> capture output and error)

    std::ifstream file(file_name) ;
    return { 
        std::istreambuf_iterator<char>(file), 
        std::istreambuf_iterator<char>() 
    };
}

string CmdClient::execute_tee( std::string cmd )
{
    std::string file_name = "result_tee.txt" ;
    std::system( ( cmd + " | tee " + file_name ).c_str() ) ; // redirect output to file

    // open file for input, return string containing characters in the file
    std::ifstream file(file_name) ;
    return { 
        std::istreambuf_iterator<char>(file), 
        std::istreambuf_iterator<char>() 
    };
}