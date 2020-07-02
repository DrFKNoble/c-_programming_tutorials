#include <QCoreApplication>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QString>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // File input and output using standard library

    // Basic file input and output

    std::cout << "1. Basic file input and output" << std::endl;

    std::ofstream outputFile;

    outputFile.open("myFile.txt");

    std::string outputToFile = "This string will be written to a file.";

    outputFile << outputToFile << std::endl;

    outputFile.close();

    std::ifstream inputFile;

    inputFile.open("myFile.txt");

    std::string inputFromFile = "";

    std::getline(inputFile, inputFromFile);

    inputFile.close();

    std::cout << "The following was read from the file: " << std::endl;
    std::cout << inputFromFile << std::endl;

    std::cout << std::endl;

    // Advanced file input and output

    std::cout << "2. Advanced file input and output with the standard library." << std::endl;

    std::string fileName = "myFile.txt";

    std::filesystem::path executablePath = std::filesystem::path(argv[0]);
    std::filesystem::path parentPath = executablePath.parent_path();

    std::filesystem::path filePath = parentPath / fileName;

    std::cout << "The executable's path is: " << std::endl;
    std::cout << executablePath.string() << std::endl;

    std::cout << "The executable's parent path is: " << std::endl;
    std::cout << parentPath.string() << std::endl;

    std::cout << "The file's path is: " << std::endl;
    std::cout << filePath.string() << std::endl;

    // Write to file

    std::string writeMessage = "Writing to and reading from a file using the standard library.";

    std::fstream toFile = std::fstream(filePath.string(), std::fstream::out);

    toFile << writeMessage;

    toFile.close();

    // Read from file

    std::string readMessage = "";

    std::fstream fromFile = std::fstream(filePath.string(), std::fstream::in);

    std::getline(fromFile, readMessage);

    fromFile.close();

    std::cout << "The following was read from the file: " << std::endl;
    std::cout << readMessage << std::endl;

    std::cout << std::endl;

    // File input and output using the Qt framework

    std::cout << "3. Advanced file input and output with the Qt framework." << std::endl;

    QString qFileName = "myFile.txt";

    QDir qProgramDir = QDir(argv[0]);

    QString qExecutablePath = qProgramDir.absolutePath();

    qProgramDir.cd("..");

    QString qParentPath = qProgramDir.absolutePath();

    QString qFilePath = qParentPath + "/" + qFileName;

    qDebug() << "The executable's path is: ";
    qDebug() << qExecutablePath;

    qDebug() << "The executable's parent path is: ";
    qDebug() << qParentPath;

    qDebug() << "The file's path is: ";
    qDebug() << qFilePath;

    // Write to file

    QString qWriteMessage = "Writing to and reading from a file using the Qt framework.";

    QFile qToFile = QFile(qFilePath);

    if (!qToFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return 1;
    }

    QTextStream out(&qToFile);

    out << qWriteMessage;

    qToFile.close();

    // Read from file

    QString qReadMessage = "";

    QFile qFromFile = QFile(qFilePath);

    if (!qFromFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return 2;
    }

    QTextStream in(&qFromFile);

    qReadMessage = in.readLine();

    qFromFile.close();

    qDebug() << "The following was read from the file: ";
    qDebug() << qReadMessage;

    return a.exec();
}
