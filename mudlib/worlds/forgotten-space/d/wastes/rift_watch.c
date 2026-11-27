// /d/wastes/rift_watch.c
// 大營西北斷崖暨墨黑垂直雪壁（Ch.104：五年前炸垮半山後之半丈深黑石隙與精鋼岩釘垂降口）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("北荒裂谷・墨黑雪壁垂降崖");
    set_long("大營西北角外五里處險峻的墨黑色垂直雪壁，五年前被人從上方引爆三十斤烈性開山重藥\n"
             "炸垮了半座山頭才封死這道山溝；唯有最靠崖角露出一道半丈寬的深黑石隙，壁面上\n"
             "隱約可見兩根順節理砸入堅冰的破冰精鋼岩釘與雙股垂降麻繩（垂降下谷：rappel cliff）。\n"
             "向東南摸黑返營【冰脊高地勘探大營】，向下垂降進入【黑冰斷谷】。\n");

    set_exits(([
        "southeast": "/d/wastes/expedition_camp.c",
        "down":      "/d/wastes/black_ice_valley.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", HIW "墨黑雪壁垂降崖緣的玄石如鐵般冰冷堅硬，垂降麻繩已凍成硬邦邦的粗麻冰柱。" NOR);
    set_smell("default", CYN "高崖罡風裡沒有半絲煙火氣，只有凜冽雪霧與崖底深谷湧上來的陰寒石氣。" NOR);
    set_listen("default", WHT "裂谷深處偶爾向上捲來空洞幽遠的回風鳴響，彷彿深淵在低聲吞吐氣息。" NOR);
}

void init() {
    ::init();
    add_action("do_rappel", "rappel");
}

int do_rappel(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "cliff" && arg != "down" && arg != "垂降" && arg != "斷崖") {
        notify_fail("你想沿哪裡垂降？試試：rappel cliff\n");
        return 0;
    }
    message_vision("$N緊繫安全牛筋繩並確認滑輪雙契承重後，借精鋼岩釘沿墨黑雪壁半丈石隙\n"
                   "靜聲垂降百餘步人工爆破碎石帶，嗅見底下冰層深處未散的硫磺焦灰氣息。\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "rappel", "target": "cliff" ]));
    }
    return 1;
}
