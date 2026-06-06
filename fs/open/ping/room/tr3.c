#include <room.h>
#include <ansi.h>
inherit ROOM;
 void create()
{
  set("short", "段家競技場");
  set("long", @LONG
身為段家弟子，必須文武合一。段王爺有鑑於這一點，特別為弟
子們成立訓練廳，希望他們在讀書之外，還能鍛鍊自己的體魄。
  

LONG);
    set("light_up", 10);
   set("exits", ([
   "down": __DIR__"tr4",
    "up": __DIR__"tr2",
   
    ]));
   set("objects",([
         "/open/ping/npc/train3.c":  3,
           ]));
 setup();
}
