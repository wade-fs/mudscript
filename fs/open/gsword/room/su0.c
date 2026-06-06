#include "/open/open.h"

inherit ROOM;

void create ()
{
  set ("short", "蜀中城之南門");
	set( "build", 18 );
  set ("long", @LONG
一座斑駁的石砌城門展現在你眼前,似乎在訴說著蜀中城的悠
遠歷史,高聳的城牆,滄桑的匾額(sign),告訴你這城也曾經有過輝
輝煌的時候,如經她已從歷史中退役,只剩仙劍派還留在這裡...
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "
這是一座古老的匾額,只見上面題著:

    縱使鵝毛難飛越  龍盤虎踞蜀中城

                  承平元年,開城紀念
",
]));

  set("light_up", 1);
  set("outdoors", "/open/gsword");

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/main/room/[2]",
  "north" : "/open/gsword/room/su1.c",
]));

  setup();
}
