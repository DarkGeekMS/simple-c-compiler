
import sys
import subprocess

# 1. Import `QApplication` and all the required widgets
from PyQt5.QtWidgets import QApplication, QLabel, QWidget, QFileDialog, QPushButton, QHBoxLayout, QVBoxLayout, QMainWindow, QLineEdit, QTextEdit, QGridLayout
from PyQt5.QtGui import QColor, QIcon
from PyQt5 import QtWidgets, QtGui, QtCore

class MyWindow(QWidget):
    def __init__(self):
        super(MyWindow,self).__init__()
        self.file = ""
        self.output = ""
        self.output_dir = ""
        self.initUI()

    def initUI(self):
        self.setGeometry(700, 700, 800, 800)
        self.setWindowTitle("C/C++ Compiler")
        self.layout = QVBoxLayout()


        # input file browse section
        self.inBrowseButton = QPushButton('Browse .cpp file')
        self.inBrowseButton.setStyleSheet("""
            QPushButton{
                  background-color: #5dc97d; /* Green */
                border: none;
                color: white;
                padding: 5px 5px;
                text-align: center;
                text-decoration: none;
                font-size: 16px;
                border-radius: 5px;
            }
            QPushButton:hover {
                background-color: white; /* Green */
                color: #5dc97d;
                }
            """)
        self.inFileBox = QLineEdit(self.file)
        self.inBrowseButton.clicked.connect(self.browseFile)
        # input directory browse section
        self.outBrowseButton = QPushButton('Browse Output Directory')
        self.outBrowseButton.setStyleSheet("""
            QPushButton{
                  background-color: #5dc97d; /* Green */
                border: none;
                color: white;
                padding: 5px 5px;
                text-align: center;
                text-decoration: none;
                font-size: 16px;
                border-radius: 5px;
            }
            QPushButton:hover {
                background-color: white; /* Green */
                color: #5dc97d;
                }
            """)
        self.outFileBox = QLineEdit(self.file)
        self.outBrowseButton.clicked.connect(self.browseDir)

        # browse layouts
        self.browseLayout = QGridLayout()
        self.browseLayout.addWidget(self.inFileBox, 0, 0)
        self.browseLayout.addWidget(self.inBrowseButton, 0, 1)
        self.browseLayout.addWidget(self.outFileBox, 1, 0)
        self.browseLayout.addWidget(self.outBrowseButton, 1, 1)
        self.layout.addLayout(self.browseLayout)



        # compile
        self.compileButton = QPushButton('')
        self.compileButton.setIcon(QIcon("compile.png")) #icon
        self.compileButton.setStyleSheet("""
            QPushButton{
                  background-color: #ccebd5; /* Green */
                border: none;
                padding: 5px 5px;
                text-align: center;
                text-decoration: none;
                font-size: 13px;
            }
            QPushButton:hover {
                background-color: white; /* Green */
                }
            """)

        self.layout.addWidget(self.compileButton)
        self.compileButton.clicked.connect(self.compile)


        # outputs
        self.symbolTableLabel = QLabel('Symbol Tables:', self)
        self.layout.addWidget(self.symbolTableLabel)
        self.symbolTable = QTextEdit()
        self.symbolTable.setDisabled(True)
        self.symbolTable.setTextColor(QColor(0,0,255))
        self.layout.addWidget(self.symbolTable)

        self.errorsLabel = QLabel('Errors:', self)
        self.layout.addWidget(self.errorsLabel)
        self.errorBox = QTextEdit()
        self.errorBox.setDisabled(True)
        self.errorBox.setTextColor(QColor(255,0,0))
        self.layout.addWidget(self.errorBox)


        self.setLayout(self.layout)


    def browseFile(self):
        qfd = QFileDialog()
        path = "./"
        filter = "cpp(*.cpp)"
        self.file = QFileDialog.getOpenFileName(qfd, "", path, filter)[0]
        self.inFileBox.setText(self.file)

    def browseDir(self):
        filter = "(*)"
        dialog = QtWidgets.QFileDialog(self, 'Folders', "./", filter)
        dialog.setFileMode(QtWidgets.QFileDialog.DirectoryOnly)
        if dialog.exec_() == QtWidgets.QDialog.Accepted:
            self.output_dir = dialog.selectedFiles()[0]
        self.outFileBox.setText(self.output_dir)

    def compile(self):
        self.symbolTable.setPlainText("")
        self.errorBox.setPlainText("")
        output = subprocess.run(["./cpp.out", self.file, self.output_dir], capture_output=True, universal_newlines=True)
        output_lines = str(output.stdout).split('\n')
        errors = []
        symbols = []
        for i in output_lines:
            if ("line [" in i) or ("Please Enter a valid" in i):
                errors.append(i)
            else:
                symbols.append(i)
        for i in symbols:
            self.symbolTable.append(i)
        for i in errors:
            self.errorBox.append(i)


f=open("styles.css", "r")
stylesheet = f.read()
f.close()

app = QApplication(sys.argv)
win = MyWindow()
# win.setStyleSheet(stylesheet)
win.setStyleSheet("""
    QPushButton{
        background-color: #4e4e4e;
        color: #ffffff;
        position: absolute;
        top: 100px;
        left: 100px;
    }
    """)
win.show()
sys.exit(app.exec_())
