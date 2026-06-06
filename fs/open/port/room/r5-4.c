// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","海岸");
	set( "build", 12 );
  set ("long", @LONG
這裡是楓林港的海岸 . 為免海水倒灌 , 或是有人遭到意外
 , 居名們在海岸旁加修了一道護堤 . 堤防上有幾個漁民正在垂
釣 . 西邊即是漁港 , 稀稀疏疏的停著幾搜漁船 . 自從商港建立
以後 , 大部份的漁民都從商去了 , 漁港生意也因此一落千丈 , 
從前數百搜漁船的盛況 , 再也難以目睹了 .

LONG);

  set("light_up", 1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 2 */
	"east" : "/open/port/room/r5-3",
	"north" : "/open/port/room/r5-6",
]));
	set("objects",([
	"/open/port/npc/fisherman":2,
	]));

  setup();
}
