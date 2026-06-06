// Room: /open/poison/room/road10
inherit ROOM;

void create ()
{
  set ("short", "道路");
  set ("long", @LONG
東邊湖水清澈透明，可見魚兒悠游於湖中，湖面上則有
三兩隻小水鴨，水鴨們快樂的戲水著，微風吹拂湖面盪漾起
陣陣青波，不遠的前方可見一牌樓矗立在那兒。
LONG);

  set("outdoors", "/open/poison");

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/poison/room/road9",
  "northwest" : "/open/poison/room/road11",
]));

  setup();
}
