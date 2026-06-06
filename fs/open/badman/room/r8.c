// Room: /open/badman/room/r8

#include "/open/open.h"
#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "金庫");
  set ("long", @LONG
一進到這個房間，立刻就有人圍了上來阻止你繼續前進，從他
們臉上嚴肅的表情，就可以知道這裡必定就是惡人谷中戒備最森嚴
的藏寶庫了。以十大惡人當年的武功及威名，想必撈了不少金銀財
寶，一想到這裡，你的口水就情不自禁的流了出來。
    你注意到南邊有一個大鐵門，後面應該就是金庫了吧。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r9",
  "north" : __DIR__"b6",
]));
  set("objects", ([
  BAD_NPC"gguard" : 2,
]));

  set("light_up", 1);
  create_door("south", "鐵門", "north", DOOR_LOCKED);

  setup();
}
