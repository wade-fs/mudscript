// Room: /u/d/dhk/questsfan/rm5
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "山林釮路");
  set ("long", @LONG
這一會兒，你又看到一隻金背火猿正把玩著一快亮晶晶
的石頭，你小心翼翼又躲躲藏藏的欲走的更進去觀察，生一
不小心成了火猿的點心…hmm。 又你仔細一瞧，哇！不得了
牠把玩的竟是曾在古書典籍記載的奇石〝釮石〞呀！這次真
是大開眼界了。

LONG);

  set("outdoors", "/u/d");
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tod.c" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"rm4",
  "westup" : __DIR__"rm6",
]));

  setup();
}
