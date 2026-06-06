#include <ansi.h>
inherit F_SPELL;
inherit SSERVER;
inherit F_CLEAN_UP;
int ena = this_player()->query("atman_factor",1);
int per = this_player()->query_per(1);
void remove_effect(object target, int amount);
int conjure(object me, object target)
//int cast(object me, object target)
{
	string msg;
	if( !target ) target = offensive_target(me);
	if( !target )
	return notify_fail("妳想打誰？\n");
	if( me->query("id") != "neverend" )
	return notify_fail("？\n");
	if( me->query_temp("madance") )
	return notify_fail("妳已經在跳舞了, 無法再分心跳其他舞了!!\n");
	if( !target->is_character() || target->is_corpse() )
	return notify_fail("看清楚一點﹐那並不是活物。\n");
	if(target->query_state("madanced") )
	return notify_fail("對方已經陷入妳的法術之中了喔!!\n");              
	if((int)me->query_skill("mamagic",1)<150)
	return notify_fail("妳的法術等級不足以施展此術!!\n");
	if(me->query("atman") < 1500)
	return notify_fail("妳的法力不足，使用不出這樣的舞步!!\n");
	message_vision(HIM + "                                                           \n" + NOR, me, target);
	message_vision(HIM + "                         `            '                    \n" + NOR, me, target);
	message_vision(HIM + "                          `          '                     \n" + NOR, me, target);
	message_vision(HIM + "                           :        :                      \n" + NOR, me, target);
	message_vision(HIM + "         ___               `        '               ___    \n" + NOR, me, target);
	message_vision(HIM + "         `Y88888ba.         :      :         .ad88888P'    \n" + NOR, me, target);
	message_vision(HIM + "           `88888888b.      `      '      .d88888888'      \n" + NOR, me, target);  
	message_vision(HIM + "            8888888888b.     :    :     .d8888888888       \n" + NOR, me, target);
	message_vision(HIM + "            88888P  ``8b." + NOR+HIM + "   `    '   .d8''  `188888       \n" + NOR, me, target);
	message_vision(HIM + "            88888       '8b" + NOR+HIM + "   :  :   d8`       88888       \n" + NOR, me, target);
	message_vision(HIM + "           j88888  .db.   `b" + NOR+HIM + "        d'   .db.  88888k      \n" + NOR, me, target);
	message_vision(HIM + "             `888  8888" + HIY + "╮╭" + HIM + "`b (" + HBMAG+HIC + "蝶" + NOR+HIM + ") d'" + HIY + "╮╭" + HIM + "8888  888'        \n" + NOR, me, target);
	message_vision(HIM + "              888. `88' " + BLINK+HBRED+HIY + "迷" + NOR+HIY + "～～ " + HBMAG+HIC + "⊙" + NOR+HIY + " ～～" + BLINK+HBRED+HIY + "亂" + NOR+HIM + " `88' .888         \n" + NOR, me, target);
	message_vision(HIM + "              8888  `' " + HIY + "╯╰" + HIM + "  ╭" + HBMAG+HIC + "舞" + NOR+HIM + "╮  " + HIY + "╯╰" + HIM + " '`  8888         \n" + NOR, me, target);
	message_vision(HIM + "              8888b.   _,aaY' |" + HBMAG+HIC + "⊙" + NOR+HIM + "| `Yaa,_   .d8888         \n" + NOR, me, target);
	message_vision(HIM + "             j8888888888f''  ╰" + HBMAG+HIC + "天" + NOR+HIM + "╯   ``?888888888k        \n" + NOR, me, target);
	message_vision(HIM + "                88888'.'" + HIY + "╭╯" + HIM + "  d" + HBMAG+HIC + "⊙" + NOR+HIM + "b  " + HIY + "╰╮" + HIM + " `.`8888           \n" + NOR, me, target);
	message_vision(HIM + "                88' .8  " + BLINK+HBRED+HIY + "人" + NOR+HIM + "   d'" + HBMAG+HIC + "地" + NOR+HIM + "`b   " + BLINK+HBRED+HIY + "間" + NOR+HIM + "  8. `88           \n" + NOR, me, target);
	message_vision(HIM + "                l  .88 db" + HIY + "╰" + HIM + " d'|" + HBMAG+HIC + "⊙" + NOR+HIM + "|`b " + HIY + "╯" + HIM + "db 88.  l           \n" + NOR, me, target);
	message_vision(HIM + "                   888 `'   8 |" + HBMAG+HIC + "間" + NOR+HIM + "| 8   `' 88b              \n" + NOR, me, target);
	message_vision(HIM + "                   888      8 |  | 8      888              \n" + NOR, me, target);
	message_vision(HIM + "                  d888b   .d8 ╰╯ 8b.   d888b             \n" + NOR, me, target);
	message_vision(HIM + "                  88888888888      88888888888             \n" + NOR, me, target);
	message_vision(HIM + "                  8888888888        8888888888             \n" + NOR, me, target);
	message_vision(HIM + "                  l 8888888'        `8888888 l             \n" + NOR, me, target);
	message_vision(HIM + "                    `888888          888888'               \n" + NOR, me, target);
	message_vision(HIM + "                     8'  `Y          Y'  `8                \n" + NOR, me, target);
	message_vision(HIM + "                     8                    8                \n" + NOR, me, target);
	message_vision(HIM + "                     l                    l                \n" + NOR, me, target);

       me->improve_skill("mamagic",3*random(ena)+3*me->query_spi());
       me->set_temp("madance", 1);
       me->kill_ob(target);
       target->kill_ob(me);
       target->start_busy(1);      
       call_out("act1",0,msg,target,me);
       return 1;
}

int act1(string msg,object target,object me)
{         
         int mex,eex,cor;
         mex = me->query("combat_exp")/10000;
         eex = target->query("combat_exp")/20000;
         cor = target->query_cor();
         if ( random(mex+me->query_skill("magic")) + per*2 + cor > random(eex) )
         {
          msg = HIC+HBBLU + "$N展現的舞步輕盈盪漾，轉化如蝴蝶般翩然起舞，$n" + HBBLU+HIC + "在迷濛中已被迷惑而茫然!!\n" + NOR ;
         target->apply_condition("cant_perform",random(3));
         target->apply_condition("madanced", random(per/10)+1 );
         target->start_busy(per/10+cor/10);
         target->receive_wound("sen",target->query("max_sen",1)/10+cor);
         target->receive_wound("gin",target->query("max_gin",1)/10+cor);
         target->receive_wound("kee",target->query("max_kee",1)/10+cor*10);     
         call_out("act2",1,msg,target,me);
         me->improve_skill("mamagic",2*random(ena)+2*me->query_spi());
         me->add("atman", -500);    
         }else{
         msg = HBBLU+CYN + "$n" + HBBLU+CYN + "心神一定，並不受$P" + HBBLU+CYN + "的舞步所迷惑!!\n" + NOR;
         me->delete_temp("madance", 1);
         }
         message_vision(msg, me, target);
         return 1;
}

int act2(string msg,object target,object me)
{
     int cor = target->query_cor();
     if(!me->is_fighting(target))     
     {
     me->delete_temp("madance",1);
     return 1;
     }
     message_vision(HBBLU+HIC + "$N的蝶舞展現一股迷惑魅人的魔力，$n" + HBBLU+HIC + "看的如癡如醉完全無法反擊!!\n" + NOR,me,target);
     target->start_busy(1);
     target->receive_wound("kee",random(target->query("max_kee",1)/15)+cor); 
     target->receive_wound("sen",random(target->query("max_sen",1)/15)+cor);
     target->receive_wound("gin",random(target->query("max_gin",1)/15)+cor);
     me->add("atman", -100);
     me->improve_skill("mamagic",2*random(ena)+2*me->query_spi());
     call_out("act3",1,msg,target,me);
     return 1;
}

int act3(string msg,object target,object me)
{
     int cor = target->query_cor();
     if(!me->is_fighting(target))     
     {
     me->delete_temp("madance",1);
     return 1;
     }
     message_vision(HBBLU+HIC + "$N的蝶舞展現一股迷惑魅人的魔力，$n" + HBBLU+HIC + "看的如癡如醉完全無法反擊!!\n" + NOR,me,target);
     target->start_busy(1);
     target->receive_wound("kee",target->query("max_kee",1)/15); 
     target->receive_wound("sen",target->query("max_sen",1)/15);
     target->receive_wound("gin",target->query("max_gin",1)/15);
     me->add("atman", -100);
     me->improve_skill("mamagic",2*random(ena)+2*me->query_spi());
     call_out("act4",1,msg,target,me);
     return 1;
}

int act4(string msg,object target,object me)
{
     int cor = target->query_cor();
     if(!me->is_fighting(target))     
     {
     me->delete_temp("madance",1);
     return 1;
     }
     message_vision(HBBLU+HIC + "$N的蝶舞展現一股迷惑魅人的魔力，$n" + HBBLU+HIC + "看的如癡如醉完全無法反擊!!\n" + NOR,me,target);
     target->start_busy(1);
     target->receive_wound("kee",random(target->query("max_kee",1)/15)+cor); 
     target->receive_wound("sen",random(target->query("max_sen",1)/15)+cor);
     target->receive_wound("gin",random(target->query("max_gin",1)/15)+cor);
     me->add("atman", -100);
     me->improve_skill("mamagic",2*random(ena)+2*me->query_spi());
     call_out("act5",1,msg,target,me);
     return 1;
}

int act5(string msg,object target,object me)
{
     int cor = target->query_cor();
     if(!me->is_fighting(target))     
     {
     me->delete_temp("madance",1);
     return 1;
     }
     message_vision(HBBLU+HIC + "$N的蝶舞展現一股迷惑魅人的魔力，$n" + HBBLU+HIC + "看的如癡如醉完全無法反擊!!\n" + NOR,me,target);
     target->start_busy(1);
     target->receive_wound("kee",target->query("max_kee",1)/15); 
     target->receive_wound("sen",target->query("max_sen",1)/15);
     target->receive_wound("gin",target->query("max_gin",1)/15);
     me->add("atman", -100);
     me->improve_skill("mamagic",2*random(ena)+2*me->query_spi());
     call_out("act6",1,msg,target,me);
     return 1;
}

int act6(string msg,object target,object me)
{
     int cor = target->query_cor();
     if(!me->is_fighting(target))     
     {
     me->delete_temp("madance",1);
     return 1;
     }
     message_vision(HBBLU+HIC + "$N的蝶舞展現一股迷惑魅人的魔力，$n" + HBBLU+HIC + "看的如癡如醉完全無法反擊!!\n" + NOR,me,target);
     target->start_busy(1);
     target->receive_wound("kee",random(target->query("max_kee",1)/15)+cor); 
     target->receive_wound("sen",random(target->query("max_sen",1)/15)+cor);
     target->receive_wound("gin",random(target->query("max_gin",1)/15)+cor);
     me->add("atman", -100);
     me->improve_skill("mamagic",2*random(ena)+2*me->query_spi());
     call_out("act7",1,msg,target,me);
     return 1;
}

int act7(string msg,object target,object me)
{
     int cor = target->query_cor();
     if(!me->is_fighting(target))     
     {
     me->delete_temp("madance",1);
     return 1;
     }
     message_vision(HBBLU+HIC + "$N的蝶舞展現一股迷惑魅人的魔力，$n" + HBBLU+HIC + "看的如癡如醉完全無法反擊!!\n" + NOR,me,target);
     target->start_busy(1);
     target->receive_wound("kee",target->query("max_kee",1)/15); 
     target->receive_wound("sen",target->query("max_sen",1)/15);
     target->receive_wound("gin",target->query("max_gin",1)/15);
     me->add("atman", -100);
     me->improve_skill("mamagic",2*random(ena)+2*me->query_spi());
     call_out("act8",1,msg,target,me);
     return 1;
}

int act8(string msg,object target,object me)
{
     int cor = target->query_cor();
     if(!me->is_fighting(target))     
     {
     me->delete_temp("madance",1);
     return 1;
     }
     message_vision(HBBLU+HIC + "$N的蝶舞展現一股迷惑魅人的魔力，$n" + HBBLU+HIC + "看的如癡如醉完全無法反擊!!\n" + NOR,me,target);
     target->start_busy(1);
     target->receive_wound("kee",random(target->query("max_kee",1)/15)+cor); 
     target->receive_wound("sen",random(target->query("max_sen",1)/15)+cor);
     target->receive_wound("gin",random(target->query("max_gin",1)/15)+cor);
     me->add("atman", -100);
     me->improve_skill("mamagic",3*random(ena)+3*me->query_spi());
     call_out("act9",1,msg,target,me);
     return 1;
}

int act9(string msg,object target,object me)
{
     int cor = target->query_cor();
     if(!me->is_fighting(target))     
     {
     me->delete_temp("madance",1);
     return 1;
     }
     message_vision(HBBLU+HIC + "$N的蝶舞展現一股迷惑魅人的魔力，$n" + HBBLU+HIC + "看的如癡如醉完全無法反擊!!\n" + NOR,me,target);
     target->start_busy(1);
     target->receive_wound("kee",target->query("max_kee",1)/15); 
     target->receive_wound("sen",target->query("max_sen",1)/15);
     target->receive_wound("gin",target->query("max_gin",1)/15);
     me->add("atman", -100);
     me->improve_skill("mamagic",3*random(ena)+3*me->query_spi());
     call_out("act10",1,msg,target,me);
     return 1;
}

int act10(string msg,object target,object me)
{
     int cor = target->query_cor();
     if(!me->is_fighting(target))     
     {
     me->delete_temp("madance",1);
     return 1;
     }
     message_vision(HBRED+HIC + "$n漸漸的從迷濛中脫離了$N的迷惑，心神俱疲的$n" + HBRED+HIC + "如虛脫般的攤倒在地!!\n" + NOR,me,target);
     target->receive_wound("kee",random(target->query("max_kee",1)/15)+cor);
     target->receive_wound("sen",random(target->query("max_sen",1)/15)+cor);
     target->receive_wound("gin",random(target->query("max_gin",1)/15)+cor);
     target->start_busy(2);
     me->add("atman", -100);
     me->improve_skill("mamagic",5*random(ena)+5*me->query_spi());
     me->delete_temp("madance",1);
     return 1;
}
