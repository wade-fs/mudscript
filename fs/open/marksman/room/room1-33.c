// Room: /u/f/fire/room/room1-33
#include <ansi.h>
#include "marksman.h"
inherit ROOM;

void create ()
{
  set ("short", "民房");
  set ("long", @LONG
簡簡陋陋的裝潢，平平凡凡的小房屋。散發出平凡和平的氣息，
可親可愛的長沙民眾，正在努力的創造美好的家庭。老婆婆正在幫著
為家裏的人煮東東。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room1-10",
]));
  set("objects", ([ /* sizeof() == 2 */
C_NPC"/oldwoman" : 1,
C_NPC"/oldman" : 1,
]));

  setup();
}
