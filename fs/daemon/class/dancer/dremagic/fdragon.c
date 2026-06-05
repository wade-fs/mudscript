#include <ansi.h>
inherit F_SPELL;
inherit SSERVER;
int fun;
int skl;
int fk;
string msg;
object victim,*enemy;
object me;
int i;
int conjure(object me, object target)
{       
        me=this_player();  
        enemy = me->query_enemy();
        i=sizeof(enemy);
        victim = offensive_target(me);
        if(!victim) return notify_fail("你找不到敵人!!\n");
        fun=me->query("spells/fdragon/level");
        skl = (int)(me->query_skill("dremagic", 1));
        fk=(fun+skl);

        if (!me->query("spells/fdragon/level"))
        return 0;

        if( !target ) target = offensive_target(me);
        if(!me->is_fighting(target) )
        return notify_fail("這法術只能對戰鬥中的對手使用。\n");

        if(me->query("family/family_name")!="夜夢小築")
        return notify_fail("只有舞者才能使用。\n");

        if(me->query("combat_exp") < 1500000)
        return notify_fail("實戰經驗不足是施展不出來的!!\n");

        if(me->query("allow_fdragon")!=1)
        return notify_fail("偷學的不能使用喔\n");
        
        if((int)me->query("atman") < 500)
        return notify_fail("你的法力不夠﹗\n");

        if(me->query_temp("fdragon")==1)
        return notify_fail("你正在施法中\n");

        if((int)me->query("gin") < 20 )
        return notify_fail("你的精神沒有辦法有效集中﹗\n");

        me->add("atman", -(250+fk*3));
        me->receive_damage("gin", 10);

message_vision(HIC + "$N雙手高舉大喊藏身於黑暗大地的龍啊,請聽我的呼喚\n" + NOR,me,victim);
message_vision(HIC + "現身來幫助我吧......" + HIR + " 炎 " + HIW + " 之 " + HIG + " 龍 \n" + NOR,me,victim);

message_vision(HIW + "只見遙遠的地平線彼端...一條全身火紅的飛龍迅速的往這裡接近\n" + NOR,me,victim);

message_vision(HIR + "                                        &.  &.     .\n" + NOR,me,victim);
message_vision(HIR + "                                        ~ss.&ss. .s'\n" + NOR,me,victim);
message_vision(HIR + "                                .     .ss&&&&&&&&&&s.\n" + NOR,me,victim);
message_vision(HIR + "                                &. s&&&&&&&&&&&&&&`&&Ss\n" + NOR,me,victim);
message_vision(HIR + "                                ~&&&&&&&&&&&&&&&&&&o&&&       .\n" + NOR,me,victim);
message_vision(HIR + "                               s&&&&&&&&&&&&&&&&&&&&&&&&s.  .s\n" + NOR,me,victim);
message_vision(HIR + "                              s&&&&&&&&&~&&&&&&~~~~&&&&&&~&&&&&.\n" + NOR,me,victim);
message_vision(HIR + "                              s&&&&&&&&&&s~~&&&&ssssss~&&&&&&&&~\n" + NOR,me,victim);
message_vision(HIR + "                             s&&&&&&&&&&'         `~~~ss~&~&s~~\n" + NOR,me,victim);
message_vision(HIR + "                             s&&&&&&&&&&.              `~~~~~&  .s&&s\n" + NOR,me,victim);
message_vision(HIR + "                             s&&&&&&&&&&&&s....               `s&&'  `\n" + NOR,me,victim);
message_vision(HIR + "                         `ssss&&&&&&&&&&&&&&&&&&&&####s.     .&&~&.   . s-\n" + NOR,me,victim);
message_vision(HIR + "                           `~~~~&&&&&&&&&&&&&&&&&&&&#####&&&&&&~     &.&'\n" + NOR,me,victim);
message_vision(HIR + "                                 ~&&&&&&&&&&&&&&&&&&&&&####s~~     .&&&|\n" + NOR,me,victim);
message_vision(HIR + "                                  ~&&&&&&&&&&&&&&&&&&&&&&&&##s    .&&~ &\n" + NOR,me,victim);
message_vision(HIR + "                                   &&~~&&&&&&&&&&&&&&&&&&&&&&&&&&&&&~   `\n" + NOR,me,victim);
message_vision(HIR + "                                  &&~  ~&~&&&&&&&&&&&&&&&&&&&&S~~~~'\n" + NOR,me,victim);
message_vision(HIR + "                             .   .~     '  &&&&&&&&&&&&&&&&####s\n" + NOR,me,victim);
message_vision(HIR + "                             &.          .s&&&&&&&&&&&&&&&&&####~\n" + NOR,me,victim);
message_vision(HIR + "                 .           ~&s.   ..ssS&&&&&&&&&&&&&&&&&&&####~\n" + NOR,me,victim);
message_vision(HIR + "                 &           .&&&S&&&&&&&&&&&&&&&&&&&&&&&&#####~\n" + NOR,me,victim);
message_vision(HIR + "                 Ss     ..sS&&&&&&&&&&&&&&&&&&&&&&&&&&&######~~\n" + NOR,me,victim);
message_vision(HIR + "                  ~&&sS&&&&&&&&&&&&&&&&&&&&&&&&&&&########~\n" + NOR,me,victim);
message_vision(HIR + "           .      s&&&&&&&&&&&&&&&&&&&&&&&&#########~~'\n" + NOR,me,victim);
message_vision(HIR + "           &    s&&&&&&&&&&&&&&&&&&&&&#######~~'      s'         .\n" + NOR,me,victim);
message_vision(HIR + "           &&..&&&&&&&&&&&&&&&&&&######~'       .....&&....    .&\n" + NOR,me,victim);
message_vision(HIR + "            ~&&&&&&&&&&&&&&&######~' .     .sS&&&&&&&&&&&&&&&&s&&\n" + NOR,me,victim);
message_vision(HIR + "              &&&&&&&&&&&&#####~     &. .s&&&&&&&&&&&&&&&&&&&&&&&&s.\n" + NOR,me,victim);
message_vision(HIR + "   )          &&&&&&&&&&&#####'      `&&&&&&&&&###########&&&&&&&&&&&.\n" + NOR,me,victim);
message_vision(HIR + "  ((          &&&&&&&&&&&#####       &&&&&&&&###~       ~####&&&&&&&&&&\n" + NOR,me,victim);
message_vision(HIR + "  ) \\         &&&&&&&&&&&&####.     &&&&&&###~             ~###&&&&&&&&&   s'\n" + NOR,me,victim);
message_vision(HIR + " (   )        &&&&&&&&&&&&&####.   &&&&&###~                ####&&&&&&&&s&&'\n" + NOR,me,victim);
message_vision(HIR + " )  ( (       &&~&&&&&&&&&&&#####.&&&&&###'                .###&&&&&&&&&&~\n" + NOR,me,victim);
message_vision(HIR + " (  )  )   _.&~   &&&&&&&&&&&&######.&&##'                .###&&&&&&&&&&\n" + NOR,me,victim);
message_vision(HIR + " ) (  ( \\.         ~&&&&&&&&&&&&&#######....          ..####&&&&&&&&&&&~\n" + NOR,me,victim);
message_vision(HIR + "(   )& )  )        .&&&&&&&&&&&&&&&&&&####################&&&&&&&&&&&~\n" + NOR,me,victim);
message_vision(HIR + "(   (&&  ( \\     _sS~  `~&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&S&&.\n" + NOR,me,victim);
message_vision(HIR + " )  )&&&s ) )  .      .   `&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&~'  `&&\n" + NOR,me,victim);
message_vision(HIR + "  (   &&&Ss/  .&.    .&..s&&&&&&##S&&&&&&&&&&&&&&&&&&&&&&&&S~~        '\n" + NOR,me,victim);
message_vision(HIR + "    \\)_&&&&&&&&&&&&&&&&&&&&&&&##~  &&        `&&.        `&&.\n" + NOR,me,victim);
message_vision(HIR + "        `~S&&&&&&&&&&&&&&&&&#~      &          `&          `&\n" + NOR,me,victim);
message_vision(HIR + "            `~~~~~~~~~~~~~'         '           '           '\n\n\n" + NOR,me,victim);

        
                me->set_temp("fdragon",1);
                enemy = all_inventory( environment(me) );
   for( i=0; i<sizeof(enemy); i++ )
   {
        if( enemy[i]->is_character() && !enemy[i]->is_corpse() && living(enemy[i]) &&
            !enemy[i]->query("no_kill") && enemy[i]!=me &&
            !in_edit(enemy[i]) && !in_input(enemy[i]) && !enemy[i]->query_temp("netdead") &&
            !wizardp(enemy[i]))
        {     
           if(random(100)>20)
        {
            msg = HIR + "火龍迅速的將"+enemy[i]->query("name")+"給吞噬,對"+enemy[i]->query("name")+"形成莫大的傷害！\n" + NOR;
            enemy[i]->receive_damage("kee", fk*5+random(500),me);
                        COMBAT_D->report_status(enemy[i]);
        } else {
                msg = HIW + ""+enemy[i]->query("name")+"以極快的速度避開了火龍的攻擊。\n" + NOR;
        }
                
        message_vision(msg, me, target);
        
                }

        
                }
                if(fun<100) spell_improved("fdragon",random(500));
               call_out("can_use",3,me);
       return 1;
}               
                
int can_use(object me)
{
  if(!me)
    me=this_player();
  if(me) 
  {
    me->delete_temp("fdragon");
    message_vision(HIR + "火龍似乎受到$N的感招，再度浮遊於天際，等候$N的差遣!!\n" + NOR,me);
  }
  return 1;
}

