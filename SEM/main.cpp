#include <Windows.h>
#include "SEMmainForm.h"

using namespace SEM;
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<System::String ^> ^args)
{
	// Включение визуальных эффектов Windows XP до создания каких-либо элементов управления
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Создание главного окна и его запуск
	SEMmainForm^ form = gcnew SEMmainForm();
	Application::Run(form);

	return 0;
}