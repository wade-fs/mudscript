// ~babe~ (小雪球) ^O^
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "沼澤");
	set( "build", 48 );
  set ("long", @LONG
這是一片充滿污泥的沼澤,幾支蘆葦抽枝而起,卻掩蓋不住
這裡的泥獰與惡臭,點點浮萍漂在地面的污水上,你恨不得敢快
離開,但是你發現沼澤旁邊有一棵樹幹怪怪的。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : "/open/main/room/p6",
"east":"/open/area/fortress/forest01",             // 2005.6.19 Firedancer
  "west" : "/open/main/room/p11",
  "south" : "/open/main/room/p18",
]));

  set("outdoors", "/open/main");

  setup();
set("search_desc", ([ /* sizeof() == 1 */
"trunk" : HIM"樹幹上寫著十二邪星瞬間移動的心法(star)。\n"NOR,
]));
}

void init()
{
  add_action("babe_home","star");
}
int babe_home( string str )
{
  object babe = this_player();
  message_vision(HIW"$N向"HIC"雅典娜女神"HIW"請求"HIY"祝福"HIW"，瞬間身體隱一陣光芒。\n",babe);
//babe->move("/open/clan/evil/evil.c");
  message_vision("當$N的身影從"HIY"光芒"NOR"中走出，"HIW""HIC""HIW""HIC""NOR"的"HIB"邪氣"NOR"瞬時圍繞著$N身體四周。\n",babe);
  return 1;
}
