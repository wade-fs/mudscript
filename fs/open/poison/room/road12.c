// Room: /open/poison/room/road12
inherit ROOM;

void create ()
{
  set ("short", "石階");
  set ("long", @LONG
石階的兩旁設有大大的馬道，供馬車及驛馬行走，道路
兩旁種滿了櫻樹桃木，春天時樹上開滿紅花，整條石階一片
火紅，猶如一條火紅的赤龍。
LONG);

  set("outdoors", "/open/poison");

  set("exits", ([ /* sizeof() == 2 */
  "southdown" : "/open/poison/room/road11",
  "northup" : "/open/poison/room/road13",
]));

  setup();
}
