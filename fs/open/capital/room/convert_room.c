// Room: /open/capital/room/convert_room.c
inherit ROOM;

void create ()
{
  set ("short", "戰情室");
  set( "build", 84 );
  set ("long", @LONG
這裡是戰情官的辦公室，所謂戰情，顧名思意便是戰爭情形，古
人有云：知己知彼，百戰百勝，所以前線探子都會先來這裡回報戰況
，如果你在戰場上的戰功到了一定的程度，那麼戰情官便會給予你適
當的獎勵。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"r05.c",
]));
  set("objects", ([ /* sizeof() == 1 */
    "/open/capital/npc/gy.c" : 1,
  ]));
  set("no_fight", 1);
  set("light_up", 1);
  set("no_magic", 1);

  setup();
}

void init()
{
  add_action("do_team","team");
}

int do_team(){
  object me=this_player();
  tell_object(me, "李 喚叫道：不要在這裡組 team,或用 team 砍人。\n");
  return 1;
}
