#include <combat.h>
#include <ansi.h>
inherit SKILL;


void sp2(object me, object victim, object  weapon, int damage);
void sp4(object me,object victim,object weapon,int damage);

mapping *action= ({
 (["action":"$N¨Ï¥X [0;1;36;45m¤[1mC[1m [1m®[1mü[1m [1m¿[1mW[1m [1mÅ[1mQ[1m [1m®[1m±[0m  [0;1;33m¯[1m«[1m [1m÷[1m´[1m [1m¯[1m}[1m [1m®[1mö[0m

              [0;1;32m®[1m±[1m [1m«[1ml[1m [1m«[1mæ[1m [1m±[1m²[0m¡A[0;1;31m¥[1mû[1m [1m®[1m«[1m [1m®[1m±[1m [1m¶[1mÕ[0m¡A[0;1;35m°[1m­[1m [1m­[1mú[1m [1m¯[1m«[1m [1mÀ[1mz[0m

             $NÁ|°_$w,©¹$nªº¦U¤j¥Þ¹D§ð¥h,\n¥O$n²`²`ªº³Q§A©Ò¶Ë",
    "dodge":-10,
    "parry":20,
    "damage":90,
    "force":45,
    "damage_type":"·ï¶Ë"
  ]),
 (["action":"$N¤f¤¤¤@¦R¯u®ð¡A¨Ï¥Î [0;1;36;45m¤[1mC[1m [1m®[1mü[1m [1m¿[1mW[1m [1mÅ[1mQ[1m [1m®[1m±[0m [0;1;33m«[1mã[1m [1m®[1mü[1m [1m¨[1mg[1m [1mÀ[1mÜ[0m

             ±N$w®±ºÝ¶êÂà¬°§Î¡Aºø±K¨£ªø¡A¦V$n§ð¥´¹L¥h.",
    "dodge":40,
    "parry":50,
    "damage":100,
    "force":50,
    "damage_type":"·ï¶Ë"
  ]),
  (["action":"$N©¿µM»â®©"+HIC"¤C®ü¿WÅQ®±"NOR"

                 ²Ä¤T¦¡"HIB"¢G¤ÑÅF´c®ö ¢G"NOR+"

              ±q¤ªÃú¤¤ÅÜ¤Æ¥X¦UºØ©î©Û¤§®±©Û¡A·¥ºÉ¸Þ©_¤§¯à¨Æ,°Ê¦VµL©w¡A¤£¥i®»ºN,¦V$n«Ü«Üªº¨ë¤F¹L¥h",
    "dodge":10,
    "parry":10,
    "damage":155,
    "force":80,
    "damage_type":"·ï¶Ë"
  ]),
  (["action":"$N¬ðµM¼Cªk¤@®i,¨Ï¥X"+HIC"¤C®ü¿WÅQ®±"NOR"

                  ²Ä¥|¦¡"BLU"¢GÅQ®ü´­«Â ¢G"NOR+"

               ¨­¤l¬ðµM¨³³tÄËªÅ¦Ó­¸,¤â¤¤ªº®±®ðÀHµÛ¨­Åéªº±ÛÂà¦p¨g­·¤j«B,¦V$n$1­¸©b¦Ó¥h....",
    "dodge":30,
    "parry":20,
    "damage":145,
    "force":70,
    "damage_type":HIB"¯}Åé"NOR"¤§¶Ë",
  ]),
  (["action":"$N¨Ï¥X"+HIC"¤C®ü¿WÅQ®±"NOR"

                 ²Ä¤­¦¡"HIR"¢G¦å®ü¼çÀs ¢G"NOR+"

              $N©¿µM¤@¤À¬°¤G,¤G¤H¦P®É®¼$w«æ¨ë¦V«e¡A¦P®É¯e¨ë$n«|³ï¡A¥X©Û¨³¯eµL¤ñ",
    "dodge":45,
    "parry":45,
    "damage":105,
    "force":100,
    "damage_type":"·ï¶Ë"
  ]),
  (["action":"$N¤j¥s"+HIC"¤C®ü¿WÅQ®±"NOR"¤§

                "HIW"¢G·¥®üÀs±² ¢G"NOR+"

              Àþ¶¡»â®©¨ä¤¤¤§ºëÅè,¥ß¨è±N®±§Ö³t²rÀ»,®±¦p¬y¬Pªº©¿¨Ó©¿¥h$n$1ªºÀV¤W¹º¤F­ÓªÜ»T....",
    "dodge":45,
    "parry":45,
    "damage":170,
    "force":100,
    "damage_type":"·ï¶Ë"
  ]),
  (["action":"$N¤jÁn¨gÀz,¨Ï¥X"+HIC"¤C®ü¿WÅQ®±"NOR"²Ä¤C¦¡"HIM"¢G¤õ®üµI¤Ñ ¢G"NOR+",$N¨­¦p¥PÅbªº­¸µ¾,­É§U¦p¥PÅbªº¯«¤O,©Û©ÛÀ»¤¤$n­n®`,¨Ïªº$1¨ü¶Ë¤£»´....",
    "dodge":45,
    "parry":55,
    "damage":165,
    "force":100,
    "damage_type":"·ï¶Ë"
  ]),
  (["action":"$N¦³¦p¤@°¦³¥°¨¯ëªº©b¶],¨Ï¥X"+HIC"¤C®ü¿WÅQ®±"NOR"

                ²Ä¤K¦¡"WHT"¢G¥ÛÃö¦^°¨ ¢G"NOR+"

              ¨â¤â±N$w®i¶}¡A¨ê¨ê¼Æ®±¡A¥uÅ¥$n$1´X¡§°Ú¡¨ªº¤@Án¤j¥s!~~~~",
    "dodge":-45,
    "parry":55,
    "damage":130,
    "force":90,
    "damage_type":"·ï¶Ë"
  ]),
  (["action":"$N¤j³Ü¤@Án

               "+HIR"¢G~¶­~¦^~¯¬~¿Ä~ ¢G"NOR"

               ¤§"HIC"¨RÆF¼Cªk"NOR+"²Ä¤E¦¡,$N»E¶°¤Ñ¦a¶¡ªº¯EµM¥¿®ð,¤Ñ¦a¥¿®ð¥ß§Y¦¨»ñ§Î¯ëªº»E¶°¦b$w¤¤,¦V$n$1²r§ð¦Ó¥h",
    "dodge":35,
    "parry":-55,
    "damage":160,
    "force":80,
    "damage_type":"·ï¶Ë"
   ]),
   (["action":"$N¨Ï¥X"+HIC"¤C®ü¿WÅQ®±"NOR"

                 ²Ä¤Q¦¡"HBYEL"¢G-¸U-©¨-´Â-©v- ¢G"NOR+"

               $N¬ðµM¶¡®±®ð¤@¦R¡A$w¤Æ§@¤@¹D¥Õ­i¦p«CÀs¯ëªº¡A¦V$n$1ª½½Ä¹L¥h....",
    "dodge":45,
    "parry":55,
    "damage":195,
    "force":180,
    "damage_type":"·ï¶Ë"
   ]),
   (["action":"$N²`·P¸U©À­Ñ¦Ç,¨Ï¥X"+HIC"¤C®ü¿WÅQ®±"NOR"¤¤ªº

               "HIB"¢G´dµh²ö¦W ¢G"NOR+"

               ¦b´d¶Ë¤U¼W¥[²ö¦Wªº¤O¶q,¨­Åé¤@Ä£,®±®±¥´¤¤$nªº­n®`....",
    "dodge":55,
    "parry":65,
    "damage":255,
    "force":110,
    "damage_type":"·ï¶Ë"
    ]),

});


void sp4(object me,object victim,object weapon,int damage)
{
   int i = me->query("unarmed")*10 + me->query_skill("seven-unarmed");
   if (me->query_skill_mapped("force") == "seven-unarmed" && random(400) < 10 )
   {       message_vision(HIW"$N¹B°_¤õ®üµI¤Ñ¡A§â$nªº¯u®ð¾É¤J$Nªº®ð®ü¤¤¡C\n"NOR,me,victim);
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
                        case 0: return "§AÅ¥¨ì¡u³Ø°Õ¡v¤@Án»´ÅT¡M³º¦ü¬O°©¸HªºÁn­µ¡T\n";
                        case 1: return "$N«l¤O¤@¦R¡M$nªº$lµo¥X¡u³Ø¡v¦a¤@ÁnÃzÅT¡T\n";
                        case 2: return "¥uÅ¥¨£$nªº$l¡u³Ø¡v¦a¤@Án ...\n";
                }
        }
}

