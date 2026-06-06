#include <combat.h>
#include <ansi.h>
inherit SKILL;


void sp2(object me, object victim, object  weapon, int damage);
void sp4(object me,object victim,object weapon,int damage);

mapping *action= ({
 (["action":"$NϥX C  W Q     } 

               l  A   A   z

             $N|_$w,$nUj޹Dh,\nO$n``QAҶ",
    "dodge":-10,
    "parry":20,
    "damage":90,
    "force":45,
    "damage_type":""
  ]),
 (["action":"$Nf@RuAϥ C  W Q    g 

             N$wݶରΡAKAV$n𥴹Lh.",
    "dodge":40,
    "parry":50,
    "damage":100,
    "force":50,
    "damage_type":""
  ]),
  (["action":"$NM⮩"+HIC + "CWQ" + NOR + "

                 ĤT" + HIB + "GFc G" + NOR+"

              qܤƥXUةۤۡAɸީ_,ʦVLwAiN,V$nܫܪFLh",
    "dodge":10,
    "parry":10,
    "damage":155,
    "force":80,
    "damage_type":""
  ]),
  (["action":"$NMCk@i,ϥX"+HIC + "CWQ" + NOR + "

                  ĥ|" + BLU + "GQ G" + NOR+"

               lMt˪Ŧӭ,⤤Hۨ骺pgjB,V$n$1bӥh....",
    "dodge":30,
    "parry":20,
    "damage":145,
    "force":70,
    "damage_type":HIB + "}" + NOR + "",
  ]),
  (["action":"$NϥX"+HIC + "CWQ" + NOR + "

                 Ĥ" + HIR + "Gs G" + NOR+"

              $NM@G,GHPɮ$wVeAPɯe$n|AXۨeL",
    "dodge":45,
    "parry":45,
    "damage":105,
    "force":100,
    "damage_type":""
  ]),
  (["action":"$Njs"+HIC + "CWQ" + NOR + "

                " + HIW + "Gs G" + NOR+"

              ⮩䤤,ߨNֳtr,pyPөh$n$1VWFӪܻT....",
    "dodge":45,
    "parry":45,
    "damage":170,
    "force":100,
    "damage_type":""
  ]),
  (["action":"$Njngz,ϥX"+HIC + "CWQ" + NOR + "ĤC" + HIM + "GI G" + NOR+",$NpPb,ɧUpPbO,۩$nn`,Ϫ$1ˤ....",
    "dodge":45,
    "parry":55,
    "damage":165,
    "force":100,
    "damage_type":""
  ]),
  (["action":"$Np@몺b],ϥX"+HIC + "CWQ" + NOR + "

                ĤK" + WHT + "G^ G" + NOR+"

              N$wi}AƮAuť$n$1Xڡ@njs!~~~~",
    "dodge":-45,
    "parry":55,
    "damage":130,
    "force":90,
    "damage_type":""
  ]),
  (["action":"$Njܤ@n

               "+HIR + "G~~^~~~ G" + NOR + "

               " + HIC + "RFCk" + NOR+"ĤE,$NEѦaEM,ѦaߧYί몺Eb$w,V$n$1rӥh",
    "dodge":35,
    "parry":-55,
    "damage":160,
    "force":80,
    "damage_type":""
   ]),
   (["action":"$NϥX"+HIC + "CWQ" + NOR + "

                 ĤQ" + HBYEL + "G-U---v- G" + NOR+"

               $NM@RA$wƧ@@DխipCs몺AV$n$1ĹLh....",
    "dodge":45,
    "parry":55,
    "damage":195,
    "force":180,
    "damage_type":""
   ]),
   (["action":"$N`PUѦ,ϥX"+HIC + "CWQ" + NOR + "

               " + HIB + "GdhW G" + NOR+"

               bdˤUW[WOq,@ģ,$nn`....",
    "dodge":55,
    "parry":65,
    "damage":255,
    "force":110,
    "damage_type":""
    ]),

});


void sp4(object me,object victim,object weapon,int damage)
{
   int i = me->query("unarmed")*10 + me->query_skill("seven-unarmed");
   if (me->query_skill_mapped("force") == "seven-unarmed" && random(400) < 10 )
   {       message_vision(HIW + "$NB_IѡA$nuɤJ$NC\n" + NOR,me,victim);
    victim->receive_damage("kee",random(i));
    me->add("kee",random(i));
   }
}
int valid_enable(string usage)
{
        return (usage=="unarmed"||usage=="parry");
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 100 ) return 0;

        if( random(damage_bonus/2) > victim->query_str() ) {
                victim->receive_wound("kee", (damage_bonus - 100) / 3 );
                switch(random(3)) {
                        case 0: return "Aťuذաv@nTMOHnT\n";
                        case 1: return "$NlO@RM$n$loXuءva@nzTT\n";
                        case 2: return "uť$n$luءva@n ...\n";
                }
        }
}

