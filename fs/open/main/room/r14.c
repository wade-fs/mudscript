// Room: /open/main/room/r14.c

inherit ROOM;

void create()
{
	set("short", "道路");
	set( "build", 24 );
	set("long", "	南方的草原上，隱約的看到有幾隻不知名的動物在追逐著
	，似乎很愉快的樣子，向東方看去有座大城，應該就是新
	京了。


");

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"f14",
  "west" : __DIR__"r13",
  "south" : __DIR__"s15",
  "east" : __DIR__"r15",
]) );

  set("outdoors", "/open/main" );


  setup();
}
