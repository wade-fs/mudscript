// /d/sects/danding/discarded_pill_cliff.c
// 丹鼎宗後山・廢丹崖 (Ch.97：腐酸霧、石棚後兩只鐵罐與試藥白猿病理剖檢)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("丹鼎宗後山・廢丹崖");
    set_long("丹鼎宗背陰深谷邊緣死寂荒涼的懸崖斷崖，連山鳥都不敢飛近。崖壁滲著黑褐色廢水，\n"
             "坑底積滿刺鼻腐酸霧與厚重灰白石灰粉。崖邊搭著一座低矮漏風的石棚，工頭陶生\n"
             "蹲在棚旁處理成桶廢料；石棚後方被大石遮掩的深溝裡藏著兩只未撒石灰的封閉鐵罐，\n"
             "儲有「紫泥封口」硬渣與試藥白猿凍屍（戴口罩手套查驗：dissect ape）。\n"
             "東南石徑可返【百草谷】，向東通往【醫理院】，向南暗道口連接【地肺丹火窟】。\n");

    set_exits(([
        "southeast": "/d/sects/danding/herb_garden.c",
        "east":      "/d/sects/danding/medical_archive.c",
        "south":     "/d/sects/danding/earth_fire_pill_cave.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", WHT "崖邊堆滿的『紫泥封口』廢渣硬如焦磚，凍硬的白猿屍身冷得像塊石頭。" NOR);
    set_smell("default", MAG "變質丹藥酸腐氣、硫磺焦渣味與濃烈刺鼻的毒草敗葉腥臭直衝腦門。" NOR);
    set_listen("default", WHT "山風掠過廢丹崖發出空洞回聲，偶爾有腐蝕碎渣沿峭壁滾落山澗。" NOR);

    spawn_npc("/clone/npc/tao_sheng.c");
}

void init() {
    ::init();
    add_action("do_dissect", "dissect");
}

int do_dissect(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "ape" && arg != "slag" && arg != "白猿" && arg != "廢渣") {
        notify_fail("你想取樣檢驗什麼？試試：dissect ape\n");
        return 0;
    }
    message_vision("$N戴妥甘草棉口罩與雙層鹿皮手套，在陶生見證下從鐵罐取出紫泥廢渣封箱，\n"
                   "隨即於後山廢石室以細柳葉銀刀剖開白猿內臟——只見心肺道化晶斑雖縮減四成，\n"
                   "肝腎卻已潰爛成嵌滿暗紅血煞結晶的蜂窩狀硬化塊！$N讓陶生按下見證指印。\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "dissect", "target": "ape" ]));
    }
    return 1;
}
