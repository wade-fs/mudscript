
inherit ROOM;
#include <ansi.h>
void create () {
set ("short","魔之左翼");
        set ("long","隨著你走過每一步, 灼燙的魔氣愈是升高, 相映牆上的火蠋鬼影, 令人神
智不清, 精神上承受著無比的壓力. 此地牆石均是由魔界深處的漆黑墨石
所拼, 邪氣鬱鬱, 石性極陽, 呼應著焚天魔王的魔氣蕩蕩. 而妖魅之影散
亂, 孰不知人間黑夜之陰翳, 無絲無竹, 獸號魔哭迴轉繞光不曾歇止.  
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "east" :  __DIR__"room56",
            "west"  : __DIR__"room72",
      ]));
        setup();
}
