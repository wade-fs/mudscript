// Room: /u/f/fire/room/room1-12.c
inherit ROOM;
#include <ansi.h>
#include "bonze.c"

void create ()
{
  set ("short", HIR"陽家藥店"NOR"聯盟臨時販賣處");
	set( "build", 60 );
  set ("long", @LONG
你走進一間充滿著藥味的帳篷中，這裏是一間藥鋪。在這裏你可
以買到各式各樣的藥材。在帳篷的四周是一排的木櫃子，在櫃子上到
處寫滿了各式的藥品名稱，令你看了都覺得眼花潦亂。雖然櫃子相當
新，但是裡面的藥品並不會短少。站在藥櫃前方的清麗少女想必是這
裡的負責人。

LONG);

  set("objects", ([ /* sizeof() == 2 */
__DIR__"npc/b2_mingming.c" : 1,
// __DIR__"npc/b3_doctor_qianni.c" : 1,
]));
  set("light_up", 1);
//  set("outdoors", "/u/b");
  set("no_transmit",1);
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"i09",
]));

  setup();
}
