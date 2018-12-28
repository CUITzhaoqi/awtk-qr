/**
 * File:   qr.h
 * Author: AWTK Develop Team
 * Brief:  qr
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
 * 2018-12-19 Zhaoqi <zq@zhaoqi.info> created
 *
 */

#ifndef TK_QR_H
#define TK_QR_H

#include "base/widget.h"
#include "lib/qrencode/qrencode.h"

BEGIN_C_DECLS

/**
 * @const WIDGET_PROP_PIX_SIZE
 * 二维码像素映射关系
 */
#define WIDGET_PROP_PIX_SIZE "pix_size"

/**
 * @const WIDGET_PROP_PIX_SIZE
 * 二维码像素映射关系
 */
#define WIDGET_STATE_SCANED "scaned"

/**
 * @const WIDGET_TYPE_QR
 *
 */
#define WIDGET_TYPE_QR "qr"

/**
 * @const STYLE_ID_MARGIN
 * 边距。
 */
#define STYLE_ID_MG_COLOR "mg_color"



/**
 * @class qr_t
 * @parent widget_t
 * @annotation ["scriptable"]
 * 按钮控件。
 */
typedef struct _qr_t {
  widget_t widget;
  /**
   * 二维码每个像素在屏幕上的实际像素
   * (取值范围1-8)
   */
  QRcode *qr_code_data;
  /**
   * 二维码每个像素在屏幕上的实际像素
   * (取值范围1-8)
   */

  bitmap_t image;

  uint8_t pix_size;
  /**
   * 二维码内容
   */
  char *  qr_text;
  /**
   * 二维码宽度
   */
  uint16_t qr_width;
  /**
   * 是否有效
   * (标识二维码是否有效)
   */
  bool_t  isvalid;
} qr_t;

/**
 * @event {pointer_event_t} EVT_CLICK
 * 点击事件。
 */

/**
 * @event {pointer_event_t} EVT_LONG_PRESS
 * 长按事件。
 */

/**
 * @method button_create
 * 创建button对象
 * @annotation ["constructor", "scriptable"]
 * @param {widget_t*} parent 父控件
 * @param {xy_t} x x坐标
 * @param {xy_t} y y坐标
 * @param {wh_t} w 宽度
 * @param {wh_t} h 高度
 *
 * @return {widget_t*} 对象。
 */
widget_t* qr_create(widget_t* parent, xy_t x, xy_t y, wh_t w, wh_t h);

/**
 * @method button_cast
 * 转换为button对象(供脚本语言使用)。
 * @annotation ["cast", "scriptable"]
 * @param {widget_t*} widget button对象。
 *
 * @return {widget_t*} button对象。
 */
widget_t* qr_cast(widget_t* widget);

/**
 * @method button_set_repeat
 * 设置释放EVT_CLICK事件的时间间隔。为0则不重复释放EVT_CLICK事件。
 * @annotation ["scriptable"]
 * @param {widget_t*} widget 控件对象。
 * @param {int32_t}  repeat 释放EVT_CLICK事件的时间间隔(毫秒)。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t qr_set_repeat(widget_t* widget, int32_t repeat);

ret_t qr_set_text(widget_t* widget, char *text);

ret_t qr_set_pixsize(widget_t* widget, uint8_t pixsize);

#define QR(widget) ((qr_t*)(widget))

END_C_DECLS

#endif /*TK_BUTTON_H*/
