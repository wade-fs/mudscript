// Room: /open/poison/room/path8
inherit ROOM;

void create ()
{
  set ("short", "密道");
  set ("long", @LONG
這裡應該就是令人畏懼心寒的『陰朁道』吧，北邊可見
到令人感到溫暖窩心的光線，想必那邊是此密道的出口，不
自覺地你被那光線所吸引，極想盡快離開這陰森濕冷，又充
滿危機的鬼地方。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/poison/room/path7",
  "northwest" : "/open/poison/room/path9",
]));

  setup();
}
