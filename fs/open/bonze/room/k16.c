// Room: /open/bonze/room/k01.c

#include "bonze.c"
inherit ROOM;
void create ()
{
  set ("short", "柴房後門");
  set ("long", @LONG
這裡是少林寺的柴房後門外，這裡鮮有人來此，因此稍微有點荒涼
，前方有個水缸，似乎因為太遠故較少人使用而荒廢。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  BONZE_OBJ"vat.c" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"k15.c",
]));
  setup();
}
