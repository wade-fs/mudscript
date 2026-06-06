// Room: /open/gsword/room/suroom1.c

inherit ROOM;

void create ()
{
  set ("short", "民房");
  set ("long", @LONG
一間普通的民房,平淡的擺設,然而卻灑掃乾淨,一般的蜀中市民都
居住在如此環境裡.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/gsword/room/su6",
]));

  set("light_up", 1);

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/man" : 1,
  "/open/beggar/npc/boy" : 1,
]));

  setup();
}
