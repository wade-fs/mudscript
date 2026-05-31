#include <ansi.h>
// By Swy 最後修正 QC 98/6/20
int perform(object me, object target)
{
   int i, test=0;
   object room;
   mixed count;

   if( !target)
      return notify_fail("你要對誰使用借刀殺人之計。\n");
// 不準對玩家使用
   if( userp(target))
      return notify_fail("這招對玩者沒用。\n");

   if( me->query("sen") < 50 )
      return notify_fail("你的精神力不夠﹐無法用計。\n");

   if( me->query_skill("plan",1) < 80 )
      return notify_fail("你的謀略能力不夠。\n");

// 如果不是儒門的...hehe....
   if( me->query("family/family_name") != "儒門")
      return notify_fail("不是儒生，不給你用咧！！^_^\n");

   me->add("sen",-30);
   me->start_busy(1);
// 判斷計謀是否成功...
   if( 80 > random(100) )
   {
      room = environment( me);
// 將房間內的所有 NPC 抓出來...
      count = all_inventory( room );
      for( i=0; i< sizeof(count ); i++)
      {
// 如果是曾經有中過誘敵之計的, 就開始對 target 攻擊...
         if( count[i]->query_temp("follow") )
         {
           if(count[i]->query_temp("no_plan") || count[i]->query("no_plan"))
           {
           message_vision("$N忽然大聲的說道,竟敢對我使用計謀,看來你是活膩了!!去死吧!\n",count[i]);
           count[i]->kill_ob(me);
           me->start_busy(3);
           me->kill_ob(count[i]);
           }
           else{
            message_vision(HIW+ count[i]->query("name")+ "中了$N的借刀殺人之計, 開始朝"+ target->query("name")+ "發動猛烈的攻擊。\n"NOR, me);
            count[i]->kill_ob( target);
            target->kill_ob( count[ i]);  
// 用來判斷是否有任何的 NPC 發動攻擊了, 若為 0 則表示房間內無人中過誘敵之計...
            test++;
         }
      }
      if( test == 0)
         tell_object(me, "你想要借誰之手來幫你殺"+ target->query("name")+ "。\n");
           }
   }

   else
   {
      room = environment( me);
// 將房間內的所有 NPC 抓出來...
      count = all_inventory( room );
      for( i=0; i< sizeof(count ); i++)
      {
// 如果是曾經有中過誘敵之計的, 就開始對 me 攻擊...
         if( count[ i]->query_temp("follow")==1 )
         {
            message_vision(HIW+ target->query("name")+ "識破了$N的的借刀殺人之計, 與"+ count[ i]->query("name")+ "聯手朝你發動猛烈的攻勢。\n"NOR, me);
            count[i]->kill_ob( me);
// 用來判斷是否有任何的 NPC 發動攻擊了, 若為 0 則表示房間內無人中過誘敵之計...
            test++;
         }
      }
      message_vision(HIW+ target->query("name")+ "識破了$N的的借刀殺人之計, 朝你發動猛烈的攻勢。\n"NOR, me);
      target->kill_ob( me);
   }
   return 1;
}
