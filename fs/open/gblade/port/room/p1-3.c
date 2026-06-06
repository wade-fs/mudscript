// Room: /open/gblade/port/room/p1-3.c
inherit ROOM;

void create ()
{
  set ("short", "中央廣場");
  set ("long", @LONG
這是一個大廣場 , 東西南北四條大路構成了楓林港的主體
這裡是楓林港的中心地帶 , 街道來來往往的行人 , 有刀客 , 
有商人 , 也有些鬼鬼祟祟的旅客 , 真是個五花八門的城市 ,
西邊是楓林港最繁榮的商業地帶 , 南邊為港阜所在 , 東邊則
是刀客的大本營 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"p1-2",
  "south" : __DIR__"p3-1.c",
  "west" : __DIR__"p2-1.c",
  "east" : __DIR__"p1-4.c",
]));

  setup();
}
