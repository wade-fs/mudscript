// Room: /open/gsword/room/gsword1-4.c
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
一條普通的走廊 ,連往仙劍的武器 ,防具室 .俗話說 :工欲擅其事 ,必先
利其器 ,沒有好的配備怎麼跟別人爭長短呢 ?北邊是武器室 ,南邊是護具室 .

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : "/open/gsword/room/g1-8.c",
  "north" : "/open/gsword/room/g1-7.c",
  "east" : "/open/gsword/room/g1-5.c",
]));

  set("light_up", 1);

  setup();
}
