// clone/npc/folk/roaming_porter.c
// 挑夫阿福・依時辰往來魚市、南關車馬小棧、大石堆棧與流民矮巷之活態苦力 NPC

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("挑夫阿福");
    set_short(YEL "扛包挑夫" NOR " 阿福");
    set_long("一名精瘦黝黑、肩頭搭著一條汗漬發黃粗布巾的年輕挑夫。\n"
             "他沒考取任何行會名籍，也沒錢租內城客棧，只能天不亮跑去魚市與碼頭搶散工竹籌，\n"
             "收了工便回南關外土坯矮巷湊著買碗粗茶粥填肚子。\n");
    set_id(({ "roaming_porter", "porter afu", "afu", "porter", "挑夫阿福", "阿福", "挑夫" }));

    setup_archetype("B", 6);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "laborer", "info" }));
    set("no_combat", 1);

    add_response(({ "工錢", "竹籌", "扛包", "散活" }),
        "阿福抹了把額頭熱汗咧嘴笑道：「咱沒匠籍也沒百工腰牌，進不去北城大坊，好在外城碼頭和南關堆棧每天都能現結竹籌！只要肯賣力氣，一日掙個二三十文糙米錢總夠的。」");
    add_response(({ "矮巷", "通鋪", "暫住牌", "流民" }),
        "阿福壓低聲道：「外鄉兄弟沒路引千萬別半夜往內城中心擠，先去南關門外矮巷拼個兩文錢通鋪，找孫伯問問怎樣領張《暫住牌》，總算能安穩接活睡個整覺。」");
}
