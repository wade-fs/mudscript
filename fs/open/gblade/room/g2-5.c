inherit ROOM;

void create ()
{
  set ("short", "水池");
	set( "build", 119 );
  set ("long", @LONG

你一步步行到水池來，只見各色水禽盡都在池中浴水，也認不出名色來，
但見一個個文彩閃灼，好看異常，因而站住，看了一回。池中有一亭，亭
上有一匾，寫著『滴翠亭』亭子四面俱是遊廊曲欄，四面雕鏤隔子，糊著
紙。池邊略略有幾點山石，種著芭蕉，那邊有兩隻仙鶴在松樹下剔翎。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/gblade/npc/crane.c" : 2,
]));
  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"g2-3",
]));

  set ("資源/液體", ([
       "種類" : "水",
       "名稱" : "清水",
       "止渴" : 30
  ]) );

  setup();
}
