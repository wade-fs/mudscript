// Room: /open/gblade/port/room/p3-3.c
inherit ROOM;

void create ()
{
  set ("short", "港口");
  set ("long", @LONG
這裡就是港口了 , 不過你無法從這裡搭船 , 南邊是一片茫
茫的大海 , 一望無際 , 似乎充滿了各種危險 , 卻也滿是新奇的
事物 , 你真想搭船出去 , 到各地去闖一闖 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"p3-2",
]));

  setup();
}
