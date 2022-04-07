#include "../inc/IpfsClient.hh"




int main()
{
    IpfsClient client;
    //string tmp = client.CheckVersion();
    //string tmp = client.PinHashes();
    //string tmp = client.AddFileToIpfs("/home/peter/Desktop/MultiChainCpp_Proj_v2/my_file.txt");
    //string tmp = client.GetFileFromIpfs("QmZjfc8vgXJeaSHBsutYZtap3xtLNw6UPGVcs96uB1mN14");
    //std::cout << "Result:\n\n" << tmp << "\n";

    client.SafeFileFromIpfsToFile("QmZjfc8vgXJeaSHBsutYZtap3xtLNw6UPGVcs96uB1mN14", "tmp.txt");
    //std::cout << "I am " << execute( "pwd" ) << "\n-----------------\n" << "ipconfig result: " << execute( "ipconfig -all" ) << '\n' ;
    //execute( "ipfs cat /ipfs/QmQPeNsJPyVWPFDVHb77w8G42Fvo15z4bG2X8D2GhfbSXc/readme" )
    
}
