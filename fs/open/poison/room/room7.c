// Room: /open/poison/room/room7
inherit ROOM;

void create ()
{
  set ("short", "大殿門口");
  set ("long", @LONG
你正站在大殿門口，整個殿堂為黃色琉璃屋瓦，赤紅色
的牆壁，兩側有以如意雲紋為柱礎的盤龍柱，讓人感到金碧
輝煌，氣象萬千，如皇宮般宏大壯觀。南邊則有一寬廣朝下
的石階，石階有一由漢白玉鋪成的斜坡，其上有龍鳳捲雲的
浮雕，石階兩旁有雕刻精美的玉欄杆。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room1",
  "southdown" : __DIR__"road16",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/fighter" : 2,
]));
  set("light_up", 1);

  setup();
}
