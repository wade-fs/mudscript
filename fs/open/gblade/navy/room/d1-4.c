// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","閱\武場");
	set( "build", 12 );
  set ("long", @LONG
這裡是一片極大的廣場 . 由於水軍僅建軍數年 , 一切尚在
起步階段 , 士兵們平日最重要的是就是訓練武技 . 你看到數千
人打著赤膊 , 頂著烈日 , 面對著大海辛勤的操練著 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 2 */
	"west" : "/open/gblade/navy/room/d1-3.c",
	"east" : "/open/gblade/navy/room/d1-5.c",
	"north" : "/open/gblade/navy/room/d1-6.c",
]));
	set("objects",([
	"/open/gblade/navy/npc/soldier":2,
	]));

  setup();
}
