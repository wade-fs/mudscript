// 幫派宣戰指令 by Chan
// 只能由幫主使用
#include <ansi.h>
inherit F_CLEAN_UP;
int help( object me );
int main( object me,string str )
{
  int   money,time=3600;
  string  str1,id;
  object ob;
  if( !me->query("clan/name"))
    return notify_fail("只有幫派的人才能使用此指令!!!!\n");
  if( !sizeof(str) )
    return notify_fail( "輸入格式錯誤!!請打help declare_war!!\n" );
  if( sscanf(str, "%s %s", id, str1) != 2 )
    return notify_fail( "輸入格式錯誤!!請打help declare_war!!\n" );
  if(me->query("clan/rank") > 1)
    return notify_fail("只有幫主能宣戰!!!!\n");
   if(CLAN_D->clan_query(me->query("clan/id"),"war"))
    return notify_fail("你以經宣戰了..不用在宣戰一次\n");
  if(me->query("clan/id")== id)
    return notify_fail("你發瘋呀!!只能對別人幫派宣戰!!!!\n");
  if(!CLANV_D->clan_query(id))
    return notify_fail("沒有這個幫派......!!!\n");
    money=CLAN_D->clan_query(me->query("clan/id"),"gold");
  if(money < 350000)
   return notify_fail("幫派存款至少要有三十五萬以上才能宣戰。\n");
  ob=find_player(str1);
  if(!ob) ob=find_living(str1);
  if(!ob)
     return notify_fail("對方幫主不在線上無法進入戰爭狀態!!!!\n");
  CHANNEL_D->do_channel(me, "shout", "我"+me->query("clan/name")+"的"+me->query("clan/title")+"宣佈對"+ob->query("clan/name")+"進入全面進攻狀態!!!" );
  me->set_temp("clan_war",1);
  if(ob->query_temp("clan_war"))
   {
     time+=time();
    me->delete_temp("clan_war");
    ob->delete_temp("clan_war");
    CLAN_D->clan_set(me->query("clan/id"),"war",1);
    CLAN_D->clan_set(me->query("clan/id"),"clan_war_end_time",time);
    CLAN_D->clan_set(ob->query("clan/id"),"clan_war_end_time",time);
    CLAN_D->clan_set(me->query("clan/id"),"clan_war",ob->query("clan/id"));
    CLAN_D->clan_set(ob->query("clan/id"),"war",1);
    CLAN_D->clan_set(ob->query("clan/id"),"clan_war",me->query("clan/id"));
    shout(HIR"快報!!快報!!中原武林中的二大幫派"+me->query("clan/name")+"及"+ob->query("clan/name")+"爆發出驚天動地的幫派大戰了!!!\n"NOR);
   log_file("clan/time",sprintf("%s和%s發動了幫派戰爭的時間%d及結束時間%d\n"
                ,me->query("clan/name"),ob->query("clan/name"),time(),time));
    CLAN_D->add_money(me->query("clan/id"),-50000);
    CLAN_D->add_money(ob->query("clan/id"),-50000);
    return 1;
   }
  return 1;
}

int help( object me )

{
    write(@HELP

格式說明:declare_war <宣戰幫派的英文名稱> <對方幫主>
指令說明:
         幫派宣戰指令!!!宣戰一次成功為要花費五萬兩黃金!!!!
HELP
    );
 return 1;
}


