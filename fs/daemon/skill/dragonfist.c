#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void attack1(object me, object victim, object weapon, int damage);
void attack2(object me, object victim, object weapon, int damage);
void attack3(object me, object victim, object weapon, int damage);
void again1(object me, object victim, object weapon, int damage);


mapping *action = ({
//0
(["action":"$NLLAkusAkxeFӶA_u"+HIY + "s" + NOR+"vAI@nV~hA
xlV$n$lC",
"dodge":-60,
"parry":50,
"force":60,
"damage":325,
"damage_type" : "",
]),
//1
(["action":"$NA}@ޡA餣DAxpMšA@ۡu"+HIY + "sb" + NOR+"vAxx
$n$ldhC",
"dodge":-60,
"parry":50,
"force":70,
"damage":330,
"damage_type" : "",
]),
//2
(["action":"$NxոUbˡAY}PaAu"+HIY + "sb" + NOR+"vp@gs뼳V$nAդiɡC",
"dodge":-90,
"parry":80,
"force":100,
"damage":335,
"damage_type" : "",
]),
//3
(["action":"$Nk}_AbbxAV$n$lhAu"+HIY + "sť" + NOR+"v۷N馱aA
PɦVع_Ak_A{סC",
"dodge":-90,
"parry":80,
"force":100,
"damage":340,
"damage_type" : "",
]),
//4
(["action":"$Nkx@}Axۤ@AOExAu"+HIY + "QAjt" + NOR+"vդj}jAxlɳzA
V$n_hC",
"dodge":-90,
"parry":80,
"force":100,
"damage":345,
"damage_type" : "",
]),
//5
(["action":"$Nx@AusuH@RAu"+HIY + "E" + NOR+"vxեөAV$nC",
"dodge":-90,
"parry":80,
"force":100,
"damage":350,
"damage_type" : "",
]),
//6
(["action":"$NνwCʡAaxդ@Au"+HIY + "p" + NOR+"vϦpɫBJܡAxlpga
ŧV$nC",
"dodge":-100,
"parry":80,
"force":100,
"damage":355,
"damage_type" : "",
]),
//7
(["action":"$Nxդj}jA餺u_V~gAۦHۯuV$nhAu"+HIY + "_ʨ" + NOR+"vp
zpHC",
"dodge":-100,
"parry":80,
"force":100,
"damage":360,
"damage_type" : "",
]),
//8
(["action":"$Nɧl@fAxeAkxaqxUFXhAjۡu"+HIY + "DbW" + NOR+"v
V$n$lC",
"dodge":-100,
"parry":80,
"force":110,
"damage":365,
"damage_type" : "",
]),
//9
(["action":"$NΦprX]Aۡu"+HIY + "s\\" + NOR+"vIXAHYϤ@AAV$n$lC",
"dodge":-100,
"parry":90,
"force":110,
"damage":370,
"damage_type" : "",
]),
//10
(["action":"$NxݡAۦ\\ӤءA⼻x@XAu"+HIY + "sb" + NOR+"vV$n$lC",
"dodge":-100,
"parry":90,
"force":110,
"damage":375,
"damage_type" : "",
]),
//11
(["action":"$NxPɤ@|AۭI᩹e@AxoA@ۡu"+HIY + "s" + NOR+"vV$nC",
"dodge":-100,
"parry":90,
"force":110,
"damage":380,
"damage_type" : "",
]),
//12
(["action":"$Nxl@PAOzHlAx@aAo$n|yAu"+HIY + "ssL" + NOR+"vxpgBXA
xlƴO$nἺáC",
"dodge":-100,
"parry":90,
"force":110,
"damage":385,
"damage_type" : "",
]),
//13
(["action":"$NΤ_̰ʡAB$nAMAxvPɨgŧӦܡAu"+HIY + "ɭs" + NOR+"vpss
fAV$nC",
"dodge":-100,
"parry":100,
"force":200,
"damage":390,
"damage_type" : "",
]),
//14
(["action":"$NxvuAämA$noϳQ$NcKxvҰhAuۡu"+HIM + "KB" + NOR+"vpjB
ӡA@xS@x¶$nC",
"dodge":-110,
"parry":100,
"force":200,
"damage":395,
"damage_type" : "",
]),
//15
(["action":HIW + "                $NϥXsǵǲĤ@\n"
"             С" + HIG + "uVlЫhЦЧ]v" + HIW + "ס\n"
"          _@AMuzRAlϥxĭ\n"
"            ۷NQ" + HIG + "~l" + HIW + "ҿEoAѸ̦ӥ~_Iŧ$nC\n" + NOR,
"dodge":-110,
"parry":100,
"force":220,
"damage":400,
"damage_type" : "",
"post_action" : (: attack1 :),
]),
//16
(["action":HIW + "                $NϥXsǵǲĤG\n"
"             С" + HIC + "uWiЦBЦܟ\\v" + HIW + "ס\n"
"$NyyRF@fAfB餺~gAN" + HIR + "褧" + HIW + "Ƭ" + HIB + "Xl\n" + HIW + "   yWLANXlBuAkxA\n"
"     ۤƥXD" + HIC + "Bs" + HIW + "AX١A@֤@CV$n$lC\n" + NOR,
"dodge":-120,
"parry":100,
"force":250,
"damage":400,
"damage_type" : "",
"post_action" : (: attack2 :),
]),
//17
(["action":HIW + "                $NϥXsǵǲĤT\n"
"             С" + HIM + "uXЦϡĲÿ[v" + HIW + "ס\n"
"          $NB_~gQ\\OANuBA𬰼C\n"
"sCaxAL" + HIY + "~" + HIW + "p" + YEL + "" + HIY + "p" + BLU + "e" + HIB + "" + HIW + "V$nۤEӥhAxNCNPV$nC\n" + NOR,
"dodge":-150,
"parry":100,
"force":250,
"damage":400,
"damage_type" : "",
"post_action" : (: attack3 :),
]),
//18
(["action":HIW + "$NV½@DAhƤءAO餺" + HIY + "sl" + HIW + "AlpɴAoʥ|yA_X}}շϡC\n"
"շ·¶AۤƥXpu" + HIC + "sήl" + HIW + "A|PyۤEA_$n߯áC\n"
"u$NƵMqߡAƥRA䨭᪺" + HIB + "sήl" + HIW + "AopbbAsbѤ¡C\n\n" + NOR + "       K$N" + HIY + "" + NOR + "ɲ{A餺sl}ӥXAϥXs̲׶qC\n" + NOR + HIW + "            w" + HIR + "Y s  S  E   Z" + HIW + "עw" + NOR,
"dodge":-100,
"parry":100,
"force":150,
"damage":400,
"post_action":  (: again1 :),
"damage_type" : "",
]),

});


mapping query_action(object me, object *weapon)
{
   int skill;

   skill=me->query_skill("dragonfist", 1);

   if( me->query("family/family_name")!="" || !me->query("read_page_1",1)
       || !me->query("read_page_2",1) || !me->query("read_page_3",1)
       || !me->query("read_dragonfist",1) )
   {
    if( skill < 50)
       return action[random(7)];
    else if( skill < 60)
       return action[random(10)];
    else if( skill < 70)
       return action[random(12)];
    else if( skill < 80)
       return action[random(14)];
    else
       return action[random(15)];
   } else {if (random(100) > 80 )
       return action[random(10)+9];
    else 
       return action[random(9)+9];
   }
}
void attack1(object me, object victim, object weapon, int damage)
{
 int att_value,skill;
 skill=me->query_skill("dragonfist", 1);
 att_value = random(2*skill);
 if((me->query_skill_mapped("force")=="dragonforce")&&(me->query("force_factor") >= 1 ))
  {
   message_vision(HIG + "$Nxĭt~lpFpeV$nbӥhA$nwפU~lwӹLA_ˤF$n߯\n" + NOR,me,victim);
   victim->add("force",-att_value);
   COMBAT_D->report_status(victim, 1);
   victim->apply_condition("hart",random(15));
  }
}
void attack2(object me, object victim, object weapon, int damage)
{
 int busy_value,skill;
 skill=me->query_skill("dragonfist", 1);
 busy_value = skill / 50;
 if((me->query_skill_mapped("force")=="dragonforce")&&(me->query("force_factor") >= 1 ))
  {
   message_vision(HIC + "DXNl«J$N餺A_Hk$N@ɵLkʡC\n" + NOR,victim);
   victim->start_busy( random(busy_value) );
   COMBAT_D->report_status(victim, 1);
   victim->apply_condition("cold",random(15));
  }
}


void attack3(object me, object victim, object weapon, int damage)
{
 int att_value,skill;
 skill=me->query_skill("dragonfist",1);
 att_value=random(2*skill);
 if((me->query_skill_mapped("force")=="dragonforce")&&(me->query("force_factor") >= 1 ))
 {
  message_vision(HIM + "$NCܤ@nANxCgV$nALƼCEgӥhA$n׵LiסAGDCC\n" + NOR,me,victim);
  victim->add("kee",-att_value);
  COMBAT_D->report_status(victim,1);
  victim->apply_condition("swordkee",random(15));
 }
}

void again1(object me, object victim, object weapon, int damage)
{
 int skilv,maxlv,i,j,mydamage;
 skilv=random(me->query_skill("dragonfist",1));
 maxlv=me->query_skill("dragonfist",1);
 j=skilv/10;
 if(j>9) {j=9;}
 for(i=0;i<=j;i++)
 {
  switch(i)
  {
  case 0:
  message_vision("$NLLAkusAkxeFӶA_u"+HIY + "s" + NOR+"vAI@nV~hAxlV$nC\n",me,victim);
  break;
  case 1:
  message_vision("$NA}@ޡA餣DAxpMšA@ۡu"+HIY + "sb" + NOR+"vAxx$n|ϰťhC\n",me,victim);
  break;
  case 2:
  message_vision("$NxոUbˡAY}PaAu"+HIY + "sb" + NOR+"vp@gs뼳V$nAդiɡC\n",me,victim);
  break;
  case 3:
  message_vision("$Nk}_AbbxAV$nhAu"+HIY + "sť" + NOR+"v۷N馱aAPɦVع_Ak_A{סC\n",me,victim);
  break;
  case 4:
  message_vision("$NΦprX]Aۡu"+HIY + "s\\" + NOR+"vIXAHYϤ@AAV$nC\n",me,victim);
  break;
  case 5:
  message_vision("$NxݡAۦ\\ӤءA⼻x@XAu"+HIY + "sb" + NOR+"vV$nC\n",me,victim);
  break;
  case 6:
  message_vision("$NxPɤ@|AۭI᩹e@AxoA@ۡu"+HIY + "s" + NOR+"vV$nC\n",me,victim);                                             break;
  case 7:
  message_vision("$Nxl@PAOzHlAx@aAo$n|yAu"+HIY + "ssL" + NOR+"vxpgBXAxlƴO$nἺáC\n",me,victim);
  break;
  case 8:
  message_vision("$NΤ_̰ʡAB$nAMAxvPɨgŧӦܡAu"+HIY + "ɭs" + NOR+"vpssfAV$nC\n",me,victim);
  break;
  }
   if( ((int)victim->query_skill("move",1)
        + random((int)victim->query_skill("dodge",1))*5)
        < skilv+random((int)me->query_skill("dodge",1)*i
        + (int)victim->query_skill("move",1)) )
    {
     message_vision(HIC + "$NlOA$n@ɩ۬[AQ$N@xFAuzIv@nRX@fAII\n" + NOR,me,victim);
     victim->receive_damage("kee",(skilv*i/10));
     COMBAT_D->report_status(victim,1);
     me->add("force",-(skilv*maxlv/100));
     mydamage = mydamage+(skilv*i)/10;
   } else
   {
    message_vision(HIW + "$nbxv]򤧤UAݥX$N}A{kLF$NF\n" + NOR,me,victim);
     me->add("force",-skilv*maxlv/100);
     mydamage = mydamage+(skilv*i)/10;
   }
 }
 if(i>=9)
 {
  message_vision(HIR + "$NϥXsSEѫ᤺OӷlLA𮧤jáAIlI|ϻĵh`AoBծC\n" + NOR,me);
        me->start_busy((skilv+maxlv)/50);
        COMBAT_D->report_status(victim,1);
 } else {
 message_vision(HIR + "$NX"+chinese_number(i)+"xAu@AOLH~AϳQslҶˡARX@fAI\n" + NOR,me);
 me->start_busy((skilv+maxlv)/100);
 me->receive_damage("kee",mydamage);
 COMBAT_D->report_status(victim,1);
 }
}

int practice_skill(object me)
{
  if ((int) me->query("max_force")<1000)
  return notify_fail("AZǪѤALkѳzsǪ맮B\n");
}

string perform_action_file(string action)
{
          return CLASS_D("beggar")+"/dragonfist/"+action;
}
int valid_learn(object me)
    {
        if( me->query("max_force") < 1500 ) {
            tell_object(me, "AO׬, ̤֭n@dIC\n");
            return 0;
        }
        if(!(me->query("class") == "beggar")) {
            tell_object(me, "ṳl~ǭsǡC\n");
            return 0;
        }
        if(!(me->query("beggar/quests 10") == 1 )) {
            tell_object(me, "̤lnȤQ~ǡC\n");
            return 0;
        }
        if( me->query_str() < 20) {
            tell_object(me, "AuOǭsǡC\n");
            return 0;
        }
        if( me->query("force") < 500 ) {
            tell_object(me, "AثeO줭I, LkmǡC\n");
            return 0;
        }
        if( (me->query("potential") - me->query("learned_points")) < 3 ) {
            tell_object(me, "AणTI, LkmǡC\n");
            return 0;
        }
       if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
       return   notify_fail("ǭsQKxŤC\n");

        tell_object(me, "ǦǻݦTIC\n");
        me->add("potential", -3);
        return 1;
}
int valid_enable(string usage)
{        return ( usage=="unarmed" )||(usage=="parry");
}


