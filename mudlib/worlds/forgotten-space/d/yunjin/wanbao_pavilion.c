// /d/yunjin/wanbao_pavilion.c
// 雲津仙集・萬寶閣雲津分號 (Ch.84, Ch.90：何萬金與排他條款)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("雲津仙集・萬寶閣雲津分號");
    set_long("雕樑畫棟、沉香濃郁的三層大商號，堂內陳列著成排上好靈材箱籠與紫檀算盤。\n"
             "萬寶閣掌控著雲津西街多數甲字大倉與高價冬草馬隊配額，掌櫃何萬金常在雅座間\n"
             "以保證金、排他供應條款篩選合作小商號；後堂窄門外便是深夜卸貨的暗巷。\n"
             "向北退出大門可返【萬山商埠公所】，向南穿過後堂側門通往【鬼市暗巷與萬寶閣後門交界】。\n");

    set_exits(([
        "north": "/d/yunjin/public_office.c",
        "south": "/d/yunjin/wanbao_back_alley.c",
    ]));

    set("is_outdoor", 0);

    set_touch("default", YEL "紫檀櫃檯與雕花扶手摸上去溫潤細膩，絲毫感受不到屋外的冰天雪地。" NOR);
    set_smell("default", HIY "名貴沉香濃郁而不嗆鼻，夾著珍稀靈材匣子裡的乾燥甘香。" NOR);
    set_listen("default", WHT "紫檀算盤撥動聲沉穩緩慢，雅座簾幕後偶爾傳出壓低嗓門談條件的客套笑聲。" NOR);

    spawn_npc("/clone/npc/he_wanjin.c");
}
