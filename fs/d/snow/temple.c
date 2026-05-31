#include <obj.h>

inherit ROOM;

void create ()
{
  set ("short", "[1;35m過去時空[0m 城隍廟");
  set ("long", @LONG
這是一間十分老舊的城隍廟﹐在你面前的神桌上供奉著一尊紅臉的城
隍﹐廟雖老舊﹐但是神案四周已被香火薰成烏黑的顏色﹐顯示這裡必定相
當受到信徒的敬仰。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"square",
  "south" : __DIR__"eroad1",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/obj/paper_seal" : 2,
]));
  set("no_fight", "1");

  setup();
}
