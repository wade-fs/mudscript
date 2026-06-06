#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", HIB+"寒冰洞"+NOR);
  set ("long", @LONG
這裡是寒冰洞的最裡層 ,森森的寒氣彷彿要刺進骨頭裡去
似的 ,你的氣力正一點一滴的流失 ,眼前有個像巨大石塊般的
東西 ,原來是巨大無比的烏龜....


LONG);
 set("exits", ([ /* sizeof() == 4 */
  "southwest" : "/open/island/room/c1",
    "southeast" : "/open/island/room/c3",
  "east" : "/open/island/room/c2",
]));
set("objects", ([ /* sizeof() == 1 */
  "/open/island/npc/turtle" : 1,
]));


 
 set("light_up", 1);
 
 setup();
}
void init()
{
  object ob;
  if( interactive( ob= this_player()))
   {
        // 5秒後呼叫
        call_out("greeting", 2, ob);
   }
  add_action("do_team","team");

}

int greeting (object who)
{
  object room=environment(who);
//  判斷player是否在這個房間
  if(this_object() == room )
 who->add("kee",-70);
return 1;
}

int do_team(){
   object me=this_player();
   tell_object(me, "你手腳冰冷的不聽使喚!!\n");
   return 1;
}

