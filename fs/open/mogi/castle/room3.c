// room7.c by konn
inherit ROOM;
#include <ansi.h>
void create () {
set ("short","古堡一樓");
        set ("long","四周似乎還潛伏著什麼妖魔鬼怪,令人心裡惶惶不安。地板是由已腐舊的的木板
釘成,走在上面不停的發出嘎吱嘎吱的聲音。令人不禁想起是否有陷阱呢。

                      ～嘎吱～嘎吱～

");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "east" :  __DIR__"room4",
            "north"  : __DIR__"room7",
            "west"  : __DIR__"room2",
      ]));

       

        setup();
}
