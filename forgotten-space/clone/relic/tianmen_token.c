// clone/relic/tianmen_token.c
// 【萬物行商・天門引】青金古令 - 太古失落史前商盟的神闕通關權杖

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("青金古令", ({ "tianmen token", "ancient token", "token", "tianmen", "天門引", "青金古令", "古令" }));
    set_short(CYN "【萬物行商・天門引】" WHT "(休眠殘缺)" NOR);
    set_long("一枚巴掌大小、通體泛著暗啞青金幽光的奇異古令，非鐵非玉，入手沉重且冰寒徹骨。\n"
             "令符正面雕刻著兩條彼此咬合盤旋的遠古金龍，環抱著一座太古神闕天關，但龍首處有一道深可見骨的斷裂缺口；\n"
             "背面數十道細密繁複的微型金屬齒輪與暗金符紋已被歲月與大清洗封印徹底鎖死，中央嵌著四個斑駁古篆：\n"
             HIR "「萬物行商・天門引」\n" NOR
             WHT "（此令目前處於【休眠殘缺狀態】，核心樞機凝滯，唯有日後尋得太古商盟遺脈或高階靈樞方能重啟其通行權柄。）\n" NOR);
    set_weight(800);
    set_value(200);
    set("is_relic", 1);
    set("relic_type", "shang_token");
    set("relic_dormant", 1);
}
