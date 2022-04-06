#include "basiccontroller.h"

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  QQmlApplicationEngine engine;

  BasicController basicController;

  auto objectsToRegister = basicController.getObjectsToRegister();
  for (const auto &object : objectsToRegister) {
    engine.rootContext()->setContextProperty(object.first, object.second);
  }

  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  return engine.rootObjects().isEmpty() ? -1 : app.exec();
}
