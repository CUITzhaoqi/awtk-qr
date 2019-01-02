/**
 * File:   demo1_app.c
 * Author: AWTK Develop Team
 * Brief:  basic class of all widget
 *
 * Copyright (c) 2018 - 2018  Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2018-02-16 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "awtk.h"
#include "tkc/mem.h"
#include "widgets/label.h"
#include "base/timer.h"
#include "widgets/button.h"
#include "widgets/dialog.h"
#include "widgets/image.h"
#include "tkc/utils.h"
#include "widgets/window.h"
#include "tkc/time_now.h"
#include "base/main_loop.h"
#include "base/locale_info.h"
#include "widgets/check_button.h"
#include "widgets/progress_bar.h"
#include "base/image_manager.h"
#include "base/window_manager.h"
#include "base/widget_factory.h"
#include "ui_loader/ui_builder_default.h"
#include "ext_widgets.h"
#include "qr/qr.h"

widget_t *qr_test = NULL;

static ret_t demo_qr_pix_size_changed(void* ctx, event_t* e)
{  
  widget_t *i_pix_size = (widget_t *)ctx;

  widget_t *q_qr_code = widget_lookup(qr_test, "qr_code", TRUE);
  qr_set_pixsize(q_qr_code, edit_get_int(i_pix_size));
  return RET_OK;
}

static ret_t demo_qr_text_changed(void* ctx, event_t* e)
{  
  widget_t *i_text = (widget_t *)ctx;

  char *display_text = TKMEM_ALLOC(i_text->text.capacity);
  if (display_text != NULL) {
    wstr_get_utf8(&(i_text->text), display_text, i_text->text.capacity);

    widget_t *q_qr_code = widget_lookup(qr_test, "qr_code", TRUE);
    qr_set_text(q_qr_code, display_text);
    TKMEM_FREE(display_text);
  }
  
  return RET_OK;
}

static ret_t demo_qr_state_changed(void* ctx, event_t* e)
{  
  widget_t *b_stat_change = (widget_t *)ctx;

  widget_t *q_qr_code = widget_lookup(qr_test, "qr_code", TRUE);

  if (tk_str_eq(q_qr_code->state, WIDGET_STATE_SCANED)) {
    widget_set_state(q_qr_code, WIDGET_STATE_NORMAL);
  } else if (tk_str_eq(q_qr_code->state, WIDGET_STATE_NORMAL)) {
    widget_set_state(q_qr_code, WIDGET_STATE_SCANED);
  }

  return RET_OK;
}

static ret_t demo_qr_gen_by_code(void* ctx, event_t* e)
{
  widget_t *b_stat_change = (widget_t *)ctx;

  widget_set_enable(b_stat_change, FALSE);

  widget_t *q_qr_code = widget_lookup(qr_test, "qr_code", TRUE);

  widget_t *qr_view = widget_lookup(qr_test, "qr_view", TRUE);

  widget_t *new_qr_code = qr_create(qr_view, 0, 0, 0, 0);
  qr_set_pixsize(new_qr_code, 3);
  qr_set_text(new_qr_code, "致远电子");
  widget_set_self_layout_params(new_qr_code, "c", "50%", "50%", "50%");
  widget_set_name(new_qr_code, "new_qr_code");
  widget_use_style(new_qr_code, "qr_border");

  widget_t *b_des_by_code = widget_lookup(qr_test, "des_by_code", TRUE);
  widget_set_enable(b_des_by_code, TRUE);

  return RET_OK;
}

static ret_t demo_qr_des_by_code(void* ctx, event_t* e)
{
  widget_t *b_stat_change = (widget_t *)ctx;
  widget_set_enable(b_stat_change, FALSE);

  widget_t *qr_view = widget_lookup(qr_test, "qr_view", TRUE);
  widget_t *new_qr_code = widget_lookup(qr_view, "new_qr_code", TRUE);
  widget_destroy(new_qr_code);

  widget_t *b_gen_by_code = widget_lookup(qr_test, "gen_by_code", TRUE);
  widget_set_enable(b_gen_by_code, TRUE);

  return RET_OK;
}


static ret_t demo_qr_hide_qr(void* ctx, event_t* e)
{
  widget_t *b_hide_qr = (widget_t *)ctx;

  widget_t *q_qr_code = widget_lookup(qr_test, "qr_code", TRUE);
  widget_set_visible(q_qr_code, !q_qr_code->visible, FALSE);
  if (q_qr_code->visible) {
    widget_set_text_utf8(b_hide_qr, "show_qr");
  } else {
    widget_set_text_utf8(b_hide_qr, "hide_qr");
  }

  return RET_OK;
}

static ret_t on_show_fps(void* ctx, event_t* e) {
  widget_t* button = WIDGET(ctx);
  widget_t* widget = window_manager();
  window_manager_t* wm = WINDOW_MANAGER(widget);

  widget_invalidate(widget, NULL);
  window_manager_set_show_fps(widget, !wm->show_fps);
  if (wm->show_fps) {
    widget_set_text_utf8(button, "hide_fps");
  } else {
    widget_set_text_utf8(button, "show_fps");
  }
  

  return RET_OK;
}

static ret_t timer_preload(const timer_info_t* timer) {
  widget_t* win = WIDGET(timer->ctx);
  tk_mem_dump();

  return RET_REPEAT;
}

ret_t awtk_demo_qr() 
{
  widget_factory_register(widget_factory(), WIDGET_TYPE_QR, qr_create);
  qr_test = window_open("qr_test");

  widget_t *qr_qr_code = widget_lookup(qr_test, "qr_code", TRUE);

  widget_t *i_pix_size = widget_lookup(qr_test, "i_pix_size", TRUE);
  edit_set_int(i_pix_size, qr_get_pixsize(qr_qr_code));
  widget_on(i_pix_size, EVT_VALUE_CHANGED, demo_qr_pix_size_changed, (void *)i_pix_size);
  
  widget_t *i_text = widget_lookup(qr_test, "i_text", TRUE);
  widget_on(i_text, EVT_VALUE_CHANGED, demo_qr_text_changed, (void *)i_text);
 
  widget_t *b_stat_change = widget_lookup(qr_test, "stat_change", TRUE);
  widget_on(b_stat_change, EVT_CLICK, demo_qr_state_changed, (void *)b_stat_change);
 
  widget_t *b_gen_by_code = widget_lookup(qr_test, "gen_by_code", TRUE);
  widget_on(b_gen_by_code, EVT_CLICK, demo_qr_gen_by_code, (void *)b_gen_by_code);

  widget_t *b_show_fps = widget_lookup(qr_test, "show_fps", TRUE);
  widget_on(b_show_fps, EVT_CLICK, on_show_fps, (void *)b_show_fps);

  widget_t *b_hide_qr = widget_lookup(qr_test, "hide_qr", TRUE);
  widget_on(b_hide_qr, EVT_CLICK, demo_qr_hide_qr, (void *)b_hide_qr);

  widget_t *b_des_by_code = widget_lookup(qr_test, "des_by_code", TRUE);
  widget_on(b_des_by_code, EVT_CLICK, demo_qr_des_by_code, (void *)b_des_by_code);
  widget_set_enable(b_des_by_code, FALSE);

  timer_add(timer_preload, qr_test, 1000);

  return RET_OK;
}
