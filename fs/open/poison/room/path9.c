// Room: /open/poison/room/path9
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "石窟");
  set ("long", @LONG
你來到一個寬敞的石洞，這裡有幾張石桌石倚，石桌上
則擺了一盤石棋(chess) ，看來曾有文人雅士在這裡賞景對
奕，然如今洞前雜草叢生，幾乎淹沒整個洞口，只留絲絲斜
陽射入，洞內有一小小的坑道。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "chess" : "棋盤上積了一層厚厚的灰塵，看樣子已經很久無人至此對奕
了，哦！難不成你也想在這裡一展棋藝，只可惜無人可與你
著棋於此。
",
]));
  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"path8",
  "west" : __DIR__"road7",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/chi.c" : 1,
]));

  setup();
}
int valid_leave(object me, string dir)
{
  if( dir == "west")
message_vision(HIC + "$N很小心地穿過洞口草叢，隨即雜草又淹沒住整個洞口。\n" + NOR,me
);
  return ::valid_leave(me,dir);
}
