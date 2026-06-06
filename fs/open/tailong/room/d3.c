inherit ROOM;

void create ()
{
  set ("short", "小木屋");
  set ("long", @LONG
屋子裡面相當的乾靜，雖然傢俱全都是木頭制品，但是卻不
貴給人有很粗糙的感覺，在你面前看書的正是段譽，只看他拿著
一本易經興趣盎然的讀著。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"d2",
]));
  set("objects",([
  "/open/tailong/npc/duanyu.c" : 1,
]));
  set("no_transmit",1);
  set("no_clean_up",1);
  setup();
}
