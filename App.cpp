//
// Created by Tiziano Wu on 13/09/24.
//

#include "App.h"
#include "Mainframe.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    MainFrame* mainframe = new MainFrame("");
    mainframe->SetClientSize(1200,700);
    mainframe->Center();
    mainframe->Show();
    return true;
}