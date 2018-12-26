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

ret_t awtk_set_locale_simplified_chinese()
{
  char country[3];
  char language[3];
  const char* str = (const char*)"zh_CN";
  strncpy(language, str, 2);
  strncpy(country, str + 3, 2);
  return locale_info_change(locale_info(), language, country);
}

static ret_t awtk_set_locale_traditional_chinese()
{
  char country[3];
  char language[3];
  const char* str = (const char*)"zh_TW";
  strncpy(language, str, 2);
  strncpy(country, str + 3, 2);
  return locale_info_change(locale_info(), language, country);
}

static ret_t awtk_set_locale_japan()
{
  char country[3];
  char language[3];
  const char* str = (const char*)"ja_JP";
  strncpy(language, str, 2);
  strncpy(country, str + 3, 2);
  return locale_info_change(locale_info(), language, country);
}

static ret_t awtk_set_locale_korea()
{
  char country[3];
  char language[3];
  const char* str = (const char*)"ko_KR";
  strncpy(language, str, 2);
  strncpy(country, str + 3, 2);
  return locale_info_change(locale_info(), language, country);
}

static ret_t awtk_set_locale_english()
{
  char country[3];
  char language[3];
  const char* str = (const char*)"en_US";
  strncpy(language, str, 2);
  strncpy(country, str + 3, 2);
  return locale_info_change(locale_info(), language, country);
}

ret_t locale_application_init() {
  widget_t *win = window_open("gvs_main");

  // assets_manager_t* rm = assets_manager();
  // assets_manager_load(rm, ASSET_TYPE_FONT, "digifaw");

  assets_manager_t* rm = assets_manager();
  assets_manager_load(rm, ASSET_TYPE_FONT, "default");

  //awtk_set_locale_chinese();
  // awtk_set_locale_japan();
  //awtk_set_locale_korea();
  awtk_set_locale_simplified_chinese();
  widget_t *lab = NULL;
  lab = widget_lookup(win, "dis_ifname", TRUE);
  if (lab != NULL) {
    log_debug("123\r\n");
    // widget_use_style(lab, "center_dig");
    /* 注意:此处的 widget_set_text_utf8 的编码 需为 utf-8 */
    // widget_set_text_utf8(lab, "123");

    char tr_str[64];
    int value = 123;

    awtk_set_locale_simplified_chinese();
    const char* format = locale_info_tr(locale_info(), "中文 %d");
    snprintf(tr_str, sizeof(tr_str), format, value);
    log_debug(tr_str);
    widget_set_text(lab, tr_str);
  }
  return RET_OK;
}
