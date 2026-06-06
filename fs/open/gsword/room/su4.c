// Room: /open/gsword/room/su4.c

inherit ROOM;

void create ()
{
  set ("short", "石板大道");
	set( "build", 326 );
  set ("long", @LONG
走在寬闊的青石板大道下,依稀可想像蜀中城過去的興榮,然
而蜀中城就竟是蜀州要城,雖然沒落,尚保有過去的一絲繁華,南方
就蜀中城的鬧區,你可以在那裡買些東西, 西方則是著名的蜀中風
景區,蜀山.北方則是將軍府.
LONG);

  set("light_up", 1);
  set("outdoors", "/open/gsword");

  set("exits", ([ /* sizeof() == 4 */
  "west" : "/open/gsword/room/froad3",
  "south" : "/open/gsword/room/su3",
  "north" : "/open/gsword/room/suking",
  "east" : "/open/gsword/room/su13",
]));

  setup();
}
