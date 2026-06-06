/* ק by kalin 91-12-21
1.쥻\ˮ`O   int dam=victim->query("max_kee")/5;gkA
  אּѷmob's kee uѷӦۨšC
2.}񾧴L,]ѷӥfire kingP_,OoIuOW[knowpen\C
*/

#include <combat.h>
#include <ansi.h>
inherit SKILL;

void special_attact1(object me, object victim, object weapon, int damage);
void special_attact2(object me, object victim, object weapon, int damage);
void sp_att1(object me, object victim, object weapon, int damage);
void sp_att2(object me, object victim, object weapon, int damage);
void sp_att3(object me, object victim, object weapon, int damage);
void plan_king1(object me, object victim, object weapon, int damage);
void plan_king2(object me, object victim, object weapon, int damage);
void plan_king3(object me, object victim, object weapon, int damage);
void plan_king4(object me, object victim, object weapon, int damage);
mapping *action = ({
      ([
        "action"     :
"$N⤤$w@½M@" + HIW + "y" + NOR + "涳y" + HIB + "" + HIW + "z" + NOR + "̪$wp@syM$n$lh",
        "dodge"      :               -10,
        "parry"      :               -10,
        "damage"     :                50,
        "force"      :                100,
        "damage_type":  "",
      ]),
      ([
        "action"     :
"$NάyMsCBM⤤$w@" + HIW + "y" + HIG + "CB" + HIC + "" + HIW + "z" + NOR + "$nIh",
        "dodge"      :                0,
        "parry"      :                0,
        "damage"     :                50,
        "force"      :                100,
        "damage_type":  "",
      ]),
      ([
        "action"     :
"$N⤤$wn̡MBkLyMa@" + HIW + "y" + HIW + "" + HIR + "s" + NOR + "ݤ" + HIW + "z" + NOR + "N$wXMsXTU$nIh",
        "dodge"      :                -10,
        "parry"      :                10,
        "damage"     :                100,
        "force"      :                200,
        "damage_type":  "",
      ]),
      ([
        "action"     :
"$NN̪$w|_Ma⤤$wܩۼơM@" + HIW + "y" + HIY + "" + HIM + "ɿ" + HIW + "z" + NOR + "s$nI",
        "dodge"      :                -20,
        "parry"      :                20,
        "damage"     :                100,
        "force"      :                200,
        "damage_type": "",
      ]),
///////////////////////// Below Add By AceLan ////////////////////////////////
      ([
        "action"     :
"$NMnnױתFB, ϥX@" + HIW + "y" + HIR + "Bצ" + HIW + "z" + NOR + ",$n$lh",
        "dodge"      :                -30,
        "parry"      :                30,
        "damage"     :                150,
        "force"      :                250,
        "damage_type": "",
      ]),
      ([
        "action"     :
"$NݷǤF$nӶ, ϥX@" + HIW + "y" + NOR + "" + HIB + "K" + HIR + "" + HIW + "z" + NOR + ", tx٤F@",
        "dodge"      :                -30,
        "parry"      :                20,
        "damage"     :                150,
        "force"      :                250,
		"post_action":  (: plan_king4 :),
        "damage_type": "",
      ]),
      ([
        "action"     :
"$Njܤ@n, Ϋ, ϥX" + HIW + "y" + HIB + "½" + HIR + "" + HIY + "R" + HIG + "S" + HIW + "z" + NOR + ", $wpBI$nx",
        "dodge"      :                -50,
        "parry"      :                40,
        "damage"     :                200,
		"post_action":  (: plan_king1 :),
        "force"      :                300,
        "damage_type": "",
      ]),
      ([
        "action"     :
"$NEO, ɨ_j, oO" + HIW + "y" + HIB + "" + NOR + "" + HIR + "" + HIW + "z" + NOR + ", u$NvѭR",
        "parry"      :                30,
        "dodge"      :                -40,
        "damage"     :                200,
        "force"      :                300,
		"post_action":  (: plan_king2 :),
        "damage_type": "",
      ]),
      ([
        "action"     :
"$NϥX@" + HIW + "y" + HIB + "P" + HIM + "I" + NOR + "" + HIW + "z" + NOR + ", u$N⤤$w֩Cka$nWI",
        "parry"      :                30,
        "dodge"      :                -40,
        "damage"     :                250,
        "force"      :                 300,
		"post_action":  (: plan_king3 :),
        "damage_type": "",
      ]),
           ([        "action":
"$NCCNuBaʥ|PyAww_$wAǳƨϥXе@\n"
"$NuMCCAxOɭܤTA$nuI۬[C",
           "damage":        300,
           "dodge":        -30,
           "parry":         10,
           "post_action":  (: sp_att2 :),
              "damage_type":""
             ]),
           ([         "action":
"$NN$wCAAa⤤ۤƦCAǳƨϥXе@\n"
"$N]Lkxx|CNA$nGIݬ}ۤkC",
           "damage":        300,
           "dodge":        -30,
           "parry":         10,
           "post_action":  (: sp_att3 :),
              "damage_type":"ζ"
            ]),
      ([
        "action"     :
"$NΫ, MD_, ⤤$w½k½, $nWII, IӦ,
o@ۥO" + HIW + "y" + NOR + "" + HIB + "s" + HIG + "j" + HIR + "" + HIW + "z" + NOR,
        "dodge"      :                50,
        "parry"      :                30,
        "damage"     :                250,
        "force"      :                300,
        "damage_type": "",
        "post_action": (: special_attact1 :),
      ]),
      ([
        "action"     :
"$NάMްƤV, ϥX@" + HIW + "y" + HIB + "" + HIR + "}" + HIY + "s" + HIB + "" + HIW + "z" + NOR + ", ⤤$wqŤƵMU,
u@DLΫl, ۨgµ$nEgӦ",
        "dodge"      :                60,
        "parry"      :                40,
        "damage"     :                300,
        "force"      :                300,
        "damage_type": "",
        "post_action": (: special_attact2 :),
      ]),
      ([
        "action"     :
"$NMRAⲴqgXHHAϥXܰk" + HIW + "y" + HIB + "F" + HIR + "s" + HIY + "" + HIB + "" + HIW + "z" + NOR + ",
u@Dl𮵵۸UV~wN$nŢnF",
        "dodge"      :                60,
        "parry"      :                40,
        "damage"     :                300,
        "force"      :                300,
        "damage_type": "",
        "post_action": (: sp_att1 :),
      ]),

});

void special_attact1(object me, object victim, object weapon, int dam)
{
   int i;
   int time=me->query("combat_exp")/1000000;
   dam=this_player()->query_skill("knowpen")*3;
   if(80>random(100))
   {
      if(!this_player()->query("plan-quest/ko-fire-king"))
	  {
      message_vision(HIB + "\n$N⤤" + HIG+ weapon->query("name")+HIY + "q" + HIB + "ssŸ, $n" + HIR + "Fx" + HIB + "@զӤU, \n", me, victim);
      message_vision(
"ϪO" + HIW + "涳yk" + HIB + "̭F, b$nߪC@޹DIWF@UC\n" + NOR, me, victim);
      victim->receive_damage("kee", dam);
      COMBAT_D->report_status(victim, 1);
      }
      else
      {
        for(i=0;i<time;i++)
        {
   	      {
      message_vision(HIB + "\n$N⤤" + HIG+ weapon->query("name")+HIY + "q" + HIB + "ssŸ, $n" + HIR + "Fx" + HIB + "@զӤU, \n", me, victim);
      message_vision(
"ϪO" + HIW + "涳yk" + HIB + "̭F, b$nߪC@޹DIWF@UC\n" + NOR, me, victim);
      victim->receive_damage("kee", dam);
      COMBAT_D->report_status(victim, 1);
           }
        }
	  }
   }
   else
   {
      message_vision(HIB + "\n$N⤤" + HIW+ weapon->query("name")+HIB + "qۯssŸ, $nFxޤ@զӤU, \n" + NOR, me, victim);
      message_vision(HIW + "L$nΧ, ׹LF$NoPR@\n" + NOR, me, victim);
   }
}

void special_attact2(object me, object victim, object weapon, int dam)
{
   dam=this_player()->query_skill("force");
   if(80>random(100))
   {
      message_vision(HIB + "\n$NϥXݮa, yɨgj@, ⤤" + HIW+ weapon->query("name")+HIB + "ۤƥX}}, \n", me, victim);
      message_vision(
"k, C, ꭫a$ngAӨӡC\n" + NOR, me, victim);
      victim->receive_damage("kee", dam);
      COMBAT_D->report_status(victim, 1);
   }
   else
   {
      message_vision(HIB + "\n$NϥXݮa, yɨgj@, ⤤" + HIW+ weapon->query("name")+HIB + "ۤƥX}}, \n", me, victim);
      message_vision(
"k, C, ꭫a$ngAӨӡC\n" + NOR, me, victim);
      message_vision(HIW + "L$nΧ, ׹LF$NoPR@\n" + NOR, me, victim);
   }
}

// valid_learn uOˬdO_iH, b[ skill
int valid_learn(object me)
{
   if ((int)me->query_skill("literate")*2<(int)me->query_skill("knowpen"))
      return notify_fail("AŪѦr{פM⮩䤤DzC\n");
   return 1;
}

void sp_att1(object me, object victim, object weapon, int dam)
{
   if( 80>random(100))
   {
      if( present("ten pen", me))
      {
         dam=this_player()->query_cor()*25;
         message_vision(
"\n" + HIY + "$NfqG" + HIM + "yWyAMHANaAƦ~z" + NOR + "\n"
"" + HIY + "$NB֩ߪkA}VBBkAFsѵyɵoX}}C" + NOR + "\n"
"" + HIY + "u|PŮ𵲦}}HA$nEgӦܡAgF$n@uAy" + NOR + "\n",me,victim);
      }
      else
      {
         dam=this_player()->query_cor()*20;
         message_vision(HIW + "$NHN⤤" + HIG+ weapon->query("name")+HIW + "Au}}$nEgӥX\n" + NOR,me,victim);
      }
       victim->receive_damage("kee", dam);
       COMBAT_D->report_status(victim, 1);
       me->add("force",-100);
   }
}

void sp_att2(object me, object victim, object weapon, int damage)
{
   int i;
   int time=me->query("combat_exp")/500000;
   if(80>random(100))
   {
      message_vision(
"\n\n" + HIW + "$NAwwNuBJGߡAɯuRթAϥXЯ" + NOR + "\n"
"" + HIW + "               y㾧С㷥ۡ" + HIC + "g" + HIW + "" + HIC + "l" + HIW + "" + HIC + "" + HIW + "z" + NOR + "\n"
"" + HIW + "$NuHxӥhAñaʥ|PyV$nA$npuЭ_C" + NOR + "\n\n",me,victim);
   if(!this_player()->query("plan-quest/ko-fire-king"))
   {
      for(i=0;i<time;i++)
      {
         victim->receive_damage("kee", 75);
         COMBAT_D->report_status(victim, 1);
         me->add("force",-30);
      }
   }
   else
   {
	     for(i=0;i<time;i++)
         {
         victim->receive_damage("kee", 100);
         message_vision(HIR + "$NXѸթҳФsAV$noӥXI\n" + NOR,this_player(),victim);
         COMBAT_D->report_status(victim, 1);
         me->add("force",-30);
         }
   }
   }

}
void sp_att3(object me, object victim, object weapon, int damage)
{
           int dam=this_player()->query("bellicosity")/5;
           if( dam > 5000) dam= 500;
           if( dam < 50) dam= 50;
   if(80>random(100))
   {
      int i;
      for(i=1;i<=4;i++)
      {
         message_vision(HIW + "A_⤤ѻCAHNCAI}맮BAQyZϥXCۡI\n" + NOR,me,victim);
         switch(i)
         {
            case 1:
                message_vision(sprintf(HIW + "$NϥXy" + HIC + "Cv㻤" + HIW + "zAHLƵ۰gb$nC\n" + NOR),me,victim);
                break;
            case 2:
                message_vision(sprintf(HIY + "$NϥX" + HIW + "y" + HIC + "Cաx" + HIW + "z" + HIY + "AHLƼCէx$nC\n" + NOR),me,victim);
                break;
            case 3:
                message_vision(sprintf(HIG + "$NϥX" + HIW + "y" + HIC + "Cۡ" + HIW + "z" + HIG + "AHLƼC۱V$nC\n" + NOR),me,victim);
                break;
            case 4:
                message_vision(sprintf(HIC + "$NϥX" + HIW + "y" + HIC + "CW" + HIW + "z" + HIC + "AHWQCW$nC\n" + NOR),me,victim);
                break;
         }
           
           victim->receive_damage("kee",dam);
           COMBAT_D->report_status(victim, 1);
      }
      me->add("force",-100);
   }
}
void plan_king1(object me, object victim, object weapon, int damage)
{
   int heal=this_player()->query("max_force")/20;
   if( heal > 1000) heal= 1000;
   if(this_player()->query("kee")<this_player()->query("max_kee") && this_player()->query("mark/sixgod-plan",1) && this_player()->query("combat_exp")>5000000 && 80>random(100))
   {
      message_vision(HIW + "\n$NB_֩ߪk̤@lA@}շϱqYWUXC\n" + NOR,this_player());
	  this_player()->add("kee",heal);
      this_player()->add("force",-heal);
   }
}
void plan_king2(object me, object victim, object weapon, int damage)
{
   if(this_player()->query("mark/sixgod-plan",1) && this_player()->query("combat_exp")>5000000 && 80>random(100))
   {
      message_vision(HIW + "\n$N_DyҤѮѡzAfXGA$nߨ췥jˮ`I\n\n" + NOR,this_player(),victim);
	  this_player()->add("sen",-50);
	  victim->receive_damage("sen", 100);
      COMBAT_D->report_status(victim, 1);
	  victim->start_busy(1);
   }
}
void plan_king3(object me, object victim, object weapon, int damage)
{
   int heal=this_player()->query("max_force")/30;
   if(this_player()->query("mark/sixgod-plan",1) && this_player()->query("combat_exp")>5000000 && 80>random(100) )
   {
        message_vision(HIY + "
               $NN" + HIW + "_Ѥ" + HIY + "mxWAWlĭõۤZ
           qA$Nwܰj" + HIR + "yBwc ԵLӡz" + HIY + "_V|PlޮlI\n" + NOR,this_player());
      this_player()->add("force",heal);
	  victim->add("force",-heal);
   }
}
void plan_king4(object me, object victim, object weapon, int damage)
{
   damage=this_player()->query("combat_exp")/5000;
   if(this_player()->query("mark/sixgod-plan",1) && this_player()->query("combat_exp")>5000000 && this_player()->query("force")>1000 && 50>random(100) )
   {
   {message_vision("\n\n               " + HIR + "" + BMAG + "==========" + HIW + "y" + HIY + "@XAUI" + HIW + "z" + HIR + "==========\n" + NOR,this_player());}
   {message_vision("         " + HIC + "" + BMAG + "u$N⤤" + HIG+ weapon->query("name")+HIC + "" + BMAG + "ۤƦ@QCAƨgV$nhC\n" + NOR,this_player(),victim);}
   {message_vision("\n
     feeee n:iiiiiiiiiiiiiiiiiiiiiiii
     cdddd n:hhhhhhhhhhhhhhhhhhhhhhhh   

   \n",this_player());}
        {message_vision(HIC + "$NַNϥX涳ykĤ@" + HIW + "y" + NOR + "涳y" + HIB + "" + HIW + "z" + HIC + "ANV$nhI\n" + NOR,this_player(),victim);}
        COMBAT_D->report_status(victim, 1);  
        {message_vision(HIC + "$NַNϥX涳ykĤG" + HIW + "y" + HIG + "CB" + HIC + "" + HIW + "z" + HIC + "ANV$nhI\n" + NOR,this_player(),victim);}
        COMBAT_D->report_status(victim, 1);  
        {message_vision(HIC + "$NַNϥX涳ykĤT" + HIW + "y" + HIW + "" + HIR + "s" + NOR + "ݤ" + HIW + "z" + HIC + "ANV$nhI\n" + NOR,this_player(),victim); }
        COMBAT_D->report_status(victim, 1);  
        {message_vision(HIC + "$NַNϥX涳ykĥ|" + HIW + "y" + HIY + "" + HIM + "ɿ" + HIW + "z" + HIC + "ANV$nhI\n" + NOR,this_player(),victim);}
        COMBAT_D->report_status(victim, 1);  
        {message_vision(HIC + "$NַNϥX涳ykĤ" + HIW + "y" + HIR + "Bצ" + HIW + "z" + HIC + "ANV$nhI\n" + NOR,this_player(),victim);}
        COMBAT_D->report_status(victim, 1);  
        {message_vision(HIC + "$NַNϥX涳ykĤ" + HIW + "y" + NOR + "" + HIB + "K" + HIR + "" + HIW + "z" + HIC + "ANV$nhI\n" + NOR,this_player(),victim);}
        COMBAT_D->report_status(victim, 1);  
        {message_vision(HIC + "$NַNϥX涳ykĤC" + HIW + "y" + HIB + "½" + HIR + "" + HIY + "R" + HIG + "S" + HIW + "z" + HIC + "ANV$nhI\n" + NOR,this_player(),victim);}
        COMBAT_D->report_status(victim, 1);  
        {message_vision(HIC + "$NַNϥX涳ykĤK" + HIW + "y" + HIB + "" + NOR + "" + HIR + "" + HIW + "z" + HIC + "ANV$nhI\n" + NOR,this_player(),victim);}
        COMBAT_D->report_status(victim, 1);  
        {message_vision(HIC + "$NַNϥX涳ykĤE" + HIW + "y" + HIB + "P" + HIM + "I" + NOR + "" + HIW + "z" + HIC + "ANV$nhI\n" + NOR,this_player(),victim);}
        COMBAT_D->report_status(victim, 1);  
        {message_vision(HIC + "$NַNϥX涳ykĤQ" + HIW + "y" + NOR + "" + HIB + "s" + HIG + "j" + HIR + "" + HIW + "z" + HIC + "ANV$nhI\n" + NOR,this_player(),victim);}
        COMBAT_D->report_status(victim, 1);
		{message_vision(HIC + "$NַNϥX涳ykQ@" + HIW + "y" + HIB + "" + HIR + "}" + HIY + "s" + HIB + "" + HIW + "z" + HIC + "ANV$nhI\n" + NOR,this_player(),victim);}
        COMBAT_D->report_status(victim, 1);
		{message_vision(HIC + "$NַNϥX涳ykQG" + HIW + "y" + HIB + "F" + HIR + "s" + HIY + "" + HIB + "" + HIW + "z" + HIC + "ANV$nhI\n" + NOR,this_player(),victim);
      this_player()->add("force",-500);
	  victim->receive_wound("kee",damage);
		}
   }
}





int valid_enable(string usage)
{
   return (usage=="stabber")||(usage=="parry");
}

mapping query_action(object me, object weapon)
{
// skill level < 40 uϥΫe 9 
if( me->query_skill("knowpen",1) < 40)
      return action[ random( sizeof( action)- 4)];
// skill level > 50 ϥΫe 4 ...W[Sϥβv...
   else
      return action[ random( sizeof( action)- 4)+ 4];
}

// oӥuOd߬O_iHm, W[ skill Obo.
int practice_skill(object me)
{
   object weapon;

   me->receive_damage("sen",30);
   if (me->query_skill("literate")*2<me->query_skill("knowpen"))
      return notify_fail("AŪѦrM⮩䤤DzC\n");
   if( !objectp(weapon = me->query_temp("weapon")) ||
      ( string)weapon->query("skill_type")!="stabber")
   {
      return notify_fail("AnAXZ~m涳ykC\n");
   }

   if( ( int)me->query("sen")<30)
      return notify_fail("AMm涳ykC\n");
   return 1;
}

string perform_action_file(string action)
{
   return CLASS_D("scholar")+"/knowpen/"+action;
}
