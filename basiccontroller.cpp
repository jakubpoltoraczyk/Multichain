#include "basiccontroller.h"
#include "srcback/inc/IpfsClient.hh"
#include "srcback/inc/CmdClient.hh"
#include "srcback/inc/MultichainClient.hh"
#include "srcback/inc/MultichainInitialization.hh"

#include <iostream>
#include <vector>


string chainName  = "";
string streamName = "";
string keyName    = "";





namespace {

namespace Test {
const int MAX_NUMBER_OF_FILES = 3;
const QString FILE_NAME = QStringLiteral("File%0");
const QString FILE_PROCESS_MESSAGE =
    QStringLiteral("Process of \"%0\" has been finished");
} // namespace Test

} // namespace

BasicController::BasicController(QObject *parent) : QObject(parent) {
  QObject::connect(&dropFileAreaController,
                   &DropFileAreaController::startDroppedFileProcessing, this,
                   &BasicController::processDroppedFile);

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

std::vector<std::pair<QString, QObject *>>
BasicController::getObjectsToRegister() {
  return {{"controller", this},
          {"dropFileAreaController", &dropFileAreaController},
          {"customMessageDialogController", &customMessageDialogController}};
}

void BasicController::processDroppedFile(const std::string &filePath) {
  std::string temp = "file://";
  string fileName = filePath.substr(temp.length(), filePath.length() - temp.length());

  CmdClient cmdClient;
  cmdClient.ClearConsole();

  MultichainInitialization multichainInitialization;
  if(multichainInitialization.IsConnected()){
    IpfsClient ipfsClient;
    string fileAddress = ipfsClient.AddFileToIpfs(fileName);
    
    MultichainClient multichainClient;
    multichainClient.publishData(chainName, streamName, keyName, fileAddress, fileName);
    multichainClient.ClearConsole();
    cout << "Dodano plik: " << fileName << endl;
  }

/*



  MultichainClient multichainClient;
  multichainClient.initChain(chainName, streamName);
  multichainClient.createStream(chainName, streamName);
  multichainClient.subscribeToStream(chainName, streamName);
  multichainClient.publishData(chainName, streamName, keyName, fileAddress, fileName);
  multichainClient.listStreamItems(chainName, streamName);
  ObtainedAddressFromStream = multichainClient.returnFileAddress(chainName, streamName, fileName);

  std::cout << endl << "Odzyskany adres pliku: " << ObtainedAddressFromStream << endl;

  ipfsClient.SafeFileFromIpfsToFile(ObtainedAddressFromStream, "/home/node_a/Pulpit/ImportantData.txt");

  fileList = multichainClient.listChainFiles( chainName, streamName); // fileList is a vector of file names existing in
                              // chain names can repeat themselves
  cout << "Lista plikow:" << endl;
  for (const string &i : fileList) {
    cout << i << endl;
  }
*/

}

void BasicController::onListViewButtonReleased() {
  listViewAreaFiles.clear();
  MultichainClient multichainClient;
  MultichainInitialization multichainInitialization;
  if(multichainInitialization.IsConnected()){
    vector<string> res = multichainClient.listChainFiles(multichainInitialization.chainName, multichainInitialization.streamName);
    auto last = std::unique(res.begin(), res.end());  //
    res.erase(last, res.end());                       //czyszczenie powtarzajacych sie rekordow - przeniesc do funkcji zwracajacej!

    for (size_t i = 0; i < res.size(); i++)
    {
      listViewAreaFiles.push_back(QString::fromStdString(res[i]));
      //cout << res[i] << endl;
    }
  }
  listViewAreaFiles.push_back("File no. 1");
  listViewAreaFiles.push_back("File no. 2");
  emit updateListViewArea();                                                           //tutaj uzupelniam comboboxa
  multichainClient.ClearConsole();
  //customMessageDialogController.showMessageDialog("Update list view area", "List view area has been just updated");
}

void BasicController::onListViewFileSelected(const QString &fileName) {
  customMessageDialogController.showMessageDialog(
    "File selected", "File from list view area has been just selected");
    
  StringFinder stringFinder;
  string tmp = Test::FILE_PROCESS_MESSAGE.arg(fileName).toStdString();
  string tmp2 = "\"";
  string filePath = stringFinder.GetFirstValue(tmp , tmp2 , tmp2);
  // ^ wyciagniecie z komunikatu stringa ze scierzka

  MultichainClient multichainClient;
  IpfsClient ipfsClient;
  string ObtainedAddressFromStream = multichainClient.returnFileAddress(chainName, streamName, filePath);
  ipfsClient.SafeFileFromIpfsToFile(ObtainedAddressFromStream, filePath);
  multichainClient.ClearConsole();
  cout << "Pobrano plik: " << filePath << endl;
}

const QStringList &BasicController::getListViewAreaFiles() const {
  return listViewAreaFiles;
}
