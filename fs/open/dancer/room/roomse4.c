// Room: /open/dancer/room/roomse4.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short",GRN"涼亭"NOR);
  set ("long", @LONG
站在此地你感到陣陣涼風吹來，令人心曠神怡，涼亭的東邊是一
山堐視野廣闊可望到海洋，海景山色一望無窮，禁收眼底。令你不禁
想終生歸隱此處不再理江湖是非。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : "/open/dancer/room/roomse3.c",
]));

  set("light_up", 1);

  setup();
}
