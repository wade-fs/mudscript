// Room: /open/gblade/port/room/p1-2.c
inherit ROOM;

void create ()
{
  set ("short", "中央大道");
  set ("long", @LONG
寬廣的石板路 , 嶄新的建築 , 繁榮的街景 , 這裡真是個
希望之都啊 , 絡亦不絕的行人湧入城市 , 大家臉上帶著自信
的笑容 , 人人都想在楓林港大展身手 , 創一番大事業 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"p1-3.c",
  "north" : __DIR__"p1-1",
]));

  setup();
}
