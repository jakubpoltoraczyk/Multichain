#include "../inc/CmdClient.hh"

CmdClient::CmdClient(){

}

string CmdClient::SendRequest(string requestMsg){
    // std::cout << requestMsg << endl << endl << endl;
    return execute_tee(requestMsg);
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

string CmdClient::execute_tee( std::string cmd )
{
    std::string file_name = "result.txt" ;
    std::system( ( cmd + " | tee " + file_name ).c_str() ) ; // redirect output to file

    // open file for input, return string containing characters in the file
    std::ifstream file(file_name) ;
    return { 
        std::istreambuf_iterator<char>(file), 
        std::istreambuf_iterator<char>() 
    };
}