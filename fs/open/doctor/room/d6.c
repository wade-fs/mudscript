// room ://open/doctor/room/d6.c made by adam

inherit ROOM;

void create ()
{
  set ("short", "診療室");
  set ("long", @LONG
走到這裡，看到許多病人病厭厭地坐在椅子上，醫生們
走來走去，只見原本病厭厭的病人，一下子就生龍活虎起來，
銀針醫術天下第一，果然名不虛傳。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"d5",
  "south" : __DIR__"d9",
//  "north" : __DIR__"doctor_room",
  "east" : __DIR__"d7",
]));
  set("light_up", 1);
  

  setup();
}
