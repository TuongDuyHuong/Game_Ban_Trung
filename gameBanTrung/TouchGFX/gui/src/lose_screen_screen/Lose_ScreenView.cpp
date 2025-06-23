#include <gui/lose_screen_screen/Lose_ScreenView.hpp>
#include <gui/screen2_screen/Screen2View.hpp>
Lose_ScreenView::Lose_ScreenView()
{

}

void Lose_ScreenView::setupScreen()
{
    Lose_ScreenViewBase::setupScreen();
    printScore(finalScore);
}

void Lose_ScreenView::tearDownScreen()
{
    Lose_ScreenViewBase::tearDownScreen();
}
void Lose_ScreenView::printScore(int score)
{
    Unicode::snprintf(txtBuffer1, POINT_SIZE, "%d", score);
    point.setWildcard(txtBuffer1);
    point.invalidate();
}
