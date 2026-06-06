// Room: /open/poison/room/road9
inherit ROOM;

void create ()
{
  set ("short", "道路");
  set ("long", @LONG
你來到這裡眼前有一條道路向北綿延而去，東邊有一不
知名的湖，路邊長滿了高大的野草，就在此時，從身旁草叢
堆中發出沙沙聲響，內心浮現不安的感覺，此地似乎不宜久
留，還是早點離開為妙。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"road10",
  "southwest" : __DIR__"v1.c",
  "southup" : __DIR__"road8",
]));
  set("outdoors", "/open/poison");

  setup();
}
