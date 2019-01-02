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
 * 2018-12-29 Zhaoqi <zq@zhaoqi.info> update
 *
 */

#ifndef TK_QR_H
#define TK_QR_H

#include "base/widget.h"
#include "qrencode/qrencode.h"

BEGIN_C_DECLS

/**
 * @const WIDGET_PROP_PIX_SIZE
 * 二维码像素映射关系
 */
#define WIDGET_PROP_PIX_SIZE "pix_size"

/**
 * @const WIDGET_PROP_PIX_SIZE
 * 二维码状态被扫描
 */
#define WIDGET_STATE_SCANED "scaned"

/**
 * @const WIDGET_TYPE_QR
 * 二维码
 */
#define WIDGET_TYPE_QR "qr"

/**
 * @const STYLE_ID_MG_COLOR
 * 边框内颜色。
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
   * 二维码编码
   */
  QRcode *qr_code_data;
  /**
   * 二维码每个像素在屏幕上的实际像素
   * (取值范围1-8)
   */
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
 * @method qr_create
 * 创建qr对象
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
 * @method qr_cast
 * 转换为qr对象(供脚本语言使用)。
 * @annotation ["cast", "scriptable"]
 * @param {widget_t*} widget button对象。
 *
 * @return {widget_t*} qr对象。
 */
widget_t* qr_cast(widget_t* widget);

/**
 * @method qr_set_text
 * 设置二维码控件的显示内容
 * @annotation ["scriptable"]
 * @param {widget_t*} widget 控件对象。
 * @param {char *}  显示内容。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t qr_set_text(widget_t* widget, char *text);

/**
 * @method qr_set_pixsize
 * 设置二维码控件的实际像素
 * @annotation ["scriptable"]
 * @param {widget_t*} widget 控件对象。
 * @param {uint8_t }  实际像素。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t qr_set_pixsize(widget_t* widget, uint8_t pixsize);

/**
 * @method qr_get_pixsize
 * 获取二维码控件的实际像素
 * @annotation ["scriptable"]
 * @param {widget_t*} widget 控件对象。
 *
 * @return {ret_t} 二维码控件的实际像素。
 */
uint8_t qr_get_pixsize(widget_t* widget);

#define QR(widget) ((qr_t*)(widget))

END_C_DECLS

#endif /*TK_BUTTON_H*/
