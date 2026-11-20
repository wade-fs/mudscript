// /d/sects/bahuang/ghost_cry_gorge.c
// 大黑山東側・鬼哭冰澗 (Ch.94：五年前走山隊斷箭、八方舊甲與冰層人為爆破現場)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("大黑山東側・鬼哭冰澗");
    set_long("過大黑山東側鷹喙狀墨色風化岩脊三里外的荒寂裂谷。東坡五年前疑遭軍用烈性開山\n"
             "火藥從上方人為炸塌封死，底下藏著幽暗冰縫暗河；昨夜罡風恰好刮走一層浮雪，\n"
             "露出離地約三尺斜坡冰殼下隱約露頭的一截纏著雙股黑麻線之斷箭與冰下人工鑿痕\n"
             "（以測冰長鐵簽探冰垂降：probe ice）。向西踏雪脊返抵【北線長城巡防牆暨關口】。\n");

    set_exits(([
        "west": "/d/sects/bahuang/great_wall_gate.c",
    ]));

    set("is_outdoor", 1);
}

void init() {
    ::init();
    add_action("do_probe", "probe");
}

int do_probe(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "ice" && arg != "gorge" && arg != "冰層" && arg != "斷箭") {
        notify_fail("你想探測什麼？試試：probe ice\n");
        return 0;
    }
    message_vision("$N借測冰長鐵簽試實東坡承重並繫好牛筋安全繩垂降至三尺冰台，果然自冰殼內\n"
                   "鑿起半截刻有「一橫折、兩斜掠鷹翅」燕山箭記的斷折骨箭與一塊「八方」舊皮甲！\n"
                   "細察斷茬整齊斜切，顯係遭重斧或軍用破甲弩近距硬生生削斷。\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "probe", "target": "ice" ]));
    }
    return 1;
}
