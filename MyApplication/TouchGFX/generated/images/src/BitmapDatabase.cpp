// 4.25.0 0xb6fc8980
// Generated by imageconverter. Please, do not edit!

#include <images/BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>

extern const unsigned char image_a1[]; // BITMAP_A1_ID = 0, Size: 240x320 pixels
extern const unsigned char image_a2[]; // BITMAP_A2_ID = 1, Size: 240x320 pixels
extern const unsigned char image_egg_blue[]; // BITMAP_EGG_BLUE_ID = 2, Size: 32x32 pixels
extern const unsigned char image_egg_green[]; // BITMAP_EGG_GREEN_ID = 3, Size: 32x32 pixels
extern const unsigned char image_egg_red[]; // BITMAP_EGG_RED_ID = 4, Size: 32x32 pixels
extern const unsigned char image_egg_yellow[]; // BITMAP_EGG_YELLOW_ID = 5, Size: 32x32 pixels
extern const unsigned char image_gun[]; // BITMAP_GUN_ID = 6, Size: 64x96 pixels
extern const unsigned char image_icon_theme_images_action_done_50_50_e8f6fb_svg[]; // BITMAP_ICON_THEME_IMAGES_ACTION_DONE_50_50_E8F6FB_SVG_ID = 7, Size: 50x50 pixels
extern const unsigned char image_icon_theme_images_action_home_30_30_ffffff_svg[]; // BITMAP_ICON_THEME_IMAGES_ACTION_HOME_30_30_FFFFFF_SVG_ID = 8, Size: 30x30 pixels
extern const unsigned char image_icon_theme_images_toggle_radio_button_checked_50_50_ffffff_svg[]; // BITMAP_ICON_THEME_IMAGES_TOGGLE_RADIO_BUTTON_CHECKED_50_50_FFFFFF_SVG_ID = 9, Size: 50x50 pixels
extern const unsigned char image_icon_theme_images_toggle_radio_button_unchecked_50_50_ffffff_svg[]; // BITMAP_ICON_THEME_IMAGES_TOGGLE_RADIO_BUTTON_UNCHECKED_50_50_FFFFFF_SVG_ID = 10, Size: 50x50 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] = {
    { image_a1, 0, 240, 320, 0, 0, 240, ((uint8_t)touchgfx::Bitmap::RGB565) >> 3, 320, ((uint8_t)touchgfx::Bitmap::RGB565) & 0x7 },
    { image_a2, 0, 240, 320, 0, 0, 240, ((uint8_t)touchgfx::Bitmap::RGB565) >> 3, 320, ((uint8_t)touchgfx::Bitmap::RGB565) & 0x7 },
    { image_egg_blue, 0, 32, 32, 6, 7, 20, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 20, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_egg_green, 0, 32, 32, 6, 7, 20, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 20, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_egg_red, 0, 32, 32, 6, 7, 20, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 20, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_egg_yellow, 0, 32, 32, 6, 7, 20, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 18, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_gun, 0, 64, 96, 21, 17, 24, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 70, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_icon_theme_images_action_done_50_50_e8f6fb_svg, 0, 50, 50, 16, 33, 4, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 3, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_icon_theme_images_action_home_30_30_ffffff_svg, 0, 30, 30, 6, 12, 2, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 12, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_icon_theme_images_toggle_radio_button_checked_50_50_ffffff_svg, 0, 50, 50, 17, 17, 14, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 14, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_icon_theme_images_toggle_radio_button_unchecked_50_50_ffffff_svg, 0, 50, 50, 40, 18, 3, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 12, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 }
};

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance()
{
    return bitmap_database;
}

uint16_t getInstanceSize()
{
    return (uint16_t)(sizeof(bitmap_database) / sizeof(touchgfx::Bitmap::BitmapData));
}
} // namespace BitmapDatabase
