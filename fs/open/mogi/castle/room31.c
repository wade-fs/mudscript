inherit ROOM;
#include <ansi.h>
void create () {
set ("short","古堡二樓");
	set( "build", 64 );
        set ("long","四周充滿了令人幾乎窒息的氣氛，陰森森的鬼火詭異的
一閃一滅著，仔細一看似乎還有不少白骨散落在地上，
不禁使人起了雞皮疙瘩。看來這裡是一條東西向的長廊。
西邊似乎有一泛著詭異綠光的房間？
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "east" :  __DIR__"room30",
            "west" :  __DIR__"room32",
          
      ]));
      set("objects",([ /* sizeof() == 1 */
           __DIR__"npc/mob6" : 1,
      ]));

       

        setup();
}
int valid_leave(object me, string dir)

{
        if(dir=="west"&&present("ghost",environment(me)))
  {

message_vision(HIY"奪魂魔冷笑道:「你以為這裡是你家？」\n"NOR,me);

return 0;
}
return 1;
}
