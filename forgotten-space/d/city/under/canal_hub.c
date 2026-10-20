// d/city/under/canal_hub.c
// 城下暗渠・古暗渠樞紐 (匯集全城排污排澇、天然溶洞水系)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("城下暗渠・水網樞紐");
    set_long("這裡是一座巨大的太古石拱地下水殿，匯集了整座府城的排澇水流與天然地下溶洞暗河。\n"
             "黑色濁浪在石柱間轟鳴翻滾，水汽刺骨冰寒。\n"
             "一名黑衣擺渡盲叟手持長篙立於小舟頭上，暗中接應走私客與江湖探子。\n"
             "往北沿石階步道可走回地下鬼市，向西穿過鏽蝕水閘直通護城河盲區，\n"
             "東面有一道緊閉的太古玄鐵重門【天字一號密室】，向南則延伸入史前殘殿地宮。\n");

    set_exits(([
        "north": "/d/city/under/black_market.c",
        "west":  "/d/city/under/drain_gate.c",
        "east":  "/d/city/under/shang_secret.c",
        "south": "/d/city/under/ruins_hall.c",
    ]));

    set("is_underground", 1);
    spawn_npc("/clone/npc/under_canal_hub_ferryman.c");
}
