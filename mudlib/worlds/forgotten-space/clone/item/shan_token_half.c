// clone/item/shan_token_half.c
// 玄鐵走山令殘牌 - 卷二第三幕核心物證

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("玄鐵走山令殘牌", ({ "shan token half", "shan_token_half", "canpai", "走山令", "殘牌" }));
    set_short(CYN "【玄鐵走山令殘牌】" NOR);
    set_long("在鎮風邊防衛所北塞烽燧廢墟中起獲的半枚特製玄鐵通行令牌。\n"
             "牌面由極硬的冷鍛玄鐵鑄就，邊緣斷口參差，正面銘刻著殘缺的五年前衛所特批走山文號，\n"
             "背面凹槽中以重箭鏃深刻出一道微小的蒼鷹翎羽暗記——正是燕隼失蹤大伯燕山的獨門箭記！\n"
             "結合衛所塵封五年之秘密出關底檔，證實金石商會早在五年前即重金僱用燕山勘探北崖古礦脈水文，\n"
             "為強間接佐證（corroborative），證實商會盜採地煞布局深遠。\n");
    set_weight(120);
    set_value(600);
    set("is_evidence", 1);
    set("evidence_type", "shan_token");
    set("evidence_level", "corroborative");
}
