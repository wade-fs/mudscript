// Room: /open/gblade/port/room/p3-1.c
inherit ROOM;

void create ()
{
  set ("short", "中央大道");
  set ("long", @LONG
寬廣的石板路 , 嶄新的建築 , 繁榮的街景 , 這裡真是個
希望之都啊 . 道路往南銜接港口 , 路上多的是來自各大陸的
人 , 有些人鼻子高高的 , 頭髮是金黃色的 , 真像猴子 , 也
有些來自冥魔島的人 , 你最好少惹他們 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"p3-2.c",
  "north" : __DIR__"p1-3",
]));
	set("objects",([
	"/open/gblade/port/npc/traveller":1,
	]));

  setup();
}
