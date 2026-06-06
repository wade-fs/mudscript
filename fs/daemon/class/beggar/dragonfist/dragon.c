//Beggar Perform sQKx by Guetenr 2003/5/13
//perform Qcall outӧ@S𪺻U
//Qήɶj@XsX18xĪG
inherit F_FUNCTION;
inherit SKILL;
inherit SSERVER;
#include <ansi.h>
#include <combat.h>
#include "/open/open.h" 
int count;


string *ATTACK_MSG=({
BLU + "$N⦨, Z, sQKx --------- \n" + NOR,
RED + "$N⹺K, 𺡦, G, ਭ@DsQKx ---- \n" + NOR,
HIR + "$NΦ, @@DuZ, OsQKx---------- \n" + NOR,
HIG + "$N@Du۴xX, lGݫe, f۹DsQKx -------- \n" + NOR,

});

int again(object me);
int perform(object me,object target)
{
        int i, dam, dam1, j;
        object *all = me->query_enemy();
        object who = this_player();
        count = 0;
        if(me->is_busy()) 
        return notify_fail("A{bLkϥέsQKx!!\n");
        if(!me->is_fighting())
        return notify_fail("sQKxub԰ϥΡC\n");
        if(me->query_temp("dragon_kee"))
        return notify_fail("AwgbIisQKxF, ɬOiHB_!!\n");
        if( me->query("family/family_name") != "")
        return notify_fail("AOγII^_^\n");
        if ((int)me->query("force",1) < 500)
        return notify_fail("AOALkϥΡI\n");

        me->add("force",-500);
        message_vision(HIW + "
                       $NM@E, {!!
                           ߤ,յ{ -- jI " + HIC + "
       .......     -4&&e.                       ....... &&&&c
        .&&&&??&&&e.d&bec.CC..                  .e&&&???&&&eJ^^^&ec " + HIW + "jPul" + HIC + "
        4&&bd ..^?&&&e.&&&&&&&&&&&&&&&&eeed&P?.d&&&E..dbcJC&&&&&&&&P" + HIW + "_$N" + HIC + "
     .  .3&&&.?& ..^^)C$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$PFF^?^?^^ " + HIW + "xoX!!" + HIC + "
   &&F d&&&&&&e   .z&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&P^^.ee z&b e& " + HIW + "ΦhDu" + HIC + "
   ^P  ^&&&&&&&&&&&&&&&&&&&&&&&&&&&P^^^ ^^^^???????^^  &&&&P &&^dF  " + HIW + "   l!!" + HIC + "
e&%.e&&&&&&&&&&&&&&&&&&&&&&&&&&P^^ 4&&&   4&be   ee&P  4&&P^z^ ^    " + HIW + "       w  " + HIC + "
P^e&&&&&&&P^CCC^^^^?&&&&&&&&PF^.er   ^P^   4P^    &&^   &P^         " + HIY + "       u  " + HIC + "
 e&&&?3&F   ?&P    d&b  4ee   &P                                    " + HIY + "         " + HIC + "
4&&&^e&&      ^   ^^    P`        &&e     e.                        " + HIY + "     q  " + HIC + "
&&&F &&&   d&. 4&.         &&=  ......   d&b     .dF   .&F e zr     " + HIY + "  s     " + HIC + "
?&&&.`?f ......J^?  .&&   ^Lz&&&&&&&&&&&&&e..   'd&&% -d&&^ ^...e   " + HIY + "  Q       " + HIC + "
`&&&&  z&&&&&&&&&&&&&&&&&&&&&&&&&&&&7e. ^^^.zd&&eeeeeed&&&&&&&P^    " + HIY + "  K       " + HIC + "
  ?&&&&&&&&&&&&&&&&&&&&&&&&P????????????^^^^^^^^^^^^^^^^^^^^^       " + HIY + "  x       " + HIC + "
    `??&&&&&&&&&&&&&&&&&&P^.eeeeeeee&&&&&&&&^^^^^^^^^               " + HIW + "  x       " + NOR + "

             " + HIW + "rPjPl¥|gbӥh!!!!!!!!\n\n"+NOR+"" + NOR,me,all[i] );
        me->start_busy(1);
        all[i]->start_busy(2);
        call_out("again",3,me);
        return 1;
}

int again(object me)
{
        int i,range,action;
        int fun=me->query("functions/dragon-kee/level",1);
        int n=fun/10+2;
        int j=13-n;
        object *all = me->query_enemy();
        count ++;
        range = me->query("functions/dragon-kee/level")/10;
        if( range > sizeof(ATTACK_MSG) )
        range = sizeof(ATTACK_MSG);
        action = random(range);

        if ((int)me->query("force",1) < 500) 
        {
          me->delete_temp("dragon_kee");
          message_vision(HIR + "\n$NO, Lk~ϥέsQKx!!\n" + NOR,me,all[i] );
          return 1;
        }



        if(count>n || !me->is_fighting())
        {
          me->delete_temp("dragon_kee");
          message_vision(HIR + "\n$NϥέsQKxվ, B, s}l!!" + NOR,me,all[i] );
          return 1;
        }
          me->set_temp("dragon_kee",1);
          message_vision("\n"+ATTACK_MSG[action]+"\n",me);
          for(i=0;i<sizeof(all);i++)
            {
          switch(random(n))
                {
                  case 0:
                  {
                  message_vision("****************************yK   B      z*****************************
                         " + HIR + "lb$nW, $nW!!!\n" + NOR,me,all[i]);

                  me->add("force",-300);
                  all[i]->receive_wound( "kee" ,300);
                  COMBAT_D->report_status( all[i] );
                  if(fun<100) {function_improved("dragon-kee",random(50));}

                  }
                  break;

                  case 1:
                  {
                  message_vision( HIC + "GLk$n!!\n" + NOR , me ,all[i] );                    
                  me->add("force",-300);
                  me->start_busy(1);
                  if(fun<100) {function_improved("dragon-kee",random(50));}
                  }
                  break;
               
                  case 2:
                  {
                  message_vision("****************************y         sz*****************************
                     " + HIR + "lV誽$nU, $nA!!!\n" + NOR,me,all[i]);
                  me->add("force",-500);

                  all[i]->receive_wound( "kee" ,300);
                  all[i]->receive_damage("sen",fun*3+50,me);
                  COMBAT_D->report_status( all[i] );
                  if(fun<100) {function_improved("dragon-kee",random(50));}
                  }
                  break;
                          
                  case 3:
                  {
                  message_vision("****************************y   s      z*****************************
                           " + HIR + "släF⪺OB!!!\n" + NOR,me,all[i]);
                  me->add("force",-300);
                  all[i]->add("force",-1000);
                  COMBAT_D->report_status( all[i] );
                  if(fun<100) {function_improved("dragon-kee",random(50));}
                  }
                  break;

                  case 4:
                  {
                  message_vision("****************************y   s   n    z*****************************
                       " + HIR + "l«, Lkʼu, !!!\n" + NOR,me,all[i]);

                  me->add("force",-700);
                  all[i]->receive_wound( "kee" ,fun*5+500);
                  all[i]->receive_damage("gin",fun*5+random(100),me);
                  COMBAT_D->report_status( all[i] );
                  if(fun<100) {function_improved("dragon-kee",random(50));}
                  }
                  break;
     
                  case 5:               
                  {
                  message_vision("****************************y   D   b   Wz*****************************

                       " + HIR + "l«, ĤHLkʼu, Y!!!\n" + NOR,me,all[i]);
                  me->add("force",-700);
                  all[i]->receive_wound( "kee" ,fun*6+500);
                  all[i]->start_busy(1);
                  COMBAT_D->report_status( all[i] );
                  if(fun<100) {function_improved("dragon-kee",random(50));}
                  }
                  break;

                  case 6:
                  {
                  message_vision("****************************y_         z*****************************
                     " + HIR + "ۮդc, ⹡MW!!!\n" + NOR,me,all[i]);
                  me->add("force",-700);
                  all[i]->add("force",-1000);
                  all[i]->receive_wound( "kee" ,fun*7+500);
                  COMBAT_D->report_status( all[i] );
                  if(fun<100) {function_improved("dragon-kee",random(50));}
                  }
                  break;

                  case 7:     
                  {
                  message_vision("****************************y   p      z*****************************
                           " + HIR + "lƬ, ĤHLkʼu!!!\n" + NOR,me,all[i]);
                  me->add("force",-700);
                  all[i]->add("force",-1000);
                  all[i]->receive_wound( "kee" ,fun*8+500);
                  all[i]->receive_damage("sen",fun*3+50,me);
                  all[i]->start_busy(1);
                  COMBAT_D->report_status( all[i] );
                  if(fun<100) {function_improved("dragon-kee",random(50));}
                  }
                  break;
                
                  case 8:               
                  {
                  message_vision("****************************yQ   A   j   tz*****************************

                 " + HIR + "쭰su𪺥, OM믫F,Lkʼu!!\n" + NOR,me,all[i]);
                  me->add("force",-700);
                  all[i]->add("force",-1000);
                  all[i]->receive_damage("gin",fun*3+500,me);
                  COMBAT_D->report_status( all[i] );
                  if(fun<100) {function_improved("dragon-kee",random(50));}
                  }
                  break;
                  
                  case 9:               
                  {
                  message_vision("****************************y   s      z*****************************
               " + HIR + "ܩsu𪺭, жٵLkʼu!!!\n" + NOR,me,all[i]);

                  me->add("force",-700);
                  all[i]->add("force",-1000);
                  all[i]->receive_damage("gin",fun*3+500,me);
                  all[i]->start_busy(1);
                  COMBAT_D->report_status( all[i] );
                  if(fun<100) {function_improved("dragon-kee",random(50));}
                  }
                  break;
                
                  case 10:
                  {
                  message_vision("****************************y   s   b   z*****************************
               " + HIR + "ۨgp몺l¹!!$nL񪺥!!!\n" + NOR,me,all[i]);
                  me->add("force",-700);
                  all[i]->add("force",-1000);
                  all[i]->start_busy(1);
                  all[i]->receive_wound( "kee" ,fun*3+1000);
                  COMBAT_D->report_status( all[i] );
                  if(fun<100) {function_improved("dragon-kee",random(50));}
                  }
                  break;
                                       
                  case 11:
                  {
                  message_vision("****************************y   s      z*****************************

               gpl$n!!$nL!!!\n",me,all[i]);
                  me->add("force",-700);
                  all[i]->add("force",-3000);
                  all[i]->receive_wound( "kee" ,1000);
                  all[i]->receive_damage("gin",1000,me);
                  all[i]->receive_damage("sen",1000,me);
                  all[i]->start_busy(random(3));
                  me->start_busy(1);
                  COMBAT_D->report_status( all[i] );
                  if(fun<100) {function_improved("dragon-kee",random(20));}
                  }
                  break;
                  
                }
          }            
                call_out("again",j,me);
        return 1;
}
