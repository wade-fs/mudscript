// Room: /open/poison/room/path7
inherit ROOM;

void create ()
{
  set ("short", "密道");
  set ("long", @LONG
看著白骨遍地，遠方傳來聲聲怪聲，不知是何種動物的
悲鳴，引起你內心陣陣寒意，突然內心一念昇起，莫非這就
是令武林提之變色、聞之喪膽的『陰朁道』，看樣子最好小
心一點，四周的一切事物或許都已經被下毒了，隨意觸摸的
話，難保不見閻王。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/poison/room/path8",
  "south" : "/open/poison/room/path6",
]));

  setup();
}
