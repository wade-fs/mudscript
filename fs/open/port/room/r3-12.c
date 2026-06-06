// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","華清池");
  set ("long", @LONG
清池是個人工湖 , 池面長百五十尺 , 深二丈 . 池畔有個
廣場 , 每到假日 , 常有許多街頭賣藝者在此表演 , 非常熱鬧 .

LONG);

  set("light_up", 1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 2 */
	"east" : "/open/port/room/r3-13",
	"west" : "/open/port/room/r3-11",
	"north" : "/open/port/room/r3-15",
	"south" : "/open/port/room/r3-9",
]));

  set ("資源/液體", ([
       "種類" : "水",
       "名稱" : "清水",
       "止渴" : 30
  ]) );

  setup();
}
