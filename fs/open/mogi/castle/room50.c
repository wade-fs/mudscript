
inherit ROOM;
#include <ansi.h>
void create () {
set ("short","練\功\房");
        set ("long","這裡是古堡三樓的練功\房，兩旁的火炬將這裡照得耀如白晝，
其中有些妖魔正在練習。招式精妙，威力驚人，拳掌中夾著
呼呼風雷聲。你心中一凜，這不是失傳已久的風雷八式麼？
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "south" :  __DIR__"room49",
            "west" : __DIR__"room71",
            
      ]));

        set("objects",([ /* sizeof() == 1 */
   __DIR__"npc/wind-cloud-ghost" : 4,
      ]));

        setup();
}
