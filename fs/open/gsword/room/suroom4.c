// Room: /open/gsword/room/suroom4.c

inherit ROOM;

void create ()
{
  set ("short", "民房");
  set ("long", @LONG
一間普通的民房,平淡的擺設,然而卻灑掃乾淨,一般的蜀中
市民都居住在如此環境裡.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/gsword/room/su11",
]));

  set("light_up", 1);

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/woman" : 1,
]));

  setup();
}
