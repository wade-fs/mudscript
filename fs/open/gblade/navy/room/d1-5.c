// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","閱\武場");
  set ("long", @LONG
這裡是一片極大的廣場 . 你看到數千人打著赤膊 , 頂著烈
日 , 面對著大海辛勤的操練著 . 動作整齊一致 , 喝聲響徹雲
霄 . 你不禁暗暗佩服水軍總督卓越的治兵能力 , 如此雄兵 , 
何堅不摧 ? 何城不破 ? 東邊是一大片的軍營 , 南邊是海 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 2 */
	"west" : "/open/gblade/navy/room/d1-4.c",
	"north" : "/open/gblade/navy/room/d1-7.c",
]));
	set("objects",([
	"/open/gblade/navy/npc/soldier":1,
	"/open/gblade/navy/npc/monitor":1,
	]));

  setup();
}
