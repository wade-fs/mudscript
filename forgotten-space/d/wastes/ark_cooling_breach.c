// /d/wastes/ark_cooling_breach.c
// 方舟東側冷卻外殼豁口（Ch.109：三十具鑽山傀儡盜掘現場、太古手動總閘門鎖死七成流量）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("太古方舟・東側冷卻外殼豁口");
    set_long("順主冷卻管線檢修走道向東三里處的巨型鑿穿豁口：厚數尺的黑色合金殼體被\n"
             "三十具二階重型「鑽山傀儡」撕開丈許大口，高壓血精母液與地脈毒煞狂噴如柱，\n"
             "臨時鋼鐵平台上倒著白玉接液罐箱。距平台兩丈高處合金壁上有座齒牙卡死的丈許\n"
             "太古手動總閘門，急需以雪線苔寒霧壓毒並嵌入黑鐵齒輪連錘鎖閘（指令：lock valve）！\n"
             "往西退入【方舟主引擎冷卻艙段】，向東北搶入應急逃生道奔向【冰谷窄口】。\n");

    set_exits(([
        "west":      "/d/wastes/ark_foundation.c",
        "northeast": "/d/wastes/ice_valley_exit.c",
    ]));

    set("is_outdoor", 0);

    set_touch("default", HIB "鑿穿的黑色合金殼體切面冰冷滑膩，高壓血精母液濺起的霧氣帶著灼骨寒刺感。" NOR);
    set_smell("default", MAG "濃烈刺鼻的高壓血精腥甜味、雪線苔寒霧與地脈毒煞焦臭嗆得人眼眶發酸。" NOR);
    set_listen("default", RED "破開大口的冷卻管線如怒龍般狂噴嘶鳴，伴隨著手動總閘門齒牙卡死的沉重金屬摩擦聲。" NOR);
}

void init() {
    ::init();
    add_action("do_lock", "lock");
}

int do_lock(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "valve" && arg != "gate" && arg != "總閘" && arg != "閥門") {
        notify_fail("你想鎖死哪座裝置？試試：lock valve\n");
        return 0;
    }
    message_vision("$N戴緊雙倍雪線苔冷萃口罩噴出冰霧凝膜暫壓毒煞擴散三成，同時借兩毫公差\n"
                   "將【太古不融黑鐵齒輪構件】砸入總閘門傳動牙盤空缺處、連轟三錘猛轉閘輪！\n"
                   "七成母液噴流應聲鎖死，液壓倒灌炸毀前排五具鑽山傀儡，現場拾獲出廠批號鑽頭殘件\n"
                   "與尚存半瓶封蠟完好之血精母液玉瓶，並順道拉出四名中毒苦力！\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "lock", "target": "valve" ]));
    }
    return 1;
}
