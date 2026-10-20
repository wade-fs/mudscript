// clone/npc/gong_luchangsheng.c
// 天工木作大棚把頭 魯長生

#include "/include/ansi.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("魯長生");
    set_short(YEL "大木作把頭" NOR " 魯長生");
    set_long("一位手持墨斗與木鋸的瘦削老木匠，正審視著來自盤木縣的百年冷杉巨樑。\n"
             "他神態專注，精通全城大型絞盤、吊車與守城木構的應力搭建。\n");
    set_id(({ "luchangsheng", "lu", "carpenter", "魯長生", "把頭" }));

    set_level(25);
    set_stat("dex", 30);
    recalc_stats();

    add_response(({ "榫卯", "木作", "大樑", "機關" }),
        "魯長生敲了敲大木：「千斤大木，全賴三寸榫楔接合。受力若偏半毫，城防絞盤便會崩解！」");
}
