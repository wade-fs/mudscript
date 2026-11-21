// /d/wastes/ark_core_chamber.c
// 太古破界方舟・八角形主陣基核心圓台（Ch.106-107：五遺物嵌入式凹龕與殘缺太古光影紀錄）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("太古方舟・八角形主陣基核心圓台");
    set_long("高出艙底地面三丈、直徑約十丈的八角形暗銀冷硬金屬圓台，台面刻滿幾何凹槽與\n"
             "星軌導流線。中央多邊形晶石底座周圍環列正北、東北、西北、西南、正南五個對應不同\n"
             "紋路的嵌入式凹龕——可依序嵌放【逆星斷碑拓片】、【不融黑鐵齒輪】、【獵獸圖騰骨片】、\n"
             "【古礦地煞晶核殘片】與【天門引暨青銅契版】五器共鳴（指令：place relics）。\n"
             "圓台後方暗沉合金門廊微滑半尺通往【方舟後勤石鋼廳室】，向南走下【方舟主引擎冷卻艙段】。\n");

    set_exits(([
        "south": "/d/wastes/ark_foundation.c",
        "north": "/d/wastes/ark_logistics_hall.c",
    ]));

    set("is_outdoor", 0);
    set_touch("default", HIC "你伸手撫過八角形暗銀金屬圓台，台面幾何凹槽的加工精度達到微米級，五個嵌入式凹龕內壁分別刻著星軌、齒輪、骨紋、晶簇與青金契印。" NOR);
    set_smell("default", CYN "艙室裡瀰漫著封存萬載的惰性冷卻液氣味與淡淡的金屬電離氣息。" NOR);
    set_listen("default", WHT "圓台底部傳來極其微弱的殘餘電容脈衝聲，彷彿整座沉睡的方舟正等待五器歸位校驗。" NOR);
}

void init() {
    ::init();
    add_action("do_place", "place");
}

int do_place(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "relics" && arg != "five" && arg != "五器" && arg != "遺物") {
        notify_fail("你想把什麼嵌入圓台凹龕？試試：place relics\n");
        return 0;
    }
    message_vision("$N依序將五組太古信物嵌入東北、正北、西北、西南與正南凹龕！底座上方三尺處\n"
                   "隨即浮現青金色半透明光影：漆黑星海上懸著「二十八宿天羅結構」，下方人族方舟正由\n"
                   "『領航演算部』、『破陣護衛部』與『工程造物部』協同建造——然而影像跳至點火撞擊與\n"
                   "大清洗前瞬即炸出漆黑雪花噪點熄滅，唯見圓台後方合金門廊悄然滑開半尺縫隙！\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "place", "target": "relics" ]));
    }
    return 1;
}
