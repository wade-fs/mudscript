// Room: /u/d/dhk/questsfan/room9
inherit ROOM;

void create ()
{
  set ("short", "哨站小屋");
  set ("long", @LONG
這是一間很普通的木製房屋，但是四周擺放的家具，
令你認為這裡並不像是一間住家。放眼四周只有四名壯漢
在此煮酒聊天，但是他們的一舉一動再再顯示他們並非普
通人，難道…
LONG);

  set("outdoors", "/u/d");
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wooder.c" : 1,
  __DIR__"npc/hunter.c" : 1,
  __DIR__"npc/farmer.c" : 1,
]));
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"qroom/room5",
]));

  setup();
}
