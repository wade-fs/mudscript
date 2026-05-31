// remove.c
//code排版跟統一穿裝備時訊息前後的顏色不一的問題 by blazakira 2011/6/22

#include <ansi.h>
inherit F_CLEAN_UP;

int do_remove(object me, object ob);

int main(object me, string arg)
{
  object ob, *inv;
  int i;

  if( !arg ) return notify_fail("你要脫掉什麼﹖\n");
  arg = lower_case(arg);

  if(arg=="all") {
    inv = all_inventory(me);
    for(i=0; i<sizeof(inv); i++)
    {
      if( inv[i]->query_temp("can_not_remove") )
        return notify_fail("依你目前的狀態無法卸下這項裝備。\n");
      do_remove(me, inv[i]);
    }
    write("Ok.\n");
    return 1;
  }

  if( !objectp(ob = present(arg, me)) )
    return notify_fail("你身上沒有這樣東西。\n");
  if( ob->query_temp("can_not_remove") )
    return notify_fail("依你目前的狀態無法卸下這項裝備。\n");
  return do_remove(me, ob);
}

int do_remove(object me, object ob)
{
  string str;

  if( (string)ob->query("equipped")!="worn" )
    return notify_fail("你並沒有裝備這樣東西。\n");

  if( ob->unequip() ) {
    if( !stringp(str = ob->query("unequip_msg")) )
      switch(ob->query("armor_type")) {
        case "cloth":
        case "armor":
        case "surcoat":
        case "boots":
          str = YEL "$N將$n"YEL"脫了下來。\n" NOR;
          break;
        case "bandage":
          str = YEL "$N將$n"YEL"從傷口處拆了下來。\n" NOR;
          break;
        default:
          str = YEL "$N卸除$n"YEL"的裝備。\n" NOR;
      }
    message_vision(str, me, ob);
    if( me->is_fighting() && userp(me) ) me->start_busy(1);
    return 1;
  }
  else
    return 0;
}

int help(object me)
{
  write(@HELP
指令格式 : remove all | <物品名稱>
指令說明 : 
           這個指令讓你脫掉身上某件防具。
其他參考 :
           wear，wield 
HELP
  );
  return 1;
}
