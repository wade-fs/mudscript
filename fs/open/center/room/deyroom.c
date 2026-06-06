// Room: /u/l/lotus/girl/deyroom.c

#include "/open/open.h"
#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "彩蝶姑娘的房間");
  set ("long", @LONG
彩蝶姑娘必定是個極愛花的人, 因為房中各處都以鮮花點綴著,
散發著濃郁的花香, 連大床上都灑滿了花瓣, 躺在上面一定像跌進了
花堆裡那麼舒服, 彩蝶姑娘正快樂的跳著舞.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : CENTER_ROOM"f2c",
]));
  set("objects", ([ /* sizeof() == 1 */
  CENTER_NPC"dey.c" : 1,
]));
  set("light_up", 1);
  set("file_name", CENTER_ROOM"deyroom.c");
  create_door("west", "雕花木門", "east", DOOR_CLOSED);
  setup();
}
