// Room: /open/poison/room/room0
inherit ROOM;

void create ()
{
  set ("short", "魔教總壇");
  set ("long", @LONG
這裡便是令武林中人聞之變色的魔教總壇，殿中排了兩
排整齊的石像，地上鋪了一層虎皮毛毯，中間座前刻了一幅
巨龍雕像，那便是魔教的總精神象徵，想加入魔教的人便是
在此宣誓入教的。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road2",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/daemon/class/poisoner/poisoner" : 1,
]));
  set("light_up", 1);

  setup();
}
