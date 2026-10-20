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
}
