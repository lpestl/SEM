#include <Windows.h>
#include "SEMmainForm.h"

using namespace SEM;
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<System::String ^> ^args)
{
	// ��������� ���������� �������� Windows XP �� �������� �����-���� ��������� ����������
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// �������� �������� ���� � ��� ������
	SEMmainForm^ form = gcnew SEMmainForm();
	Application::Run(form);

	return 0;
}