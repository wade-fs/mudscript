// clone/item/hunter_badge.c
// 大荒勇士符令 - 獵戶大師階梯認可徽印

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name(HIY "大荒勇士符令" NOR);
    set_short(HIY "【大荒勇士符令】" NOR);
    set_long("這是一枚由趙老獵以整塊黑嶺暴熊頭蓋骨浸潤地煞玄油雕琢而成的沉重符令。\n"
             "上面以粗獷的刻刀勾勒著巨熊咆哮與古弓搭箭的獵殺圖騰，\n"
             "散發著濃烈的百獸避易之威，是大荒深林頂尖獵手的至高信印。\n");
    set_id(({ "hunter badge", "badge", "符令", "勇士符令", "大荒勇士符令" }));
    set_weight(500);
    set_value(500);
    set("is_badge", 1);
}
