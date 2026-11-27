// /clone/item/cred_danding_medical_tag.c
// 丹鼎宗百草谷藥牌（第三卷 Ch.89 百毒試藥谷通過憑證）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("丹鼎百草谷藥牌", ({ "cred_danding_medical_tag", "danding tag", "丹鼎百草谷藥牌", "百草谷藥牌" }));
    set_short(GRN "千機百巧門・丹鼎百草谷藥牌" NOR);
    set_long("一塊以百年鐵力青木雕成的矩形藥牌，表面隱泛淡淡草藥清氣。\n"
             "憑此牌可進出百草谷藥田與醫理院外診區，調閱病案封存室仍須病患授權或院令。\n");
    set_weight(50);
    set_value(0);
    set("is_credential", 1);
    set("sect", "danding");
}
