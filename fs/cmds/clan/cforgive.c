// 幫派赦免指令 by Chan 11/29/98
// 只能由幫主發佈。
#include <ansi.h>
inherit F_CLEAN_UP;
int help( object me );
int main( object me,string str )
{
  int cgold;
  object ob,killer;
  if( !sizeof(str) )
    return notify_fail( "輸入格式錯誤!!請打help cforgive\n" );
  if(me->query("clan/rank") > 2)
    return notify_fail("你的階級不夠,不能使用追殺令!!!\n");
  ob=find_player(str);
  if(!ob) ob=find_living(str);
  if(!ob) ob=LOGIN_D->find_body(str);
  if(!ob)
     return notify_fail("你想赦免的人不在線上哦???\n");
 if(wizardp(ob)) // 修正by avgirl..真自私的cgy..只改自己的pig..av妳改錯了..反正ppl都只看我而已
     return notify_fail("你想赦免的人不在線上哦???\n");
  if(!userp(ob))
     return notify_fail("你只能赦免線上玩家哦!!!!\n");
  if(ob==me)
      return notify_fail("你想赦免自己呀!!!有沒有搞錯呀???\n");
  if(!ob->query("ckill"))
      return notify_fail("他又沒有被追緝!!怎麼赦免呀!!!\n");
  if(ob->query("ckill_id") != me->query("clan/name"))
      return notify_fail("你不是追緝他的幫派所以無法赦免!!!\n");
    message_vision("$N發出幫派特赦令,取消對$n所有的追緝及追殺!!\n",me,ob);
    CHANNEL_D->do_channel(me, "shout", "我"+me->query("clan/name")+"的"+me->query("clan/title")+"發出特赦令,原諒"+ob->query("name") +"並取消追殺令!!" );
    ob->delete("ckill_id");
    ob->delete("ckill");
  return 1;
}

int help( object me )

{
    write(@HELP

格式說明:cforgive <ID> 赦免被幫派追緝的人 (限幫主及階級二的人使用)
指令說明:
這是發出幫派的赦免令取消被幫派所發出追殺令的人的追緝令。
相關指令:help ckill
HELP
    );
 return 1;
}

