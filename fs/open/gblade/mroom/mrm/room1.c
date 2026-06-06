// Room: /u/m/moner/tree/room28.c
inherit ROOM;

void create ()
{
  set ("short", "映陽坡");
  set ("long", @LONG

高聳的山勢至此直轉而下， 一抹清渠隨著坡道奔向前方，順著山勢往下
流去。兩旁的坡道上長滿了野生的杏花，映著陽光，如噴花蒸霧一般，攀藤撫
樹而下，只見水上落花越多，其水越清澈，往前直走，水識越快，耳旁隱隱聽
到萬馬奔騰的聲音。

LONG);

  set("light_up", 1);
  set("outdoors", "wind");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room2.c",
"north":"/open/gblade/room/room29.c",
]));

  setup();
}
