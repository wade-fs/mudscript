// 幫派殺手指令 by Chan 10/30/98
// 只能由階級一、二的人使用
// 取消殺手的部份...改由所屬的幫派人物自動攻擊
#include <ansi.h>
inherit F_CLEAN_UP;
int help( object me );
int main( object me,string str )
{
  int cgold;
  object ob,killer;
  if( !sizeof(str) )
    return notify_fail( "輸入格式錯誤!!請打help ckill\n" );
  if(!me->query("clan"))
    return 0;
  if(me->query("clan/rank") > 3)
    return notify_fail("你的階級不夠,不能使用追殺令!!!\n");
  ob=find_player(str);
  if(!ob) ob=find_living(str);
  if(!ob) ob=LOGIN_D->find_body(str);
  if(!ob)
     return notify_fail("你想追殺的人不在線上哦???\n");
	 if(wizardp(ob)) // cgy 只改自己的..?_?...by avgirl..pig..av妳改錯了..反正ppl都只看我而已
     return notify_fail("你想追殺的人不在線上哦???\n");
  if(!userp(ob))
     return notify_fail("你只能追殺線上玩家哦!!!!\n");
  
  if(ob==me)
      return notify_fail("你想追殺自己呀!!!有沒有搞錯呀???\n");
  if( ob->query("ckill"))
    return notify_fail("他以經被追緝了。\n");
  if((me->query("clan/name")==ob->query("clan/name"))&&(me->query("clan/rank")>ob->query("clan/rank")))
    return notify_fail("你無法追殺自己的幫派老大!!\n");

    message_vision("$N發出幫派追殺令,傾所有幫派弟子全力追殺$n為\n",me,ob);
    CHANNEL_D->do_channel(me, "shout", "我"+me->query("clan/name")+"的"+me->query("clan/title")+"發出幫派追殺令,傾全幫全力追殺"+ob->query("name") +"!!" );

    ob->set("ckill",1);
    ob->set("ckill_id",me->query("clan/name"));
// ckill不收錢?!...改收錢 by avgirl 00/10/03
    CLAN_D->add_money(me->query("clan/id"),-(ob->query("combat_exp")/1000));
  return 1;
}

int help( object me )

{
    write(@HELP

格式說明:ckill <ID> 追緝指定的人 (限階級一、二及三的人使用)
指令說明:
  這是發出幫派的追殺令並花幫派的錢請暗殺組識派殺手去追殺指定的人,暗殺組識
會根據要殺的人的經驗值決定價碼!!!
ps:1.被追殺的人只限玩家。
   2.被追殺的人沒有安全區域,連格鬥場也一樣照死。
   3.被追緝的人要解除追緝只有死及被幫主赦免。
   4.替身在被追緝時有用。
   5.殺死追緝的人有錢可以拿。
   6.追緝的人可以quit。
   7.一個玩家只能由一個幫派發追緝令。
   8.只能在玩家線上時才能發出。
   9.非玩家的幫眾會自動去擒殺被追殺的人。
  10.缺錢的人可以考慮去殺追緝犯有錢可以拿。
  11.who - k是表示線上被追緝的人犯。
相關指令:help cforgive
HELP
    );
 return 1;
}

