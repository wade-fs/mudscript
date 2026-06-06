inherit ITEM;
#include <ansi.h>

void create()
{
  set_name("暗殺指令書", ({ "assassination list" }) );
  set_weight(50);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "張");
    set("long", "一張暗殺名單。\n");
    set("value",0);
    set("material", "paper");
    set("no_auc",1);
    set("no_drop",1);
    set("no_sell",1);
    set("no_give",1);
    set("no_put",1);
    set("no_get",1);
    set("no_save",1);
    set("no_steal",1);
    set("light_up",-1);
  }
  setup();
}

void init()
{
  add_action("do_list","use");
}

int do_list(string str)
{
  object me=environment(),ob;
  if( str=="assassination list" ) {
    me->apply_condition("wn_move",8);
    if( !me->query_temp("assassination list") ) {
      tell_object(users(),HIR"\n\t"HIB+me->query("name")+HIR"說道：………執行暗殺任務。\n\n"NOR);
      me->set_temp("assassination list",1); //暗殺活動的mark
      if(!userp(me)) { //不是玩家才需要額外的心跳輔助的功能
        ob=new("/open/japan/obj/archery_book.c"); //作為啟動輔助暗殺活動的npc而使用
        ob->move("/open/common/room/inn");
//        ob->move("/u/b/blazakira/room/workroom");
        environment(ob)->set("assassinating",1); //在房間做輔助mark
        destruct(ob);
      }
      write("action on.\n");
    }
  }
}
