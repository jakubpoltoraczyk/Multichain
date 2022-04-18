#include "basiccontroller.h"

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  QQmlApplicationEngine engine;

  BasicController basicController;

  auto objectsToRegister = basicController.getObjectsToRegister();
  for (const auto &[registerName, registerObject] : objectsToRegister) {
    engine.rootContext()->setContextProperty(registerName, registerObject);
  }

  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  return engine.rootObjects().isEmpty() ? -1 : app.exec();
}
