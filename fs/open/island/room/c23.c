#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", HIB+"寒冰洞"+NOR);
  set ("long", @LONG
你跌入了一個陰寒的洞中 ,四週的寒氣凍得人手腳皆不靈
光 ,你正走在一塊巨大的冰棚上 ,幽藍的光芒自遙遠的冰下透
上來 ,透著詭異而迷離的氣氛...


LONG);
 set("exits", ([ /* sizeof() == 4 */
  "west" : "/open/island/room/c22",
    "east" : "/open/island/room/c20",
  "north" : "/open/island/room/c17",
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




