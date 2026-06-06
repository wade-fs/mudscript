// Room: /open/badman/room/r5
inherit ROOM;

void create ()
{
  set ("short", "賭場");
  set ("long", @LONG
這裡聚集了一大堆沒活幹的強盜嘍嘍們，整著房間吵的跟菜市
場一樣，令人感到難受。你奮力湊到人群中看個仔細，才發現原來
這裡是惡人谷裡面唯一的賭場，難怪會有這麼多不務正業的強盜們
待在這裡。你發現所有人正圍著一個留著滿臉鬍子的人不知在看什
麼熱鬧。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"b9",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/badman/npc/kwan" : 1,
]));
  set("light_up", 1);

  setup();
}
