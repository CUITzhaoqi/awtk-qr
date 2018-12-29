#include "base/canvas.h"
#include "widgets/label.h"
#include "qr/qr.h"
#include "base/widget.h"
#include "gtest/gtest.h"
#include <stdlib.h>

TEST(Qr, basic) {
  value_t v1;
  value_t v2;
  widget_t* qr = qr_create(NULL, 10, 20, 30, 40);

  ASSERT_EQ(widget_set_text(qr, L"OK"), RET_OK);
  ASSERT_EQ(wcscmp(qr->text.str, L"OK"), 0);
  ASSERT_EQ(widget_set_text(qr, L"Cancel"), RET_OK);
  ASSERT_EQ(wcscmp(qr->text.str, L"Cancel"), 0);

  value_set_wstr(&v1, L"qr");
  ASSERT_EQ(widget_set_prop(qr, WIDGET_PROP_TEXT, &v1), RET_OK);
  ASSERT_EQ(widget_get_prop(qr, WIDGET_PROP_TEXT, &v2), RET_OK);
  ASSERT_EQ(wcscmp(v1.value.wstr, v2.value.wstr), 0);

  widget_destroy(qr);
}


TEST(Qr, clone) {
  value_t v1;
  widget_t* qr1 = label_create(NULL, 10, 20, 30, 40);

  widget_set_name(qr1, "qr");
  value_set_wstr(&v1, L"qr");
  ASSERT_EQ(widget_set_prop(qr1, WIDGET_PROP_TEXT, &v1), RET_OK);

  widget_t* qr2 = widget_clone(qr1, NULL);

  ASSERT_EQ(widget_equal(qr2, qr2), TRUE);

  widget_destroy(qr1);
  widget_destroy(qr2);
}