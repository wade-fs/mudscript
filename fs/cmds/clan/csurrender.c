// 幫派宣戰指令 by Chan
// 只能由幫主使用
#include <ansi.h>
inherit F_CLEAN_UP;
int help( object me );
int main( object me,string str )
{
  int    money,su_money;
  string  id,str1;
  object ob;
  if( !me->query("clan/name"))
    return notify_fail("只有幫派的人才能使用此指令!!!!\n");
  if( !sizeof(str) )
    return notify_fail( "輸入格式錯誤!!請打help csurrender!!\n" );
  if( sscanf(str,"%s %s %d",id,str1,su_money) != 3 )
    return notify_fail( "輸入格式錯誤!!請打help csurrender!!\n" );
  if(me->query("clan/rank") > 1)
    return notify_fail("只有幫主能求和!!!!\n");
  if(!CLAN_D->clan_query(me->query("clan/id"),"war"))
    return notify_fail("只有在戰爭狀態下才能求和!!!!\n");
  if(me->query("clan/id")== id)
    return notify_fail("你發瘋呀!!只能對別人幫派求和!!!!\n");
  if(!CLANV_D->clan_query(id))
    return notify_fail("沒有這個幫派......!!!\n");
    money=CLAN_D->clan_query(me->query("clan/id"),"gold");
  if(su_money < 200000)
    return notify_fail("要求和至少要在二十萬兩黃金以上!!!。\n");
  if(su_money > money)
   return notify_fail("幫派的錢不夠哦!!。\n");
  ob=find_player(str1);
  if(!ob) ob=find_living(str1);
  if(!ob)
     return notify_fail("對方幫主不在線上無法求和!!!!\n");
  if(ob->query("clan/rank") > 1)
     return notify_fail("他不是幫派的幫主!!!\n");
  if(ob->query("clan/id") != id)
     return notify_fail("他不是那個求和幫派的幫主!!!\n");
  CHANNEL_D->do_channel(me, "chat", "我"+me->query("clan/name")+"的"+me->query("clan/title")+"願以支付求和金"+ob->query("clan/name")+"停止雙方的戰爭!!!" );
  me->set_temp("clan_surrender",1);
  me->set_temp("clan_money",su_money);
  return 1;
}

int help( object me )

{
    write(@HELP

格式說明:csurrender <求和幫派的英文名稱> <對方幫主> <求和金>
指令說明:
         求和金至少要在二十萬兩黃金以上....。
HELP
    );
 return 1;
}


