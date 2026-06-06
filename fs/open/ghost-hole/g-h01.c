#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "草原");
	set( "build", 15 );
  set ("long", @LONG
荒蕪的草地, 彷彿被死神所詛咒一般, 完全沒有任何生命
的跡象, 在草地的中央擺著一個骷髏(skeleton), 感覺上十分
的怪異。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "skeleton" : "一個奇異的骷髏, 完全看不出來是那一種生物的屍骨...\n",
]));
  set("outdoors", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/mon/npc/wolf.c" : 6,
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : "/open/mon/mon57",
]));

  setup();
}
void init()
{
        add_action("jump_skeleton", "jump");
}

int jump_skeleton(string str)
 {
      if (str!="skeleton") {
          return 0;
           } else

{
        object who;
        who = this_player();
        message("system",HIR + "\n"+who->query("family/family_name")+"" + HIW + "的" + HIY + ""+who->name()+"" + HIW + "不顧一切的跳入死靈骨堡裡，
誓言要將" + HIG + "死靈骨堡" + HIW + "內不可告人的秘密公諸於世。\n\n" + NOR,users());
        who->move("/open/ghost-hole/g-h02");
        return 1;
}
}

