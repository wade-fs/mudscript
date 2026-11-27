// d/city/west/dao_hall.c
// 宣道司正堂 (法道受牒考核處、玄機真人)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("宣道司・三清正殿");
    set_long("整座大殿以青墨色玄石與古楠木構建，穹頂繪製著周天星斗與二十八宿逆行圖。\n"
             "殿內供奉著代表宇宙秩序的太虛天尊像，殿角四座銅爐升起嫋嫋龍涎檀香。\n"
             "宣道司道官玄機真人端坐於雲床法座之上，手持拂塵閉目養神。\n"
             "凡達到十級的修士，可向玄機真人請受法道一階度牒考核 (ask xuanji about 考核)。\n"
             "持有大乾度牒者可於殿內依律行祈禳觀象之法 (ritual / 開壇)。\n"
             "往東可步出正殿大門回到宣道司牌樓，向北通往靜心聽經閣，\n"
             "順生鐵旋梯向上 (up) 可登臨摘星觀象台。\n");

    set_exits(([
        "east":  "/d/city/west/dao_gate.c",
        "north": "/d/city/west/dao_quiet.c",
        "up":    "/d/city/west/dao_observatory.c",
    ]));

    set("is_outdoor", 0);
    set_touch("default", HIC "殿柱青墨玄石寒涼沉靜，內側竟微不可察地流轉著絕靈法網的微弱磁震。" NOR);
    set_smell("default", WHT "冷冽的龍涎檀香壓住了山門外滾滾紅塵的肉濁氣息。" NOR);
    set_listen("default", CYN "偶爾響起玉磬清音，隱約能聽見樓上摘星台青銅渾天儀齒輪嚙合的細微嘀嗒聲。" NOR);

    mapping rit_rule = ([
        "require_qualification": "diviner",
        "action_label": "內城公開設壇施法",
        "sp_cost": 10,
        "sensory_msg": HIC "你展開宣道司朱印大乾度牒置於案前，結子午印引動香煙筆直上衝穹頂星圖——清冷靈韻如水洗過靈台，殿外紅塵濁障為之一清。" NOR,
        "train_stat": ([ "spi": 15 ]),
        "exp_gain": 12
    ]);
    add_action_rule("ritual", rit_rule);
    add_action_rule("開壇", rit_rule);

    spawn_npc("/clone/npc/dao_xuanji.c");
}
