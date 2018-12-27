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

ret_t demo_qr_pix_size_changed(void* ctx, event_t* e)
{
  log_debug("-------------------------");
  
  widget_t *i_pix_size = (widget_t *)ctx;
  log_debug("----%d----\r\n",edit_get_int(i_pix_size));
  // widget_t *q_qr_code = widget_lookup_all(qr_test, "qr_code", TRUE);
  // qr_set_pixsize(q_qr_code, edit_get_int(i_pix_size));
  return RET_OK;
}

ret_t awtk_demo_qr() 
{
  widget_factory_register(widget_factory(), WIDGET_TYPE_QR, qr_create);
  widget_t *qr_test = window_open("qr_test");

  widget_t *i_pix_size = widget_lookup(qr_test, "i_pix_size", TRUE);
  widget_on(i_pix_size, EVT_VALUE_CHANGED, demo_qr_pix_size_changed, (void *)i_pix_size);
  // install_click_hander(index);
  
  // timer_add(awtk_get_currtime, system_bar, 0);
  return RET_OK;
}
