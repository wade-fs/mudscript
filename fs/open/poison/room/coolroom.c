inherit ROOM;

void create ()
{
  set ("short", "魔殿秘室");
  set ("long", @LONG
這裡是一間神秘的地下室，裡面立有二十五尊黝暗的銅人，每一尊銅人都
擺了一個不同的姿勢，而它們的表情也隨著動作而有所不同。兩旁燒著熊
熊的大火，將這間地下室照的神秘而詭異。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"room17",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/teacher.c" : 1,
]));
  set("light_up", 1);
  set("no_fight", 1);

  setup();
}
