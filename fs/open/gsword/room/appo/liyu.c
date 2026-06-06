inherit ROOM;
#include <ansi.h>
void create ()
{
  seteuid(getuid());   
set ("short", "密室");
  set ("long", @LONG
一入房門 ,你馬上感到寒氣撲面而來 ,略一凝神 ,只見左手一個平台上 ,一個暗藍色的(box) 散發出令你趕到無比舒適的靈氣，使你忍不住想去開啟它。

LONG);
  set("exits", ([ /* sizeof() == 2 */
  "out" : "/open/mogi/forest/entrance.c"
]));
  set("light_up", 1);
  set("no_clean_up",1);
  setup();
}
 void init()
{
 add_action("open_box","open");
 }

  int open_box(string str)
 {
  object me,ob;
  me =this_player();
    message_vision("箱內竟是空無一物 ,你不禁呆了一會\n",me);
  me->set("liyu",3);
  return 1;
  }
