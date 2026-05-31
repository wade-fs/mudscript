// by sueplan 六韜火龍計修改 2000.7.26
//二度修改六韜奇略之火龍計於 2000.8.25 by sueplan

/*************************************************************************************
修改 By Kalin (2003-06-17)
a.增加限制-解過儒尊
b.增加限制-exp>500萬
c.取消quest/gold-fire的限制
d.調高傷害
e.拿掉大火計一定busy自己,改取隨機busy自己
*************************************************************************************/

#include <ansi.h>
int count;
int again(object me);
int perform(object me,object target)
{
        int i, dam, dam1, j;
        object *all = me->query_enemy();
        object who = this_player();
        count=0;
		if( !me->query("quests/god-plan"))
			return notify_fail("你沒解過孔明兵法的謎，不給你用咧！！^_^\n");
        if(!me->query("mark/sixgod-plan"))
			return notify_fail("你還沒解過『六韜奇略』!");
		if(me->query("combat_exp")<5000000)
			return notify_fail("你的經驗值不夠!");
		if(me->is_busy()) 
			return notify_fail("你現在是無法放火龍計的!!\n");
        if(!me->is_fighting())
			return notify_fail("火計只能在戰鬥中使用。\n");
        if( me->query("sen") < 50 )
			return notify_fail("你的精神力不夠﹐無法用計。\n");
        if( me->query_skill("plan") < 120 )
			return notify_fail("你的謀略能力不夠。\n");
        //加入如果用大火計在解穴時是不能放的
        if(me->query_temp("big_fire"))
			return notify_fail("你正在施放大火計, 此時是不可以再放火龍計的!!\n");
        // 不是儒門
        if( me->query("family/family_name") != "儒門")
			return notify_fail("不是儒生，不給你用咧！！^_^\n");
        me->add("sen",-20);
        me->start_busy(1);
        message_vision( HIR + @LONG
$N使用六韜奇略之中的火計﹗只見火舌似龍般飛舞於你的面前 .....

LONG + NOR , me , target );
  for( i = 0 ; i < sizeof(all) ; i ++ ) 
  {
  if( 80 > random(100))
  {
      //if( me->query("quest/gold-fire") && (me->query("combat_exp")>5000000))
      dam=who->query_skill("stabber")*10;
      //一般ppl大約只會到2100 + weapon 只能到2200
      dam1 = dam;
      if(dam1>2500)
      dam1=2500;
      j=who->query_skill("plan",1)*3;
     message_vision(HIW"$N熟知兵法運計之要，將"HIR"儒門火計"HIW"以及"HIG"六韜奇略"HIW"中大熱之計，和而為一，\n$n驟時發現身旁業火亂竄，竟然是赤壁之戰時所用之"HIR"『"HIC"火    龍    計"HIR"』"HIW"!\n\n"NOR , me , all[i] );
      all[i]->apply_condition("burn",30);  
      all[i]->receive_wound( "kee" ,dam1);
      all[i]->receive_wound( "sen" ,j);
      all[i]->receive_wound( "gin" ,j);
      COMBAT_D->report_status( all[i] );
  }
  else 
  message_vision( HIY + @LONG
$n見情勢不妙﹐跳了開來﹐逃過了一劫﹗
LONG + NOR , me ,all[i] );
  }
  if(me->query("env/大火計"))
  {
	  call_out("again",2,me);
	  me->set_temp("big_fire",1);
  }
  return 1;
}

//以下是set大火計會出現的情形
//大火計會busy自己4但考濾pkla 傷害不可太高
//加上書生穿meq 可能可以崩穴 by sueplan
int again(object me)
{
        int i;
        object *all = me->query_enemy();
        count ++;
        if(count > 4 || !me->is_fighting()) 
        {
                                      //新加避免儒門meq解穴後還可以放
          count = 0;
          me->delete_temp("big_fire");
          return 1;
        }
if (me->query("env/大火計"))
{
    if (me->query("bellicosity") < 500)
    {
    	  count = 0;
          me->delete_temp("big_fire");
	  return 1;
    }
    me->add("bellicosity",-5);
    //加入temp
    message_vision( HIY"$N大喊  : "HIC"『"HIW"六韜奇略，烈火焚天 "HIG"- "HIR"炬火計"HIC"』"HIY"一個巨大的火陣在眾人面前展開!!\n"NOR , me );
    for(i=0;i<sizeof(all);i++)
    {
        if(random(100) <80)
        {
        //all[i]->receive_wound( "kee" ,700);
		all[i]->receive_wound( "kee" ,700+random(300));
        //all[i]->receive_wound( "sen" ,100);
		all[i]->receive_wound( "sen" ,100+random(50));
        //all[i]->receive_wound( "gin" ,100);
		all[i]->receive_wound( "gin" ,100+random(50));
//傷精及神調降 
//busy 自己 4所以強度調高, 不然沒有busy(4)的強度 by sueplan
        COMBAT_D->report_status( all[i] );
        } 
        else 
        {
        message_vision( HIY + @LONG
$n見情勢不妙﹐跳了開來﹐逃過了一劫﹗
LONG + NOR , me ,all[i] );
        }
   }
   if(random(3)==1)   me->start_busy(1);
  call_out("again",2,me);
//busy算好了心跳時間, 故在放大火計時自己是不會出手的
  }
return 1;
}

