//礦坑 by frequency
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIW + "古" + HIM + "‧" + YEL + "地底" + HIY + "宮殿" + NOR);
  set ("long", @LONG
高聳宏偉的石柱將這裡撐起了一片廣大空間，污濁的空氣似乎
也稀薄許多，腳下是以大理石鋪成的平整地面。雖然在這裡看不見
精細雕工處理過的痕跡，但光看這些巨大樑柱以及方整無瑕的四壁
，就夠令人讚歎的了，想必是古時礦工為了祈求大地之神的保佑而
興建的土之神殿。
LONG);

  set("exits", ([
  "south" : __DIR__"ground-temple2.c",
  "north" : __DIR__"ground-temple.c",

               ]));
  set("outdoors", "/open/main");
  set("no_transmit",1);
  setup();
}
