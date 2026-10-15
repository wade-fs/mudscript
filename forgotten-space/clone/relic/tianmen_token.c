// clone/relic/tianmen_token.c
// 【萬物行商・天門引】青金古令 - 太古失落史前商盟的神闕通關權杖

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("青金古令", ({ "tianmen token", "ancient token", "token", "tianmen", "天門引", "青金古令", "古令" }));
    set_short(CYN "【萬物行商・天門引】" NOR);
    set_long("一枚巴掌大小、通體泛著深邃青金幽光的奇異古令，非鐵非玉，入手重若萬鈞且冰寒徹骨。\n"
             "令符正面雕刻著兩條狂暴猙獰、彼此咬合盤旋的遠古金龍，環抱著一座直插雲霄的太古神闕天關；\n"
             "背面則由數十道細密繁複至極的微型金屬齒輪與暗金符紋咬合成太古封印，中央嵌著四個森嚴古篆：\n"
             HIR "「萬物行商・天門引」\n" NOR
             "持此令者，能借上古商盟大勢破開大清洗遺留的護山殺陣與封關禁制，自由出入太古九座神闕要塞！\n");
    set_weight(800);
    set_value(1000);
    set("is_relic", 1);
    set("relic_type", "shang_token");
}
