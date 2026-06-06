// Room: /u/d/dhk/questsfan/room1
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "段王府密道");
  set ("long", @LONG
這條密道又潮濕、又暗。傳聞這條密道是歷代平南王
府將軍為防止此城被敵軍攻破時給予將軍逃命用的，這條
密道應該通往後山吧？但是你定下心一看，此地確像被廢
棄不用了…
LONG);

  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room2",
  "out" : "open/ping/room/np25",
]));

  setup();
}
