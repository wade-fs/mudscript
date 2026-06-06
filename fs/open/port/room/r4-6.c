// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","四海刀聯");
	set( "build", 108 );
  set ("long", @LONG
這裡是天下刀客總本部 . 屋內的陳設簡單而有威嚴 , 西首
一張太師椅 , 刀聯會長雷一鳴正竭誠的歡迎著你的到來 . 刀客
總部是在十年前從蜀中遷來的 , 換了個環境 , 人氣也旺了許多
 . 你可以在此加入(join)刀客的陣容 . 南邊是刀客的交誼廳 .

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
	"south" : "/open/port/room/r4-7.c",
	"north" : "/open/port/room/r4-3",
]));
	set("objects",([
	"/daemon/class/blademan/master":1,
	"/open/port/npc/blademan":1,
	]));

  setup();
}
int valid_leave(object me, string dir)
{
	if(me->query("class")!="blademan"&&dir=="south")
return notify_fail("那裡只有刀客能夠進去!\n");
return ::valid_leave(me,dir);
}
