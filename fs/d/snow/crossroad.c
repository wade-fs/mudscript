// Room: /d/snow/crossroad.c

inherit ROOM;

void create ()
{
  set ("short", "[1;35m過去時空[0m 山坳");
  set ("long", @LONG
這裡是一處山坳﹐往南就是雪亭鎮﹐一條蜿蜒的小徑往東通往另一
個鄰近的小山村﹐一塊官府立的告示牌立在路旁﹐上面寫著有關野羊山
土匪出沒的警告標誌。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"mstreet4",
]));
  set("outdoors", "snow");

  setup();
}
