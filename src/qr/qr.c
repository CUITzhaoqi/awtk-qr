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

#include "tkc/mem.h"
#include "base/timer.h"
#include "tkc/utils.h"
#include "qr.h"
#include "base/widget_vtable.h"


static ret_t qr_on_repeat(const timer_info_t* info) {
  pointer_event_t evt;
  qr_t* button = QR(info->ctx);
  widget_t* widget = WIDGET(info->ctx);

  return RET_REPEAT;
}

static ret_t qr_pointer_up_cleanup(widget_t* widget) {
  qr_t* button = QR(widget);
  

  return RET_OK;
}

static ret_t qr_on_event(widget_t* widget, event_t* e) {
  uint16_t type = e->type;
  qr_t* button = QR(widget);

  switch (type) {
    case EVT_AFTER_PAINT:
      log_debug("evt_name:%s \r\n", "EVT_AFTER_PAINT");
      break;
    case EVT_BEFORE_PAINT:
      log_debug("evt_name:%s \r\n", "EVT_BEFORE_PAINT");
      break;
    case EVT_PAINT:
      log_debug("evt_name:%s \r\n", "EVT_PAINT");
      break;
    default:
      break;
  }

  return RET_OK;
}

static ret_t qr_get_prop(widget_t* widget, const char* name, value_t* v) {
  return_value_if_fail(widget != NULL && name != NULL && v != NULL, RET_BAD_PARAMS);
  qr_t* qr = QR(widget);

  if (tk_str_eq(name, WIDGET_PROP_TEXT)) {
    value_set_str (v, qr->qr_text);
    return RET_OK;
  } else if (tk_str_eq(name, WIDGET_PROP_PIX_SIZE)) {
    value_set_int8(v, qr->pix_size);
    return RET_OK;
  }

  return RET_NOT_FOUND;
}

static ret_t qr_set_prop(widget_t* widget, const char* name, const value_t* v) {
  return_value_if_fail(widget != NULL && name != NULL && v != NULL, RET_BAD_PARAMS);
  qr_t* qr = QR(widget);
  log_debug("name:%s value:%d\r\n", name, value_int(v));

  if (tk_str_eq(name, WIDGET_PROP_PIX_SIZE)) {
    return qr_set_pixsize(widget, value_int(v));
  } else if (tk_str_eq(name, WIDGET_PROP_TEXT)) {
    return qr_set_text(widget, value_str(v));
  }

  return RET_NOT_FOUND;
}

static ret_t qr_destroy(widget_t* widget) {
  qr_t* qr = QR(widget);


  return RET_OK;
}

ret_t qr_set_text(widget_t* widget, char *text)
{
  return_value_if_fail(widget != NULL && text != NULL, RET_BAD_PARAMS);
  qr_t* qr = QR(widget);
  char* qr_text = TKMEM_ZALLOCN(char, strlen(text) + 1);
  memcpy(qr_text, text, strlen(text));
  qr->qr_text = qr_text;
  return RET_OK;
}

ret_t qr_set_pixsize(widget_t* widget, uint8_t pixsize)
{
  return_value_if_fail(widget != NULL, RET_BAD_PARAMS);
  qr_t* qr = QR(widget);
  qr->pix_size = pixsize;

  return RET_OK;
}

static ret_t qr_on_paint_self(widget_t* widget, canvas_t* c) {
  log_debug("test!");
  qr_t* qr = QR(widget);
  // if (widget->state == WIDGET_STATE_NORMAL){
    if (qr->qr_text != NULL) {
      QRcode *qr_code;
      style_t* style = widget->astyle;
      int32_t margin = style_get_int(style, STYLE_ID_MARGIN, 2);
      int y = 0, x = 0, a = 0, b = 0;
      qr_code = qr->qr_code_data;
      widget_ungrab(widget->parent, widget);
      if (qr->scaned == FALSE) {
        for(y = 0; y < qr_code->width; y++) {
          for(x = 0; x < qr_code->width; x++) {
            if(qr_code->data[y * qr_code->width + x] & 0x01)  {
              /* 画黑色矩形 */
              canvas_set_fill_color(c, color_init(0x00, 0x00, 0x00, 0xff));
            } else {
              /* 画白色矩形 */
              canvas_set_fill_color(c, color_init(0xff, 0xff, 0xff, 0xff));   
            }
            canvas_fill_rect(c, x * qr->pix_size + margin, y * qr->pix_size + margin, qr->pix_size, qr->pix_size);
          }
        }
      } else if (qr->scaned == TRUE) {

      }
      widget->dirty = TRUE;
    }
  // }

  return widget_paint_helper(widget, c, NULL, NULL);
}

static ret_t qr_on_paint_border(widget_t* widget, canvas_t* c) {
  log_debug("\r\ntest2\r\n");
  // if (widget->state == WIDGET_STATE_NORMAL){
    qr_t* qr = QR(widget);

    color_t trans = color_init(0, 0, 0, 0);
    style_t* style = widget->astyle;
    int32_t margin = style_get_int(style, STYLE_ID_MARGIN, 2);
    color_t margin_color = style_get_color(style, STYLE_ID_BG_COLOR, trans);
    const char* logo_image_name = style_get_str(style, STYLE_ID_FG_IMAGE, NULL);
    bitmap_t img;
    rect_t r;
    
    // x = (0 - widget->w) / 2 + x;
    QRcode *qr_code;
    qr_code = qr->qr_code_data;

    /* 边框颜色 */
    if (margin > 0) {
      /* 根据style 设置边框颜色 */
      canvas_set_fill_color(c, margin_color);   
      /* 上 */
      canvas_fill_rect(c, 0, 0, margin + qr_code->width * qr->pix_size, margin);
      /* 右 */  
      canvas_fill_rect(c, margin + qr_code->width * qr->pix_size, 0, margin, margin + qr_code->width * qr->pix_size);  
      /* 下 */  
      canvas_fill_rect(c, margin, margin + qr_code->width * qr->pix_size, margin + qr_code->width * qr->pix_size, margin); 
      /* 左 */  
      canvas_fill_rect(c, 0, margin, margin, margin + qr_code->width * qr->pix_size); 
    }

    /* 二维码的logo图片 */
    r = rect_init(0 + margin + (qr_code->width / 5) * 2.5 * qr->pix_size , 0 + margin + (qr_code->width / 5) * 2 * qr->pix_size, (qr_code->width / 4) * qr->pix_size, (qr_code->width / 4) * qr->pix_size);
    if (logo_image_name && widget_load_image(widget, logo_image_name, &img) == RET_OK) {
      canvas_draw_image_ex(c, &img, IMAGE_DRAW_SCALE, &r);
    }
  // }
  if (widget->state == WIDGET_STATE_SELECTED){
    color_t dimgrey = color_init(0X69, 0X69, 0X69, 50);
    style_t* style = widget->astyle;
    int32_t margin = style_get_int(style, STYLE_ID_MARGIN, 2);
    const char* check_image_name = style_get_str(style, STYLE_ID_BG_IMAGE, NULL);
    bitmap_t img;
    rect_t r;

    /* 二维码 */
    r = rect_init(0, 0, margin + qr->qr_width * qr->pix_size, margin + qr->qr_width * qr->pix_size);
    canvas_set_fill_color(c, dimgrey);   
    canvas_fill_rect(c, 0, 0, margin * 2 + qr->qr_width * qr->pix_size, margin * 2 + qr->qr_width * qr->pix_size); 
    if (check_image_name && widget_load_image(widget, check_image_name, &img) == RET_OK) {
      canvas_draw_image_ex(c, &img, IMAGE_DRAW_ICON, &r);
    }
  }
  return RET_OK;
}

static ret_t qr_on_paint_begin(widget_t* widget, canvas_t* c) {
  qr_t* qr = QR(widget);
  if (qr->qr_text != NULL) {
    QRcode *qr_code;
    qr_code = QRcode_encodeString((const char *)qr->qr_text, 3, QR_ECLEVEL_H, QR_MODE_8, 1);
    qr->qr_code_data = qr_code;
    qr->qr_width = qr_code->width;
  }
  return RET_OK;
}

static ret_t qr_on_paint_end(widget_t* widget, canvas_t* c) {
  qr_t* qr = QR(widget);
  if (qr->qr_code_data != NULL) {
    QRcode_free(qr->qr_code_data);
    qr->qr_code_data = NULL;

    widget->dirty = FALSE;
  }

  return RET_OK;
}

static ret_t qr_on_paint_background(widget_t* widget, canvas_t* c) {
  qr_t* qr = QR(widget);

  // if (widget->state == WIDGET_STATE_SCANED){
  //   color_t dimgrey = color_init(0X69, 0X69, 0X69, 0);
  //   style_t* style = widget->astyle;
  //   int32_t margin = style_get_int(style, STYLE_ID_MARGIN, 2);
  //   const char* check_image_name = style_get_str(style, STYLE_ID_BG_IMAGE, NULL);
  //   bitmap_t img;
  //   rect_t r;

  //   /* 二维码的logo图片 */
  //   r = rect_init(0, 0, margin + qr->qr_width * qr->pix_size, margin + qr->qr_width * qr->pix_size);
  //   // vgcanvas_t* vg = canvas_get_vgcanvas(c);
  //   // if (vg != NULL) {
  //   //   vgcanvas_set_fill_color(vg, dimgrey);
  //   //   vgcanvas_translate(vg, c->ox, c->oy);
  //   //   vgcanvas_rounded_rect(vg, 0, 0, widget->w, widget->h, 0);
  //   //   vgcanvas_translate(vg, -c->ox, -c->oy);
  //   //   vgcanvas_fill(vg);
  //   // }
  //   canvas_set_fill_color(c, dimgrey);   
  //   canvas_fill_rect(c, 0, 0, margin + qr->qr_width * qr->pix_size, margin + qr->qr_width * qr->pix_size); 
  //   // if (check_image_name && widget_load_image(widget, check_image_name, &img) == RET_OK) {
  //   //   canvas_draw_image_ex(c, &img, IMAGE_DRAW_SCALE, &r);
  //   // }
  // }
  return RET_OK;
}

static const char* s_qr_properties[] = {WIDGET_PROP_REPEAT, NULL};
static const widget_vtable_t s_qr_vtable = {.size = sizeof(qr_t),
                                                .type = WIDGET_TYPE_QR,
                                                .create = qr_create,
                                                .clone_properties = s_qr_properties,
                                                .persistent_properties = s_qr_properties,
                                                .on_event = qr_on_event,
                                                .set_prop = qr_set_prop,
                                                .get_prop = qr_get_prop,
                                                .on_destroy = qr_destroy,
                                                .on_paint_begin = qr_on_paint_begin,
                                                .on_paint_end   = qr_on_paint_end,
                                                .on_paint_background = qr_on_paint_background,
                                                .on_paint_border = qr_on_paint_border,
                                                .on_paint_self = qr_on_paint_self};

widget_t* qr_create(widget_t* parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  qr_t* qr = TKMEM_ZALLOC(qr_t);
  widget_t* widget = WIDGET(qr);
  return_value_if_fail(qr != NULL, NULL);

  widget_init(widget, parent, &s_qr_vtable, x, y, w, h);
  widget->state = WIDGET_STATE_NORMAL;
  /* 默认的二维码像素与屏幕像素的转化关系 */
  qr->pix_size = 1;

  return widget;
}

widget_t* qr_cast(widget_t* widget) {
  return_value_if_fail(widget != NULL && widget->vt == &s_qr_vtable, NULL);

  return widget;
}
