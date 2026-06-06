// Room: /open/poison/room/road16
inherit ROOM;

void create ()
{
  set ("short", "中庭");
  set ("long", @LONG
你來到了一個庭院，這裡種滿了各種奇花異草，院內還
種有許多矮竹，短小圓滑的枝節，嗯~~這應該就是可愛的葫
蘆竹吧，中間為由漢白玉所鋪成的玉路，直達北邊大殿，庭
院東西兩旁設有小拱門，分別通往各堂樓。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/envoy5" : 1,
]));
  set("outdoors", "/open/poison");
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"room6",
  "west" : __DIR__"road18",
  "east" : __DIR__"road17",
  "northup" : __DIR__"room7",
]));

  setup();
}
