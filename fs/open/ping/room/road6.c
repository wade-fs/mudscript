// Room: /open/ping/room/road6.c
inherit ROOM;

void create ()
{
  set ("short", "石板大道");
	set( "build", 248 );
  set ("long", @LONG
這裡是平南城的西區,每次苗人的進犯,這兒都是首當其衝,
然而這裡的百性似忽已習慣刀槍下過日子, 依然悠閒的作生意
,你的南方便是軍營,駐有守城的大軍.
北邊似乎是一處森林,看起來有點陰森!
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"road10",
  "north" : __DIR__"m2",
  "west" : __DIR__"wdoor.c",
  "east" : __DIR__"road5",
]));
  set("outdoors", "/open/ping");

  setup();
}
