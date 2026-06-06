// Room: /open/gblade/port/room/p1-5.c
inherit ROOM;

void create()
{
  set ("short", "四海刀聯");
  set ("long", @LONG
這裡是刀客總部所在 , 由於金刀門立足於此 , 刀客總部也
在十餘年前從蜀中遷移來此 , 就近招收刀客 , 而楓林港也因此
成為刀客的大本營 , 只要加入 (join) 刀客的行列 , 你就能向
各大刀派拜師學藝 .

LONG);

set("objects",([
	"/daemon/class/blademan/master" :1 ,
	"/open/gblade/port/npc/blademan":1,
]));
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"p1-4",
]));
  setup();
}
