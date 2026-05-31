// Room: /d/snow/mstreet4.c

inherit ROOM;

void create ()
{
  set ("short", "[1;35m過去時空[0m 雪亭鎮街道");
  set ("long", @LONG
這裡是雪亭鎮的大街﹐一條小巷子通往東邊﹐西邊則是一間驛站﹐
由於雪亭鎮來往的商旅、官員並不很多﹐因此雖然是官府的驛站﹐也接
受百姓的信件﹐大街往北是一處山坳﹐從這裡遠遠地可以望見北方的野
羊山﹐出了山坳就是一條碎石路通往山上。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"postoffice",
  "south" : __DIR__"mstreet3",
  "north" : __DIR__"crossroad",
]));

  setup();
}
