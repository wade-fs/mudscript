// refresh.c
// refix by chan
int exert(object me, object target)
{
 int force,max_force,limit_force,value;
 limit_force=(int)me->query("max_force")/100;
 limit_force=limit_force*5;
 if(limit_force > 125)
  limit_force=125;
 if(limit_force < 5)
  limit_force=5;
 if((int)me->query("force")<20) //至少要20以上才能用吧.....by chan
  return notify_fail("你的內力不夠。\n");
 if((int)me->query("force")< limit_force)
  return notify_fail("你的內力不夠。\n");
 if( target != me ) return notify_fail("你只能用內功\收歛自己的心神。\n");
 value=(int)me->query("max_force")/4;
 if(value<50) //保障新手條款
   value=50;
 if(value>200) //設定上限
   value=200;
//以上修正by chan
     me->add("force", -limit_force);
 me->receive_heal("sen",value);
//以上fix  by chan
//        message_vision("$N略一凝神﹐吸了口氣﹐精神看起來清醒多了。\n", me);
        if( me->is_fighting() ) me->start_busy(1);
        return 1;
}
