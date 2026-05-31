// 幫派接受求和 by Chan
// 只能由幫主使用
#include <ansi.h>
inherit F_CLEAN_UP;
int help( object me );
int main( object me)
{
  int    money,su_money;
  string  clan_su,str1;
  object ob;
  if( !me->query("clan/name"))
    return notify_fail("只有幫派的人才能使用此指令!!!!\n");
  if(me->query("clan/rank") > 1)
    return notify_fail("只有幫主能接受求和!!!!\n");
  if(!CLAN_D->clan_query(me->query("clan/id"),"war"))
    return notify_fail("只有在戰爭狀態下才能接受求和!!!!\n");
  clan_su=CLAN_D->clan_query(me->query("clan/id"),"clan_war");
  str1=CLAN_D->clan_query(clan_su,"master");
  ob=find_player(str1);
  if(!ob) ob=find_living(str1);
  if(!ob)
     return notify_fail("沒有幫派向貴幫求和!!!\n");
  if(!ob->query_temp("clan_surrender"))
     return notify_fail("沒有幫派向貴幫求和!!!\n");
  su_money=ob->query_temp("clan_money");
  write("你接受了求和的建議!!!\n");
  CHANNEL_D->do_channel(me, "chat", "我"+me->query("clan/name")+"的"+me->query("clan/title")+"願接收"+ob->query("clan/name")+"的求和要求!!停止雙方的戰爭!!!" );
  ob->delete_temp("clan_surrender");
  ob->delete_temp("clan_money");
  CLANV_D->clan_stop_money(clan_su,su_money);
  return 1;
}

int help( object me )

{
    write(@HELP

格式說明:cagree
指令說明:
         接收對方的求和...。
HELP
    );
 return 1;
}


