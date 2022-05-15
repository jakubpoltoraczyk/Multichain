#include "../inc/MultichainInitialization.hh"

MultichainInitialization::MultichainInitialization(){
    std::ifstream infile("../GlobalVariables.txt");
    if(infile.fail()){
        cout << endl  << endl  << endl << "---> Brak Pliku: GlobalVariables!!!" << endl  << endl  << endl ;
    }
    else{
        StringFinder finder;
        chainName = finder.GetFirstValue(infile, "test_chain_name:");
        streamName = finder.GetFirstValue(infile, "test_stream_name:");
        keyName = finder.GetFirstValue(infile, "test_key_name:");
        infile.close();
    }
}

bool MultichainInitialization::IsConnected(){
    if (!MultichainIsWorking())
    {
        //MultichainClient multiClient;
        //multiClient.runChain(chainName);

        //todo -> show MessageBox with connection error
        cout << "------> Multichain " + chainName + " is not working" << endl;
    }
    if (!StreamIsConnected())
    {
        //todo -> show MessageBox with connection error
        cout << "------> Stream " + chainName + " is not connected" << endl;
    }
    
    return true;
}
bool MultichainInitialization::MultichainIsWorking(){
    CmdClient cmdClient;
    StringFinder finder;
    string res = cmdClient.SendRequest_normal("multichain-cli "+chainName+" getpeerinfo");
    string badResponse = "error: couldn't connect to server";

    return !finder.StringExistInString(res, badResponse);
}
bool MultichainInitialization::StreamIsConnected(){
    CmdClient cmdClient;
    StringFinder finder;
    string res = cmdClient.SendRequest_normal("multichain-cli chain1 listpermissions "+streamName+".*");
    string badResponse = "error code: -";

    return !finder.StringExistInString(res, badResponse);
}























