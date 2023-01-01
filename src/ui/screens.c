#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "styles.h"
#include "ui.h"

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_main_checkbox_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
        if (tick_value_change_obj != ta) {
            assignBooleanProperty(0, 1, 2, value, "Failed to assign Checked state");
        }
    }
}

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.checkbox_1 = obj;
            lv_obj_set_pos(obj, 129, 204);
            lv_obj_set_size(obj, 125, 20);
            lv_checkbox_set_text(obj, " direct var");
            lv_obj_add_event_cb(obj, event_handler_cb_main_checkbox_1, LV_EVENT_ALL, 0);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_1 = obj;
            lv_obj_set_pos(obj, 110, 172);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_2 = obj;
            lv_obj_set_pos(obj, 110, 134);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        }
    }
}

void tick_screen_main() {
    {
        bool new_val = evalBooleanProperty(0, 1, 2, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.checkbox_1, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.checkbox_1;
            if (new_val) lv_obj_add_state(objects.checkbox_1, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.checkbox_1, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(0, 0, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_1;
            lv_label_set_text(objects.label_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(0, 2, 2, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_2);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_2;
            lv_label_set_text(objects.label_2, new_val);
            tick_value_change_obj = NULL;
        }
    }
}


void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
