// clone/npc/gong_registry_clerk.c
// 方矩・司匠簿吏 (gong_registry_clerk) - 匠籍登記處

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("方矩");
    set_short(CYN "百工司匠簿吏" NOR " 方矩");
    set_long("一位案頭堆滿六縣原料調撥批件與匠人考功圖譜的年輕書吏。\n");
    set_id(({ "gong_registry_clerk", "fang ju", "fangju", "registry clerk", "方矩", "司匠簿吏", "簿吏" }));

    setup_archetype("A", 18);
    set("class", "gong_initiate");
    set("faction", "gong");
    set("roles", ({ "service", "info" }));
    set("schedule", "day");

    add_response(({ "匠籍", "調撥", "批件", "晉升", "原料" }),
        "方矩翻開匠冊道：「凡取得歐陽大師親授【天工烏木尺】之正式學徒，皆在此登錄匠籍，憑籍可按官價申領重石生鐵、盤木良材與烈礬赤銅！」");
}
