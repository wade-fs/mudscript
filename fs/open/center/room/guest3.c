// Room: /u/l/lotus/girl/guest3.c
#include "/open/open.h"

inherit ROOM;

void create ()
{
  set ("short", "曲廳");
  set ("long", @LONG
唱歌的姑娘年紀輕輕的, 技巧很好, 吸引了很多人在這兒飲酒聽
小曲兒. 一旁拉琴的老頭子, 是個好手, 聽說巧心姑娘是他的關門弟
子,現在年歲大了, 不肯再收弟子了.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : CENTER_ROOM"guest.c",
  "north" : CENTER_ROOM"guest4.c",
  "west" : CENTER_ROOM"tin1.c",
]));
  set("light_up", 1);
  set("file_name", CENTER_ROOM"guest3.c");

  setup();
}
