// Room: /open/main/room/f26.c

inherit ROOM;

void create()
{
	set("short", "森林");
	set( "build", 12 );
	set("long", "這裡是一片廣大的原始森林，參差的樹木雜亂的長著，陽
光透過枝葉灑下點點金黃，地上則凌亂的部滿落葉與雜草.
");

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"f25",
  "south" : __DIR__"f27",
  "west" : __DIR__"s32",
  "east" : __DIR__"r46",
]) );

  set("outdoors", "/open/main" );


  setup();
}
