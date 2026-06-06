// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","閱\武場");
  set ("long", @LONG
這裡是一片極大的廣場 . 你看到數千人打著赤膊 , 頂著烈
日 , 面對著大海辛勤的操練著 . 動作整齊一致 , 喝聲響徹雲
霄 . 據說就算處於楓林鬧市 , 也能清楚的聽到士兵們的呼喝聲
 . 現在身臨現場 , 更是讓人聞之喪膽 . 北邊是軍營 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 2 */
	"south" : "/open/gblade/navy/room/d1-4.c",
	"east" : "/open/gblade/navy/room/d1-7.c",
]));
	set("objects",([
	"/open/gblade/navy/npc/soldier":2,
	]));

  setup();
}
