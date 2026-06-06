inherit ROOM;

void create ()
{
  set ("short", "小溪邊");
  set ("long", @LONG
順著小溪往前走 ,前面是一小片竹林 ,令你不禁想起了蘇東坡的
名句 :無竹使人俗 .想起這位大文豪 ,你不自覺的想起了垂涎已
久的東坡肉 ,望著自己微凹的小腹 ,唉 ,無肉使人瘦真是一點也
不假啊 !

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"room27",
  "north" : __DIR__"room38",
]));
  setup();
}


