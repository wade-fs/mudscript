
inherit ROOM;
#include <ansi.h>
void create () {
set ("short","七色迴路");
        set ("long","一步踏入此地, 立覺陰冷刺骨, 此處乃是妖魔古堡中最陰最寒之地. 儘管
兩邊的牆壁上掛著兩列燭臺, 卻不透一絲絲暖意, 冷光落壁, 邪氳雰雰, 
魔氣呼嘯, 掠影幢幢, 你頓時發現聽覺與視覺已經不能作出正確的判斷. 
突來陣陣殺氣掀起了紫黑色的火線, 血腥的戰鬥將隨時發生. 
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "east"  : __DIR__"room90",
            "west"  : __DIR__"room88",
      ]));
        setup();
}
