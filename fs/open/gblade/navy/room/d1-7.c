// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","閱\武場");
  set ("long", @LONG
這裡是一片極大的廣場 . 你看到數千人打著赤膊 , 頂著烈
日 , 面對著大海辛勤的操練著 . 動作整齊一致 , 喝聲響徹雲
霄 . 東邊和北邊皆為軍營 , 除了幾個輪值人員留守外 , 大部
份的士兵都在閱武場接受訓練 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 2 */
	"south" : "/open/gblade/navy/room/d1-5",
	"west" : "/open/gblade/navy/room/d1-6",
]));
	set("objects",([
	"/open/gblade/navy/npc/monitor":1,
	"/open/gblade/navy/npc/soldier":1,
	]));

  setup();
}
