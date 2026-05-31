//儒門三十六計裡的陣法計
//類似像仙劍的劍陣一樣，會以人數啟動
//為一不同的是，用計者並不會參與戰鬥
//只是在旁邊觀看，就像古時候的軍師
//只在旁邊出策略。
//
//
//陣法暫定為：
//
//自由搏擊：	此陣需要兩個NPC 來助陣，其NPC 的攻擊力，防禦力不減
//鶴翼之陣：	此陣需要三個NPC 來助陣，其NPC 的攻擊力*2/3，防禦力*3/2
//四方之陣：	此陣需要四個NPC 來助陣，其NPC 的攻擊力/2,防禦力*2
//魚鱗之陣：	此陣需要五個NPC 來助陣，其NPC 的攻擊力=(攻擊力+防禦力)，防禦力 = 0

#include <ansi.h>
int perform(object me,object target)
{

  int i,m,k=0;
  int c=0;		// 用來給 who 累加用
  object room;
  mixed count,who;

  if( !target ) return notify_fail("你要對誰用計 ?\n");
  if( userp(target) ) return notify_fail("這招對玩者沒用。\n");
  if( me->query("sen") < 50 )
   return notify_fail("你的精神力不夠，無法用計。\n");
  if( me->query_skill("plan") <= 70 )
   return notify_fail("你的謀略能力不夠。\n");
//  if( me->query_skill("god-plan") <= 70)
//   return notify_fail("你對孔明兵法的了解不夠，無法使用此計。\n");
  if( me->query("family/family_name") != "儒門")
   return notify_fail("不是儒生，不給你用咧！！^_^\n");
  if( me->is_fighting() )
   return notify_fail("你沒空啦！！\n");

  room = environment(me);
  count = all_inventory(room);
who=all_inventory(room);

  for(i=0;i<sizeof(count);i++)
  {
   if( count[i]->query_temp("follow")==1)      // 假如此人中過 follow
{
     who[c++]= count[i];				// 將 count 抓到的人放到 who 裡面
   k=k+1;						// 原本用 i 來累加，會造成 who 不連續
}
  }

     if( k == 2 )
     {
      message_vision("\n$N大喝：「眾將聽令！」\n"+
      who[0]->query("name")+"，"+who[1]->query("name")+
      "\n隨即擺\開「自由搏擊」，給予"+target->query("name")+"迎頭痛擊。\n\n",me);
      who[0]->kill_ob(target);
      target->kill_ob(who[0]);
      who[1]->kill_ob(target);
      target->kill_ob(who[1]);
      target->start_busy(2);
     } else
     if( k == 3 )
     {
      message_vision("$N大喝：「眾將聽令！」\n"+
      who[0]->query("name")+"，"+who[1]->query("name")+"，"+who[2]->query("name")+
      "\n隨即擺\開「鶴翼之陣」，給予"+target->query("name")+"迎頭痛擊。\n\n",me);
      who[0]->kill_ob(target);
      target->kill_ob(who[0]);
      who[1]->kill_ob(target);
      target->kill_ob(who[1]);
      who[2]->kill_ob(target);
      target->kill_ob(who[2]);
      target->start_busy(3);
     } else
     if( k == 4 )
     {
      message_vision("$N大喝：「眾將聽令！」\n"+
      who[0]->query("name")+"，"+who[1]->query("name")+"，"+who[2]->query("name")+"，"+who[3]->query("name")+
      "\n隨即擺\開「四方之陣」，給予"+target->query("name")+"迎頭痛擊。\n\n",me);
      who[0]->kill_ob(target);
      target->kill_ob(who[0]);
      who[1]->kill_ob(target);
      target->kill_ob(who[1]);
      who[2]->kill_ob(target);
      target->kill_ob(who[2]);
      who[3]->kill_ob(target);
      target->kill_ob(who[3]);
      target->start_busy(4);
     } else
     if( k == 5 )
     {
      message_vision("$N大喝：「眾將聽令！」\n"+
      who[0]->query("name")+"，"+who[1]->query("name")+"，"+who[2]->query("name")+"，"+who[3]->query("name")+"，"+who[4]->query("name")+
      "\n隨即擺\開「魚鱗之陣」，給予"+target->query("name")+"迎頭痛擊。\n\n",me);
      who[0]->kill_ob(target);
      target->kill_ob(who[0]);
      who[1]->kill_ob(target);
      target->kill_ob(who[1]);
      who[2]->kill_ob(target);
      target->kill_ob(who[2]);
      who[3]->kill_ob(target);
      target->kill_ob(who[3]);
      who[4]->kill_ob(target);
      target->kill_ob(who[4]);
      target->start_busy(4);
     } else
     if( k <= 1 && k > 5 )
     {
     return notify_fail("此人數的陣形還再開發中，有意參與請洽卡邦。\n");
     }
  return 1;
}

