#include <QTest>
#include <QFile>
#include "markdownFileReader.h"

class TestMarkdownFileReader : public QObject
{
    Q_OBJECT

private slots:
    // Test case for reading an existing Markdown file
    void testReadExistingFile()
    {
        // Path to an existing Markdown file
        QString filePath = "data/continuous_deployment_of_qt_wasm_application.md";

        // Create a Markdown file
        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream out(&file);
        out << "# Continuous Deployment of Qt WASM Application\n";
        out << "## Introduction\n";
        out << "This is a sample Markdown file.\n";
        out << "## Conclusion\n";
        out << "This is the end of the sample Markdown file.\n";

        MarkdownFileReader reader(filePath.toStdString());
        QString content = QString::fromStdString(reader.read());

        // Check that the content is not empty
        QVERIFY(!content.isEmpty());
    }

    // Test case for reading a non-existent Markdown file
    void testReadNonExistentFile()
    {
        // Path to a non-existent file
        QString filePath = "path/to/nonexistent/file.md";

        MarkdownFileReader reader(filePath.toStdString());
        QString content = QString::fromStdString(reader.read());

        // Check that the content is empty since the file doesn't exist
        QVERIFY(content.isEmpty());
    }
};

QTEST_APPLESS_MAIN(TestMarkdownFileReader)
#include "test_markdownFileReader.moc"
