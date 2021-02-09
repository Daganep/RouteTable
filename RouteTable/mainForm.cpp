#include "mainForm.h"
#include "addMarsh.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ argv) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    RouteTable::mainForm form; //WinFormsTest - имя вашего проекта
    Application::Run(% form);
    return 0;
}