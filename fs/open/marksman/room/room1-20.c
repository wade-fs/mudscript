// Room: /u/f/fire/room/room1-20.c
inherit ROOM;
#include <ansi.h>
#include "marksman.h"
void create ()
{
  set ("short", HIY + "箭盟聚眾" + NOR);
	set( "build", 3 );
  set ("long", @LONG
這裏是弓箭聚會的場所，也是弓箭手的公會所在。花崗岩所作成
，富麗輝煌，顯得玲瓏可人。其上雕刻幾個行書寫成的大字，更添風
流瀟灑。這裏似乎可以讓成為弓箭手的一員。
LONG);

  set("objects", ([ /* sizeof() == 1 */
C_NPC"/master_b.c" : 1,
]));
set("outdoors","/open");
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room1-19",
]));

  setup();
}
