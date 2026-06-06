// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short","三代弟子休息室");
        set("long", @LONG
這間休息室是給天道派第三代弟子休息時所用的，在這間房中有
缸水，你可以喝一點來解渴。此外這還有幾張床可讓你暫時休息一下
，回復一下疲倦的身心。
LONG);
  set("objects", ([ /* sizeof() == 1 */
  "/open/tendo/obj/beck":1,
]));
set("exits", ([
	"west":__DIR__"r29",
]));
  set("no_fight",1);
  set("no_kill",1);
  set("no_magic",1);
  set("light_up",1);
  set("no_spells",1);
  setup();
}
