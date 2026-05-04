#pragma once

// =====================================================
// TFT_eSPI PASSIVE CONFIG (Pin dikontrol dari general.ini)
// =====================================================

// Wajib supaya TFT_eSPI tidak pakai config default lain
#define USER_SETUP_LOADED

// Driver sesuai general.ini
#define ILI9341_DRIVER

// Resolusi sesuai general.ini
#define TFT_WIDTH  240
#define TFT_HEIGHT 320

// Warna (ganti ke TFT_RGB kalau kebalik)
#define TFT_RGB_ORDER TFT_RGB

// SPI Speed (sinkron sama general.ini)
#define SPI_FREQUENCY       27000000
#define SPI_READ_FREQUENCY  20000000
#define SPI_TOUCH_FREQUENCY 2500000

// Font halus
#define SMOOTH_FONT
