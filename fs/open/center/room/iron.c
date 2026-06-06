// Room: /u/p/powell/room/iron.c

inherit ROOM;

void create ()
{
  set ("short", "驛站鐵鋪");
  set ("long", @LONG
這是一間小鐵鋪, 平常以幫農夫村婦們打造菜刀、鋤具並修理壞掉的鐵
製器具為主, 由於最進馬賊強盜為害, 店主也開始賣起些重型或輕型的防身
武器來, 甚至還兼營起武器、防具的買賣。如果你對武器、防具有興趣, 開
口問問店主吧!
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : "/open/center/room/road2",
]));

  set("light_up", 1);

  setup();
}
