inherit ROOM;
#include <ansi.h>
void create()
{
  set("short",HIR + "不死鳥ソ塔" + NOR);
  set("long", @LONG 

這裡聳立著一座巨大的高塔聳立，古老、憂鬱的氣息遠遠
傳出，你現在正面對聚塔的大門，然而大門上卻貼著一道
封條，而有這道封條在，任憑你耗費多大力氣也無法推動
這扇門。

LONG);
  set("exits", ([ /* sizeof() == 1 */
      ]));
  set("light", 1);
  setup();

}

void init()
{
  add_action("do_touch","touch");
}

int do_touch(string str)
{
  object me=this_player();
  string arg;
  if(!str||sscanf(str, "%s",arg)!=1)
    return notify_fail("你在摸什麼？\n");
  if(arg != "door")
    return notify_fail("你在摸什麼？\n");
  if(this_object()->query_temp("have_player")==1)
    return notify_fail("你摸的大門忙線中，請稍後再摸，謝謝！\n");
  if( arg == "door")
  {
   if(me->query("class")!="beggar")
     return notify_fail("你不是丐幫的人，無法進入。\n");
   if(me->query("beggar/got_cloudstaff")==1)
   {
    message_vision(HIR + "$N將手放在大門上，突然......\n" + NOR,me);
    message_vision(HIR + "$N被吸入門內，消失眼前。\n" + NOR,me);   
    me->move("/open/beggar/tower/top1");
   }
   else
   {
    message_vision(HIR + "$N將手放在大門上，突然......\n" + NOR,me);
    message_vision(HIR + "$N被吸入門內，消失眼前。\n" + NOR,me);
    me->move("/open/beggar/tower/stair");
    //this_object()->set_temp("have_player",1);
   }
    return 1;
  }
}


