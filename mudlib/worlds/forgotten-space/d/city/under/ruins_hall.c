// d/city/under/ruins_hall.c
// 史前殘殿地宮 (殘破人面巨石像、地煞氣機匯聚點)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit RUIN_ROOM_OB;

void create() {
    ::create();
    set_short("太古舊城・史前殘殿");
    set_long("穿過幽邃的地下暗渠裂隙，眼前豁然開朗，竟是一座傾頹倒塌的太古宏偉地宮殿堂。\n"
             "數根三人合抱的青銅蟠龍古柱斷裂在地，中央斜臥著半尊高達三丈的殘破人面巨石雕像。\n"
             "石像雙眸空洞，俯瞰著地下萬古長夜，石座底層刻滿了被世人遺忘的史前象形神紋。\n"
             "地煞氣機在此如墨汁翻湧，若無高深修為或天命感應，久留必遭陰煞侵蝕。\n"
             "向北穿過殘破石拱，可走回古暗渠水網樞紐。\n");

    set_exits(([
        "north": "/d/city/under/canal_hub.c",
    ]));

    set("is_underground", 1);
    set("is_ruin", 1);

    set_touch("default", HIB "斷裂的青銅蟠龍柱覆著冰冷滑膩的水垢與銅綠，指腹傳來極其微弱的陰寒震顫。" NOR);
    set_smell("default", MAG "深埋地底萬年的腐朽石粉氣味與濃厚刺骨的地煞陰寒潮氣。" NOR);
    set_listen("default", WHT "空曠地宮裡迴盪著地下水滴砸落石像底座的清脆「答、答」聲與低沉風鳴。" NOR);

    mapping inspect_rule = ([
        "targets": ({ "statue", "glyphs", "石像", "神紋", "" }),
        "sp_cost": 6,
        "sensory_msg": HIB "你蹲在傾頹的三丈石像底座前摸索那些史前象形神紋，只覺指尖滲入一絲難以言喻的蒼涼古意。" NOR,
        "train_stat": ([ "int": 8, "per": 8 ]),
        "exp_gain": 12
    ]);
    add_action_rule("inspect", inspect_rule);
    add_action_rule("端詳", inspect_rule);
}
