// Room: /u/l/lotus/girl/guest2.c
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "彩廳");
  set ("long", @LONG
一群年紀十四, 五歲的少女, 舞著鳳陽花鼓, "咚咚咚", "咚咚咚
咚", 俏皮可愛. 這是舞孃表演舞蹈的地方, 客人們在此飲酒, 欣賞舞
蹈, 好不風流, 不一定什麼時候,  以舞蹈聞名的彩蝶姑娘會下得樓來
舞一曲.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : CENTER_ROOM"tin1.c",
  "south" : CENTER_ROOM"tin3.c",
  "east" : CENTER_ROOM"guest",
]));
  set("light_up", 1);
  set("file_name", CENTER_ROOM"guest2.c");

  setup();
}
