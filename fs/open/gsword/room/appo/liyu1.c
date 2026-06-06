inherit ROOM;
#include <ansi.h>
int done;
void create ()
{
  seteuid(getuid());
set ("short", "密室");
  set ("long", @LONG
一入房門 ,你馬上感到寒氣撲面而來 ,略一凝神 ,只見左手一個平台上 ,一個暗藍色的(box)散發出令你趕到無比舒適的靈氣，使你忍不住想去開啟它。
LONG);
  set("exits", ([ /* sizeof() == 2 */
  "out" : "/open/scholar/room/r17.c"
]));
  set("light_up", 1);
  set("no_clean_up",1);
   set("no_reset",1);
  setup();
}
 void init()
{
 add_action("open_box","open");
  }

int open_box(string str)
 {
  object me;
  me =this_player();
  if( done== 0 )
      {
      message("system",HIC + "\n遠方天空出現突然出現數以千計的藍色光點..\n" + NOR,users());
      message_vision(HIC + "\n只見無數彩蝶圍繞在$N身邊，眼前的景象看的你目瞪口呆..\n" + NOR,this_player());
      call_out("msg1",3,me);
     }
   else
    message_vision("箱內竟是空無一物 ,你不禁呆了一會\n",me);
    me->set("liyu",0);
  done=1;
    return 1;
}

int msg1(object me)
{
  object ob;
  message("system",HIC + "\n轉眼間藍色光點慢慢聚集在世外書香..\n" + NOR,users());
  message_vision(HIC + "\n無數彩蝶頓時朝向$N飛去，驚愕之餘，彩蝶已幻化為筆凝聚在$N手中..\n" + NOR,me);
  ob=new("/open/gsword/new/pen.c");
  me->set_temp("liyu_pen",1);
if(!me->query("quests/shasword")) me->set("quests/shasword",1);
  me->set("liyu",0);
  ob->move(me);
  return 1;
  }
