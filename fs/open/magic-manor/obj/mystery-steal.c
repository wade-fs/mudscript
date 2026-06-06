//調整色碼為ansi 改進使用者的判斷this_player()>>environment(this_object) 增加敘述以便測試 by blazakira 2011/4/14

#include <ansi.h>
#include <armor.h>
inherit NECK;
inherit F_SAVE;
inherit F_AUTOLOAD;

string inputstr,verb;

void create()
{
  set_name(HIC + "妙手空空套" + NOR,({"mystery steal"}));
  set_weight(1);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","\n");
    set("unit", "條");
    set("material","steal");
    set("value",10000);
    set("no_sell", 1);
    set("no_give",1);
    set("no_get",1);
    set("no_put",1);
    set("no_auc",1);
    set("no_drop",1);
    set("no_steal",1);
    set("armor_prop/armor", 10);
 }
  setup();
}

void init()
{
  add_action("do_steal","steal");
}

int do_steal(string arg)
{
  string ob,player;
  object obj, npc, me;
  me = environment(this_object());

  if(userp(me)) return 0;
  if(this_player(1) != environment(me)) return ;
  if(!arg) {
//    return notify_fail("\n");
    message_vision("沒指定目標！\n" + NOR,me,npc);
    return 1;
  }
  if(sscanf(arg, "%s from %s",ob,player) != 2) {
//    return notify_fail("\n");
    message_vision("指令錯誤！\n" + NOR,me,npc);
    return 1;
  }
  if ( !(npc = present(player, environment (me))) ) {
//    return notify_fail ("沒這個"+arg+"\n");
    message_vision("對方不在同一間房間。\n" + NOR,me,npc);
    return 1;
  }
  if(wiz_level(npc)>0) {
//    return notify_fail("\n");
    message_vision("只見$N悄悄貼近wiz$n但是被發現了。\n" + NOR,me,npc);
    return 1;
  }
  if (!(obj=present(ob, npc))) {
//    return notify_fail("\n");
    message_vision("$N沒這個東西。\n" + NOR,me,npc);
    return 1;
  }
  obj->move(me);
  message_vision("只見$N悄悄貼近$n，不動聲色的偷了$n的" + HIY+obj->name(1)+NOR + "。\n" + NOR,me,npc);
  return 1;
}

int query_autoload () //假使有意外被玩家持有也不允許autoload by blazakira
{
  return 0;
}
