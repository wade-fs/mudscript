// Room: /open/poison/room/room11
inherit ROOM;

void create ()
{
  set ("short", "說法堂");
  set ("long", @LONG
這裡是用以傳授武學知識的地方，並時常於此地比試武
功，用以決定教徒的各種升遷，及考驗教徒所學之技能，以
決定是否能傳授更高深的武學。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"room13",
  "north" : __DIR__"room12",
  "east" : __DIR__"road18",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/elder1" : 1,
]));

  setup();
}
