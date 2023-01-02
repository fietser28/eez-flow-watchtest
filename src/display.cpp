
#include <Arduino.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <task.h>
#include <timers.h>
#include <lvgl.h>
#include <TFT_eSPI.h>

#include "ui/ui.h"
#include "main.h"

#define MY_LV_TICK_TIME 20

TFT_eSPI tft = TFT_eSPI(); /* TFT instance */

static void guiTimerFunction( TimerHandle_t xTimer );
static TimerHandle_t guiTimerHandle;

static void guiTask(void *pvParameter);
TaskHandle_t guiTaskHandle;

/*Change to your screen resolution*/
static const uint32_t screenWidth = TFT_WIDTH;
static const uint32_t screenHeight = TFT_HEIGHT;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * 10];

static lv_disp_drv_t disp_drv;
static lv_indev_drv_t indev_drv;     // Touchscreen
      
static void guiTimerFunction( TimerHandle_t tm ) {
  lv_tick_inc(MY_LV_TICK_TIME);
}

void gui_task_init(void)
{

  TimerHandle_t gt;
  guiTimerHandle = xTimerCreate("gut", pdMS_TO_TICKS(MY_LV_TICK_TIME), pdTRUE, NULL, guiTimerFunction);


  xTaskCreate(guiTask, "gui", 4096 * 2, NULL, 3, &guiTaskHandle);

};

/**********************
 *   STATIC FUNCTIONS
 **********************/

/* Display flushing */
static void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  tft.startWrite();
  tft.setAddrWindow(area->x1, area->y1, w, h);
  tft.pushColors((uint16_t *)&color_p->full, w * h, true);
  tft.endWrite();

  lv_disp_flush_ready(disp);
}

/*Read the touchpad*/
static void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{

  uint16_t touchX, touchY;

  bool touched = tft.getTouch(&touchX, &touchY, 600);

  if (!touched)
  {
    data->state = LV_INDEV_STATE_REL;
  }
  else
  {
    data->state = LV_INDEV_STATE_PR;

    // Set the coordinates (note the rotation X <-> Y, also scaled...)
    data->point.x = 320 - (touchX * 4) / 3;
    data->point.y = 240 - (touchY * 3) / 4;
  }
}

static void guiTask(void *pvParameter)
{
      lv_init();

      tft.begin();        /* TFT init */
      tft.setRotation(3); /* Landscape orientation, flipped */
      tft.initDMA();
      /*Set the touchscreen calibration data,
        the actual data for your display can be aquired using
        the Generic -> Touch_calibrate example from the TFT_eSPI library*/
      //  uint16_t calData[5] = { 275, 3620, 264, 3532, 1 };
      //  tft.setTouch( calData );

      lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * 10);

      /*Initialize the display*/
      lv_disp_drv_init(&disp_drv);
      disp_drv.hor_res = screenWidth;
      disp_drv.ver_res = screenHeight;
      disp_drv.flush_cb = my_disp_flush;
      disp_drv.draw_buf = &draw_buf;
      lv_disp_drv_register(&disp_drv);

      /*Initialize the input device driver for touchpad*/
      lv_indev_drv_init(&indev_drv);
      indev_drv.type = LV_INDEV_TYPE_POINTER;
      indev_drv.read_cb = my_touchpad_read;
      lv_indev_drv_register(&indev_drv);
  
      //  Set to 1 if you do not see any GUI, for testing display/HW setup
#if 0
   /* Create simple label */
   lv_obj_t *label = lv_label_create( lv_scr_act() );
   lv_label_set_text( label, "Hello world!" );
   lv_obj_align( label, LV_ALIGN_CENTER, 0, 0 );
#else
      // EEZ GUI init
      ui_init();
#endif

  xTimerStart(guiTimerHandle, 0);

  while (1)
  {
    vTaskDelay(pdMS_TO_TICKS(MY_LV_TICK_TIME));
//        lv_tick_inc(MY_LV_TICK_TIME);   // Moved to task seperate from ui_tick().
        lv_task_handler();
        ui_tick();
  }
}
