// Room: /open/bonze/room/k01.c
inherit ROOM;

void create ()
{
  set ("short", "柴房");
  set ("long", @LONG
這裡是少林寺的柴房，由於少林的人數並不少，因此常有人藉著砍
柴來修煉，是以這裡經常呈現滿倉的情況使得大廚等人不得不上言給方
丈，希望能騰出人手來保育山林與限制砍伐。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"k12.c",
  "south" : __DIR__"k14.c",
]));
  set("light_up", 1);
  setup();
}
