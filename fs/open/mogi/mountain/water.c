// room7.c by konn
inherit ROOM;
#include <ansi.h>
void create () {
set ("short","冷泉湖");
        set ("long","
  這裡就是冷泉湖了，魔界村唯一水源的來源。天邪峰上的積雪
堆積在這裡因為此地的氣溫稍高故在此形成冰水湖。湖面現在
到處都是浮冰，浮現淡淡的藍色，看起來還挺漂亮的。\n
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
         "west" :  __DIR__"d",
      ]));

       

        setup();
set ("資源/液體", ([
       "種類" : "水",
       "名稱" : "清水",
       "止渴" : 30
  ]) );
}
