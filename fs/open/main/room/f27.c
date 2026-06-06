// Room: /open/main/room/f27.c

inherit ROOM;

void create()
{
	set("short", "森林");
	set( "build", 175 );
	set("long", "這裡是一片廣大的原始森林，參差的樹木雜亂的長著，陽
光透過枝葉灑下點點金黃，地上則凌亂的部滿落葉與雜草.
");

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"f26",
  "west" : __DIR__"s39",
  "east" : __DIR__"f28",
]) );
  set("objects",([
  "/open/main/npc/chou-kau" : 1,
  ]));
  set("outdoors", "/open/main" );


  setup();
}
