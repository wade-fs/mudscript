// Room: /open/gblade/port/room/p3-2.c
inherit ROOM;

void create ()
{
  set ("short", "中央大道");
  set ("long", @LONG
寬廣的石板路 , 嶄新的建築 , 繁榮的街景 , 這裡真是個
希望之都啊 . 道路往南銜接港口 , 西邊是楓林港最大的客棧
因為通航帶來的大量旅客 , 客棧生意非常之好 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"p4-1.c",
  "south" : __DIR__"p3-3.c",
  "north" : __DIR__"p3-1",
]));

  setup();
}
