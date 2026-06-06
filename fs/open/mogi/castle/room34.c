
inherit ROOM;
#include <ansi.h>
void create () {
set ("short","古堡二樓");
        set ("long","四周充滿了令人幾乎窒息的氣氛，陰森森的鬼火詭異的
一閃一滅著，仔細一看似乎還有不少白骨散落在地上，
不禁使人起了雞皮疙瘩。看來這裡是一條東西向的長廊
，而南邊似乎是通往三樓的樓梯？
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "south" :  __DIR__"room35",
            "west" :  __DIR__"room33",
          
      ]));

       

        setup();
}
