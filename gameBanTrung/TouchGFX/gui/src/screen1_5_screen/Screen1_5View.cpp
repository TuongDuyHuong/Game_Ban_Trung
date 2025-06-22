#include <gui/screen1_5_screen/Screen1_5View.hpp>


Screen1_5View::Screen1_5View()
{

}

void Screen1_5View::setupScreen()
{
    Screen1_5ViewBase::setupScreen();
}

void Screen1_5View::tearDownScreen()
{
    Screen1_5ViewBase::tearDownScreen();
}
// void set_clasic_mode()
// {
//     gameMode = 0;
//     number_of_lines = 5;
// }
// void set_new_mode()
// {
//     gameMode = 1;
// }
void Screen1_5View::set_classic_mode()
{
    gameMode = 0;
    number_of_lines = 5;
}
void Screen1_5View::set_new_mode()
{
    gameMode = 1;
}