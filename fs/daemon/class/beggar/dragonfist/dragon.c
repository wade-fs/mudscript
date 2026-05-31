//Beggar Perform ­°Às¤Q¤K´x by Guetenr 2003/5/13
//¥»perform §Q¥Îcall out¨Ó§@¯S§ðªº»²§U
//§Q¥Î®É¶¡¶¡¹j§@¥X³s¥X18´xªº®ÄªG
inherit F_FUNCTION;
inherit SKILL;
inherit SSERVER;
#include <ansi.h>
#include <combat.h>
#include "/open/open.h" 
int count;


string *ATTACK_MSG=({
BLU"$NÂù¤â¦¨«ý, ªZ¾§¨°¿³, ¥¿¬°­°Às¤Q¤K´x¤§ --------- \n"NOR,
RED"$N¤â¹º¤K¨ö, ®ðº¡¦À¥Ð, ²ö¥¡¤G¥Þ, Âà¨­¤@¹D­°Às¤Q¤K´x¤§ ---- \n"NOR,
HIR"$N¨­§Î¦ü­·, ¤@¤â¤@¹D¯uªZ¹º­·, ¥¿¬O­°Às¤Q¤K´x¤¤¤§---------- \n"NOR,
HIG"$N¤@¹D¯u®ð¦Û´x¤¤´å¥X, ®ð«lª½¹G¹ï¤â¯Ý«e, ¤f¤¤³Û¹D­°Às¤Q¤K´x¤¤¤§ -------- \n"NOR,

});

int again(object me);
int perform(object me,object target)
{
        int i, dam, dam1, j;
        object *all = me->query_enemy();
        object who = this_player();
        count = 0;
        if(me->is_busy()) 
        return notify_fail("§A²{¦bµLªk¨Ï¥Î­°Às¤Q¤K´x!!\n");
        if(!me->is_fighting())
        return notify_fail("­°Às¤Q¤K´x¥u¯à¦b¾Ô°«¤¤¨Ï¥Î¡C\n");
        if(me->query_temp("dragon_kee"))
        return notify_fail("§A¤w¸g¦b¬I®i­°Às¤Q¤K´x¤F, ¦¹®É¬O¤£¥i¥H¹B°_ªº!!\n");
        if( me->query("family/family_name") != "¤¢À°")
        return notify_fail("§A¤£¬O¤¢À°¤£¯à¥Î³á¡I¡I^_^\n");
        if ((int)me->query("force",1) < 500)
        return notify_fail("§A¤º¤O¤£°÷¡AµLªk¨Ï¥Î¡I\n");

        me->add("force",-500);
        message_vision(HIW"
                       $N¬ðµM¨­®§¤@»E, ²´¤¤Åã²{ª÷¥ú!!
                           Âù¤â¥ß¤Ñ,¨­¿Õµ{äÕ -- ¤j©I "HIC"
       .......     -4&&e.                       ....... &&&&c
        .&&&&??&&&e.d&bec.CC..                  .e&&&???&&&eJ^^^&ec "HIW"±j¯Pªº¯u®ð«l"HIC"
        4&&bd ..^?&&&e.&&&&&&&&&&&&&&&&eeed&P?.d&&&E..dbcJC&&&&&&&&P"HIW"¤£Â_ªº¦Û$N"HIC"
     .  .3&&&.?& ..^^)C$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$PFF^?^?^^ "HIW"ªº´x¤¤µo¥X!!"HIC"
   &&F d&&&&&&e   .z&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&P^^.ee z&b e& "HIW"§Î¦¨¦h¹D¯u"HIC"
   ^P  ^&&&&&&&&&&&&&&&&&&&&&&&&&&&P^^^ ^^^^???????^^  &&&&P &&^dF  "HIW"   ®ð«l!!"HIC"
e&%.e&&&&&&&&&&&&&&&&&&&&&&&&&&P^^ 4&&&   4&be   ee&P  4&&P^z^ ^    "HIW"       ¡w  "HIC"
P^e&&&&&&&P^CCC^^^^?&&&&&&&&PF^.er   ^P^   4P^    &&^   &P^         "HIY"       ¯u  "HIC"
 e&&&?3&F   ?&P    d&b  4ee   &P                                    "HIY"       ¶ø  "HIC"
4&&&^e&&      ^   ^^    P`        &&e     e.                        "HIY"  ­°   ¸q  "HIC"
&&&F &&&   d&. 4&.         &&=  ......   d&b     .dF   .&F e zr     "HIY"  Às   ¡¯  "HIC"
?&&&.`?f ......J^?  .&&   ^Lz&&&&&&&&&&&&&e..   'd&&% -d&&^ ^...e   "HIY"  ¤Q       "HIC"
`&&&&  z&&&&&&&&&&&&&&&&&&&&&&&&&&&&7e. ^^^.zd&&eeeeeed&&&&&&&P^    "HIY"  ¤K       "HIC"
  ?&&&&&&&&&&&&&&&&&&&&&&&&P????????????^^^^^^^^^^^^^^^^^^^^^       "HIY"  ´x       "HIC"
    `??&&&&&&&&&&&&&&&&&&P^.eeeeeeee&&&&&&&&^^^^^^^^^               "HIW"  ¡x       "NOR"

             "HIW"²r¯Pªº±j¯P®ð«l´Â¥|­±À°¤è¨g©b¦Ó¥h!!!!!!!!\n\n"+NOR+""NOR,me,all[i] );
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
          message_vision(HIR"\n$N¤º¤O¤£¨¬, µLªkÄ~Äò¨Ï¥Î­°Às¤Q¤K´x!!\n"NOR,me,all[i] );
          return 1;
        }



        if(count>n || !me->is_fighting())
        {
          me->delete_temp("dragon_kee");
          message_vision(HIR"\n$N¨Ï¥Î­°Às¤Q¤K´x«á½Õ¾ã®ð®§, «æ¹B¤º®§, ­«·s¶}©l!!"NOR,me,all[i] );
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
                  message_vision("[0;1;33m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1;37m¡[1my[1;36m±[1mK[1m [1m [1m [0m[0;1;34m«[1mB[1m [1m [1m [1;36m¤[1m£[1m [1m [1m [1;34m¶[1m³[1;37m¡[1mz[1;33m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[0m
                         "HIR"®ð«l¥´À»¦b$n¨­¤W, Åý$n­W¤£³ô¨¥!!!\n"NOR,me,all[i]);

                  me->add("force",-300);
                  all[i]->receive_wound( "kee" ,300);
                  COMBAT_D->report_status( all[i] );
                  if(fun<100) {function_improved("dragon-kee",random(50));}

                  }
                  break;

                  case 1:
                  {
                  message_vision( HIC"µ²ªGµLªk¥´¤¤$n!!\n"NOR , me ,all[i] );                    
                  me->add("force",-300);
                  me->start_busy(1);
                  if(fun<100) {function_improved("dragon-kee",random(50));}
                  }
                  break;
               
                  case 2:
                  {
                  message_vision("[0;1;33m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1;37m¡[1my[1;34m®[1mÉ[1m [1m [1m [0m­¼   [0;1m¤[1m»[1m [1m [1m [0mÀs[0;1m¡[1mz[1;33m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[0m
                     "HIR"®ð«l¤À¦V¤»¤èª½½Ä$nªº¸£³U, Åý$n¯«®ðµA´²!!!\n"NOR,me,all[i]);
                  me->add("force",-500);

                  all[i]->receive_wound( "kee" ,300);
                  all[i]->receive_damage("sen",fun*3+50,me);
                  COMBAT_D->report_status( all[i] );
                  if(fun<100) {function_improved("dragon-kee",random(50));}
                  }
                  break;
                          
                  case 3:
                  {
                  message_vision("[0;1;33m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1;37m¡[1my[1mÂ[1mù[1m [1m [1m [1mÀ[1ms[1m [1m [1m [1m¨[1mú[1m [1m [1m [0m[0;1m¤[1mô[1m¡[1mz[1;33m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[0m
                           "HIR"­°Às®ð«l¥´¶Ã¤F¹ï¤âªº¤º¤O¹B¦æ!!!\n"NOR,me,all[i]);
                  me->add("force",-300);
                  all[i]->add("force",-1000);
                  COMBAT_D->report_status( all[i] );
                  if(fun<100) {function_improved("dragon-kee",random(50));}
                  }
                  break;

                  case 4:
                  {
                  message_vision("[0;1;33m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1;37m¡[1my[1;33m¯[1m«[1m [1m [1m [1mÀ[1ms[1m [1m [1m [0m·n   [0;1;33m [0m[0;1;33m§[1mÀ[1;37m¡[1mz[1;33m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[0m
                       "HIR"®ð«l¬¤´é¶ÃÂ«, Åý¹ï¤âµLªk°Ê¼u, ¨­¨ü®ð¶Ë!!!\n"NOR,me,all[i]);

                  me->add("force",-700);
                  all[i]->receive_wound( "kee" ,fun*5+500);
                  all[i]->receive_damage("gin",fun*5+random(100),me);
                  COMBAT_D->report_status( all[i] );
                  if(fun<100) {function_improved("dragon-kee",random(50));}
                  }
                  break;
     
                  case 5:               
                  {
                  message_vision("[0;1;33m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1;37m¡[1my[1;32m©[1mÎ[0m   ÅD[0;1m [1m [1m [1m¦[1mb[0m   ²W[0;1m¡[1mz[1;33m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[0m

                       "HIR"®ð«l¬¤´é¶ÃÂ«, Åý¼Ä¤HµLªk°Ê¼u, ¯«´¼±Y¶Ã!!!\n"NOR,me,all[i]);
                  me->add("force",-700);
                  all[i]->receive_wound( "kee" ,fun*6+500);
                  all[i]->start_busy(1);
                  COMBAT_D->report_status( all[i] );
                  if(fun<100) {function_improved("dragon-kee",random(50));}
                  }
                  break;

                  case 6:
                  {
                  message_vision("[0;1;33m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1;37m¡[1my[1;32m¾[1m_[1m [1m [1m [1mÅ[1må[1m [1m [1m [1m¦[1mÊ[1m [1m [1m [0m[0;1;32m¨[1m½[1;37m¡[1mz[1;33m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[0m
                     "HIR"¦¹©Û®ð¶Õ¤¿´c, Åý¹ï¤â¹¡¨ü¦×Åé©Mºë®ð¤Wªº½ÄÀ»!!!\n"NOR,me,all[i]);
                  me->add("force",-700);
                  all[i]->add("force",-1000);
                  all[i]->receive_wound( "kee" ,fun*7+500);
                  COMBAT_D->report_status( all[i] );
                  if(fun<100) {function_improved("dragon-kee",random(50));}
                  }
                  break;

                  case 7:     
                  {
                  message_vision("[0;1;33m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1;37m¡[1my[1;31m¬[1mð[1m [1m [1m [1m¦[1mp[1m [1m [1m [1m¨[1mä[1m [1m [1m [0m[0;1;31m¨[1mÓ[1;37m¡[1mz[1;33m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[0m
                           "HIR"®ð«l¤Æ¬°¯«Âê, Åý¼Ä¤HµLªk°Ê¼u!!!\n"NOR,me,all[i]);
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
                  message_vision("[0;1;33m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1;37m¡[1my[1m§[1mQ[0m   ¯A[0;1m [1m [1m [1m¤[1mj[0m   ¤t[0;1m¡[1mz[1;33m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[0m

                 "HIR"¹ï¤â¨ü¨ì­°Às¯u®ðªº¥´À», ¤º¤O©Mºë¯«³£¨ü¨ì¤F½ÄÀ»,µLªk°Ê¼u!!\n"NOR,me,all[i]);
                  me->add("force",-700);
                  all[i]->add("force",-1000);
                  all[i]->receive_damage("gin",fun*3+500,me);
                  COMBAT_D->report_status( all[i] );
                  if(fun<100) {function_improved("dragon-kee",random(50));}
                  }
                  break;
                  
                  case 9:               
                  {
                  message_vision("[0;1;33m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1;37m¡[1my[1;33m¼[1mç[1;31m [1m [1m [1mÀ[1ms[1;32m [1m [1m [1m¤[1mÅ[1;36m [1m [1m [0m[0;1;36m¥[1mÎ[1;37m¡[1mz[1;33m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[0m
               "HIR"¹ï¤â¨ü¦Ü©ó­°Às¯u®ðªº­­¨î, ¤£¦ý¨­¨ü³Ð¶ËÁÙµLªk°Ê¼u!!!\n"NOR,me,all[i]);

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
                  message_vision("[0;1;33m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1;37m¡[1my[1;31m¾[1mÔ[0m   Às[0;1m [1m [1m [1m¦[1mb[0m   ³¥[0;1m¡[1mz[1;33m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[0m
               "HIR"¦¹©Û¨g¦p¥¨®ö¯ëªº®ð«l´Â¹ï¤â´é¨Ó!!Åý$n¨­¨üµL¤ñªº¥´À»!!!\n"NOR,me,all[i]);
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
                  message_vision("[0;1;33m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1;37m¡[1my[1;33m¤[1m®[1;37m [1m [1m [1mÀ[1ms[1;33m [1m [1m [1m¦[1m³[1;37m [1m [1m [0m[0;1m®[1m¬[1m¡[1mz[1;33m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[1m*[0m

               [0;1;31m¦[1m¹[1m©[1mÛ[1m¨[1mg[1m¦[1mp[1m¥[1m¨[1m®[1mö[1m¯[1më[1mª[1mº[1m®[1mð[1m«[1ml[1m´[1mÂ[1m$[1mn[1m´[1mé[1m¨[1mÓ[1m![1m![1mÅ[1mý[1m$[1mn[1m¨[1m­[1m¨[1mü[1mµ[1mL[1m¤[1mñ[1mª[1mº[1m¥[1m´[1mÀ[1m»[1m![1m![1m![0m\n",me,all[i]);
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
