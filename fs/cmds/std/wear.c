// wear.c
//code排版跟統一穿裝備時訊息前後的顏色不一的問題 by blazakira 2011/6/22

#include <ansi.h>
inherit F_CLEAN_UP;

int do_wear(object me, object ob);

int main(object me, string arg)
{
  object ob, *inv;
  int i, count;

  if( !arg ) return notify_fail("你要穿戴什麼﹖\n");
  arg = lower_case(arg);

  if(arg=="all") {
    inv = all_inventory(me);
    for(count=0, i=0; i<sizeof(inv); i++) {
      if( inv[i]->query("equipped") ) continue;
      if(do_wear(me, inv[i]) ) count ++;
    }
    write("Ok.\n");
    return 1;
  }

  if( !objectp(ob = present(arg, me)) )
    return notify_fail("你身上沒有這樣東西。\n");

  if( ob->query("equipped") )
    return notify_fail("你已經裝備著了。\n");

  return do_wear(me, ob);
}

int do_wear(object me, object ob)
{
  string str, gender;

  if( me->query("race") == "人類" &&
      (gender=ob->query("gender_only")) &&
      gender != (string)me->query("gender") )
  {
    if (gender == "女性")
      return notify_fail("這是女人的衣衫﹐你身為男人也想穿﹐羞也不羞﹖\n");
    else
      return notify_fail("這是男人的衣衫﹐你身為女人也想穿﹐羞也不羞﹖\n");
  }

  if( ob->wear() ) {
    if( !stringp(str = ob->query("wear_msg")) )
      switch( ob->query("armor_type") ) {
        case "cloth":
        case "armor":
        case "boots":
          str = YEL + "$N穿上一" + ob->query("unit") + "$n" + YEL + "。\n" + NOR;
          break;
        case "head":
        case "neck":
        case "wrists":
        case "finger":
        case "hands":
          str = YEL + "$N戴上一" + ob->query("unit") + "$n" + YEL + "。\n" + NOR;
          break;
        case "waist":
          str = YEL + "$N將一" + ob->query("unit") + "$n" + YEL + "綁在腰間。\n" + NOR;
          break;
        default:
          str = YEL + "$N裝備$n" + YEL + "。\n" + NOR;
        }
      if( me->is_fighting() && userp(me) ) me->start_busy(1);
      message_vision(str, me, ob);
      return 1;
    } else
  return 0;
}
 
int help(object me)
{
  write(@HELP
指令格式 : wear <裝備名稱>
指令說明 : 
           這個指令讓你裝備某件防具。
其他參考 :
           remove，wield，unwield
HELP
  );
  return 1;
}
