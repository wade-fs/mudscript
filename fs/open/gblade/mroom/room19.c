// Room: /u/m/moner/room/room19.c
inherit ROOM;

void create()
{
  set ("short", "水雲軒");
  set ("long", @LONG

清蔥的翠綠籠罩著此處, 佳木籠蔥, 奇花爛爛, 一帶清流從花木深處
瀉於石縫之中, 清風微拂, 翠竹搖曳, 藤蘿掩映中, 你的眼皮漸漸感到
沉重了。

LONG);

  set("light_up", 1);
  set("outdoors", "wind");
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room17.c",
]));
  setup();
}
