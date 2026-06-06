// Room: /open/soulin/room/big.c

inherit ROOM;

void create ()
{
  set ("short", "$HIY$寶殿密室$NOR$");
  set ("long", @LONG
這裡是放置少林討論版的房間。
LONG);
  set("no_magic", "1");
  set("build", 12);
  set("light_up", "1");
  set("exits", ([ /* sizeof() == 1 */
    "south" : __DIR__"s20.c",
  ]));

  setup();
  call_other("/obj/board/bonze_wiz","???");
}
